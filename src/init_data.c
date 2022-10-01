/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 09:12:48 by etomiyos          #+#    #+#             */
/*   Updated: 2022/10/01 19:09:21 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

//if here_doc, pipex->cmd_start = 3
void	init_data(t_pipex *pipex, int argc, char *argv[])
{
	pipex->how_many_cmds = (argc - 3);
	pipex->number_of_pipes = pipex->how_many_cmds - 1;
	pipex->cmd_start = 2;
	pipex->array_fd = ft_calloc(sizeof(int *), pipex->number_of_pipes);
	pipex->splitted_cmd = ft_calloc(sizeof(int *), pipex->how_many_cmds + 1);
	pipex->infd = open(argv[1], O_WRONLY);
	pipex->outfd = open(argv[argc - 1], O_CREAT | O_RDWR | O_TRUNC, S_IRWXU);
}

void	fd_memory_allocate(t_pipex *pipex)
{
	int	i;

	i = 0;
	while (i < pipex->number_of_pipes)
	{
		pipex->array_fd[i] = ft_calloc(sizeof(int), 2);
		i++;
	}
}

void	pipe_values(t_pipex *pipex)
{
	int	i;
	int	k;
	int	value;

	i = 0;
	k = 1;
	value = -5;
	while (i < pipex->number_of_pipes)
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

void	close_pipes(t_pipex *pipex)
{
	int	i;

	i = 0;
	while (i < pipex->number_of_pipes)
	{
		close(pipex->array_fd[i][0]);
		close(pipex->array_fd[i][1]);
		i++;
	}
	close(pipex->infd);
	close(pipex->outfd);
}
