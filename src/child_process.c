/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 10:33:40 by etomiyos          #+#    #+#             */
/*   Updated: 2022/10/04 15:08:59 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"


int	child_process_check(t_pipex *pipex, char *envp[], int i)
{
	int	j;

	split_pathname(pipex, envp, i);
	j = append_path(pipex);
	// if (j == CMD_NOT_FOUND)
	// {
	// 	// invalid_args_msg();
	// 	printf ("%d) deu ruim\n", j);
	// 	return (CMD_NOT_FOUND);
	// }
	if (i == 0)
	{
		dup2(pipex->infd, STDIN_FILENO);
		dup2(pipex->array_fd[i][1], STDOUT_FILENO);
	}
	else if (i != (pipex->how_many_cmds - 1))
	{
		dup2(pipex->array_fd[i - 1][0], STDIN_FILENO);
		dup2(pipex->array_fd[i][1], STDOUT_FILENO);
	}
	else
	{
		dup2(pipex->array_fd[i - 1][0], STDIN_FILENO);
		dup2(pipex->outfd, STDOUT_FILENO);
	}
	close_pipes(pipex);
	pipex->path_element = ft_strjoin(pipex->path_vec[j], pipex->bar);
	child_process_execution(pipex, envp);
	ft_printf("Algo deu errado\n");
	return (0);
}

void	child_process_execution(t_pipex *pipex, char *envp[])
{
	if (execve(pipex->path_element, pipex->splitted_cmd, envp) == -1)
	{	
		perror("execve error: ");
		exit(CMD_NOT_FOUND);
	}
}
