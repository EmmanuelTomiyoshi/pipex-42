/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forking.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 11:35:38 by etomiyos          #+#    #+#             */
/*   Updated: 2022/10/06 11:37:09 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void    forking(t_pipex *pipex, char *envp[])
{
    int i;

    i = 0;
    while (i < pipex->cmd_number)
	{
		pipex->splitted_cmd[i] = ft_split(pipex->cmd_list[i], ' '); //
		pipex->pid_fd[i] = fork();
		if (pipex->pid_fd[i] < 0)
			exit(1);
		if (pipex->pid_fd[i] == 0)
			pipex->status = child_process_check(pipex, envp, i);
		i++;
	}
}