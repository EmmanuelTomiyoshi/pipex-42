/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 10:33:40 by etomiyos          #+#    #+#             */
/*   Updated: 2022/10/13 20:00:20 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_dup_redirection(t_pipex *p, int i)
{
	if (i == 0)
	{
		dup2(p->infd, STDIN_FILENO);
		dup2(p->array_fd[i][1], STDOUT_FILENO);
	}
	else
	{
		dup2(p->array_fd[i - 1][0], STDIN_FILENO);
		dup2(p->outfd, STDOUT_FILENO);
	}
}

void	child_process_check(t_pipex *p, char *envp[], int i)
{
	int	j;

	j = check_path(p, i);
	if (j == CMD_NOT_FOUND)
	{
		free_memory(p);
		exit(CMD_NOT_FOUND);
	}
	child_dup_redirection(p, i);
	close_pipes(p);
	if (j < 0)
		p->path_element = NULL;
	else
		p->path_element = ft_strjoin(p->envp_path_list[j], p->bar);
	child_process_execution(p, envp, i);
}

void	child_process_execution(t_pipex *p, char *envp[], int count)
{
	if (p->path_element == NULL)
	{
		free_memory(p);
		exit(CMD_NOT_FOUND);
	}
	if (execve(p->path_element, p->splitted_cmd[count], envp) == -1)
	{
		free_memory(p);
		exit(errno);
	}
	free_memory(p);
}
