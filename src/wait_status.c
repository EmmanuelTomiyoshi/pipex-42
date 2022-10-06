/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_status.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 11:38:50 by etomiyos          #+#    #+#             */
/*   Updated: 2022/10/06 19:24:58 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	wait_status(t_pipex *pipex)
{
	int	i;

	i = 0;
	ft_printf("status:%d\n", WEXITSTATUS(pipex->status));
	while (i < pipex->cmd_number)
	{
		waitpid(pipex->pid_fd[i], &pipex->status, 0);
		if (WIFEXITED(pipex->status))
			pipex->status = WEXITSTATUS(pipex->status);
		if (pipex->status != 0)
			error_pipex(pipex->status, pipex->splitted_cmd[i][0]);
		i++;
	}
}
