/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 09:12:48 by etomiyos          #+#    #+#             */
/*   Updated: 2022/09/29 09:28:36 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	init_data(t_pipex *pipex, int argc, char *argv[])
{
	printf(GREEN "\nINIT DATA\n");
	printf(RESET "");
	printf("total number of arguments: %d\n", argc);
	pipex->how_many_cmds = (argc - 3);
	printf("cmd count: %d\n", pipex->how_many_cmds);
	pipex->number_of_pipes = pipex->how_many_cmds - 1;
	printf("number of pipes: %d\n", pipex->number_of_pipes);
	
	//file1 and file2 fds
	pipex->infd = open(argv[1], O_WRONLY); //opening fd file1
	pipex->outfd = open(argv[argc - 1], O_CREAT | O_RDWR | O_TRUNC, S_IRWXU); //fd file2

	//allocating memory for array_fd
	pipex->array_fd = ft_calloc(sizeof(int *), pipex->number_of_pipes);
}


void    fd_memory_allocate(t_pipex *pipex)
{
    int i;

    i = 0;
    while (i < pipex->number_of_pipes)
    {
        pipex->array_fd[i] = ft_calloc(sizeof(int), 2);
        printf("%d) array_fd[%ls]\n", i, pipex->array_fd[i]);
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
			printf("%d): array_fd[%d][%d]\n", i, i, k);
			k++;
		}
		i++;
	}
}