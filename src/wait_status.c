/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_status.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 11:38:50 by etomiyos          #+#    #+#             */
/*   Updated: 2022/10/12 13:58:15 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	wait_status(t_pipex *p)
{
	int	i;

	i = 0;
	while (i < p->cmd_number)
	{
		waitpid(p->pid_fd[i], &p->status, 0);
		if (WIFEXITED(p->status))
			p->status = WEXITSTATUS(p->status);
		if (p->status != 0)
			handle_error_status(p->status, p->splitted_cmd[i][0]);
		i++;
	}
}
