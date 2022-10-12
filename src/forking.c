/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forking.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 11:35:38 by etomiyos          #+#    #+#             */
/*   Updated: 2022/10/12 11:48:58 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	splitted_cmd(t_pipex *pipex, int ind)
{
	int		i;
	char	*aux;

	handle_quoting(&pipex->cmd_list[ind], SPACE, TEMP_VALUE);
	pipex->splitted_cmd[ind] = ft_split(pipex->cmd_list[ind], TEMP_VALUE);
	i = 0;
	while (pipex->splitted_cmd[ind][i])
	{
		handle_quoting(&pipex->splitted_cmd[ind][i], TEMP_VALUE, SPACE);
		aux = pipex->splitted_cmd[ind][i];
		pipex->splitted_cmd[ind][i] = ft_strtrim(pipex->splitted_cmd[ind][i],
				"'");
		free(aux);
		i++;
	}
}

void	forking(t_pipex *pipex, char *envp[])
{
	int	i;

	i = 0;
	while (i < pipex->cmd_number)
	{
		splitted_cmd(pipex, i);
		pipex->pid_fd[i] = fork();
		if (pipex->pid_fd[i] < 0)
			exit(1);
		if (pipex->pid_fd[i] == 0)
			pipex->status = child_process_check(pipex, envp, i);
		i++;
	}
}
