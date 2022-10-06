/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printftesting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 14:06:54 by etomiyos          #+#    #+#             */
/*   Updated: 2022/10/06 14:34:05 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void    printftesting(t_pipex *pipex, int i)
{
    int j;
    int	k;
    if (i == 1)
    {
        dprintf(pipex->fd_debug, "\n#INIT STATIC DATA\n");
        dprintf(pipex->fd_debug, "argc: %d\n", pipex->argc);
        dprintf(pipex->fd_debug, "cmd_number: %d\n", pipex->cmd_number);
        dprintf(pipex->fd_debug, "cmd_start: %d\n", pipex->cmd_start);
        dprintf(pipex->fd_debug, "pipe_number: %d\n", pipex->pipe_number);
    }
    if (i == 2)
    {
        dprintf(pipex->fd_debug, "\n#ARGV DATA\n");
        j = 0;
        while (j < pipex->argc)
	    {
            dprintf(pipex->fd_debug, "%d) argv[%d] = %s\n",
            j, j, pipex->argv[j]);
            j++;
	    }
        dprintf(pipex->fd_debug, "\n#CMD LIST\n");
        j = 2;
        k = 0;
        while (j <= pipex->cmd_number + 1)
        {
            dprintf(pipex->fd_debug, "cmd[%d] = ""\"""%s""\""" \n",
            k, pipex->cmd_list[k]); 
            j++;
            k++;
        }
    }
    if (i == 3)
    {
        dprintf(pipex->fd_debug, "\n#FILE DESCRIPTORS\n");
        dprintf(pipex->fd_debug, "infd(%d) | outfd(%d)\n",
        pipex->infd, pipex->outfd);

        j = 0;
        while (j < pipex->pipe_number)
        {
            k = 0;
            while (k <= 1)
            {
                dprintf(pipex->fd_debug, "%d) pipe_fd[%d][%d]\n",
                j, j, k);
                k++;
            }
            j++;
        }
    }
}