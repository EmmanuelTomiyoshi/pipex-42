/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forking.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 11:35:38 by etomiyos          #+#    #+#             */
/*   Updated: 2022/10/15 22:16:12 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	forking(t_pipex *p, char *envp[])
{
	int	i;

	i = 0;
	init_fd_data(p, p->argv);
	fd_memory_allocate(p);
	init_pipe_values(p);
	while (i < p->cmd_number)
	{
		split_cmd(p, i);
		p->pid_fd[i] = fork();
		fork_check(p, i, envp);
		i++;
	}
}

void	fork_check(t_pipex *p, int i, char *envp[])
{
	if (p->pid_fd[i] < 0)
		exit(1);
	if (p->pid_fd[i] == 0)
	{
		if (p->infd == -1 && i == 0)
		{
			free_memory(p);
			exit(1);
		}
		child_process_check(p, envp, i);
	}
}
