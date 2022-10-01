/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 09:12:48 by etomiyos          #+#    #+#             */
/*   Updated: 2022/09/30 15:14:06 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	init_data(t_pipex *pipex, int argc)
{
	ft_printf(GREEN "\nINIT DATA\n");
	ft_printf(RESET "");
	ft_printf("total number of arguments: %d\n", argc);
	pipex->how_many_cmds = (argc - 3);
	ft_printf("cmd count: %d\n", pipex->how_many_cmds);
	pipex->number_of_pipes = pipex->how_many_cmds - 1;
	ft_printf("number of pipes: %d\n", pipex->number_of_pipes);
    
    pipex->cmd_start = 2; //if here_doc, start with 3
	
	//file1 and file2 fds

	//allocating memory for array_fd
	pipex->array_fd = ft_calloc(sizeof(int *), pipex->number_of_pipes);
	pipex->splitted_cmd = ft_calloc(sizeof(int *), pipex->how_many_cmds + 1); //
}


void    fd_memory_allocate(t_pipex *pipex)
{
    int i;

    i = 0;
    while (i < pipex->number_of_pipes)
    {
        pipex->array_fd[i] = ft_calloc(sizeof(int), 2);
        ft_printf("%d) array_fd[%ls]\n", i, pipex->array_fd[i]);
        i++;
    }
}

void    pipe_values(t_pipex *pipex)
{
    int i;
    int k;
    int value;

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
			ft_printf("%d): array_fd[%d][%d]\n", i, i, k);
			k++;
		}
		i++;
	}
}

void    close_pipes(t_pipex *pipex)
{
    int i;

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