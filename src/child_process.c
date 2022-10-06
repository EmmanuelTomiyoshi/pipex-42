/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 10:33:40 by etomiyos          #+#    #+#             */
/*   Updated: 2022/10/06 09:34:27 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"


int	child_process_check(t_pipex *pipex, char *envp[], int i)
{
	int	j;

	j = check_path(pipex, i);
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
	else if (i != (pipex->cmd_number - 1))
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
	if (j < 0)
		pipex->path_element = '\0';
	else
		pipex->path_element = ft_strjoin(pipex->path_vec[j], pipex->bar);
	child_process_execution(pipex, envp, i);
	ft_printf("Algo deu errado\n");
	return (0);
}

void	child_process_execution(t_pipex *pipex, char *envp[], int count)
{
	if (pipex->path_element == NULL)
	{
		free_memory(pipex);
		exit(CMD_NOT_FOUND);
	}
	dprintf(pipex->fd_debug, "%d) pipex->path_element: %s\n", count, pipex->path_element);
	dprintf(pipex->fd_debug, "%d) args: %s\n", count, pipex->splitted_cmd[count][0]);
	dprintf(pipex->fd_debug, "%d) args: %s\n", count, pipex->splitted_cmd[count][1]);
	if (execve(pipex->path_element, pipex->splitted_cmd[count], envp) == -1)
	{
		free_memory(pipex);
		exit(errno);
	}
	free_memory(pipex);
}

