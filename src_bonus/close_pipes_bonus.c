/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_pipes_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 10:15:03 by etomiyos          #+#    #+#             */
/*   Updated: 2022/10/14 18:47:30 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	close_pipes(t_pipex *p)
{
	int	i;

	i = 0;
	while (i < p->pipe_number)
	{
		close(p->array_fd[i][0]);
		close(p->array_fd[i][1]);
		i++;
	}
	if (p->infd != -1)
		close(p->infd);
	close(p->outfd);
}
