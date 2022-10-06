/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pipe_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 10:42:41 by etomiyos          #+#    #+#             */
/*   Updated: 2022/10/06 19:24:38 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	init_fd_data(t_pipex *p)
{
	p->infd = open(p->argv[1], O_RDONLY);
	if (p->infd < 0)
	{
		if (!access(p->argv[1], F_OK))
			exit(0);
		exit(1);
	}
	p->outfd = open(p->argv[p->argc - 1], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (p->outfd < 0)
		exit(1);
	fd_memory_allocate(p);
}

void	fd_memory_allocate(t_pipex *pipex)
{
	int	i;

	i = 0;
	while (i < pipex->pipe_number)
	{
		pipex->array_fd[i] = ft_calloc(sizeof(int), 2);
		i++;
	}
}

void	init_pipe_values(t_pipex *pipex)
{
	int	i;
	int	k;
	int	value;

	i = 0;
	k = 1;
	value = -5;
	while (i < pipex->pipe_number)
	{
		value = pipe(pipex->array_fd[i]);
		if (value == -1)
			perror("pipe:");
		k = 0;
		while (k <= 1)
		{
			k++;
		}
		i++;
	}
}
