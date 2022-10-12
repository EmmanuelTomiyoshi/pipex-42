/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forking.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 11:35:38 by etomiyos          #+#    #+#             */
/*   Updated: 2022/10/12 14:00:38 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	forking(t_pipex *p, char *envp[])
{
	int	i;

	i = 0;
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
		child_process_check(p, envp, i);
}
