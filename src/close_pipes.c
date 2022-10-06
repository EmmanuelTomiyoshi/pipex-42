/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_pipes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 10:15:03 by etomiyos          #+#    #+#             */
/*   Updated: 2022/10/06 10:24:02 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	close_pipes(t_pipex *pipex)
{
	int	i;

	i = 0;
	while (i < pipex->pipe_number)
	{
		close(pipex->array_fd[i][0]);
		close(pipex->array_fd[i][1]);
		i++;
	}
	close(pipex->infd);
	close(pipex->outfd);
}
