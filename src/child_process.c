/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 10:33:40 by etomiyos          #+#    #+#             */
/*   Updated: 2022/10/01 10:50:07 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void    child_process_execution(t_pipex *pipex, char *argv[], char *envp[], int i)
{
    int j;

    split_pathname(pipex, argv, envp, i);
    j = check_path(pipex, i);
    if (i == 0)
    {
        dup2(pipex->infd, STDIN_FILENO); //entrada
        dup2(pipex->array_fd[i][1], STDOUT_FILENO); //saída
    }
    else if (i != (pipex->how_many_cmds - 1))
    {
        dup2(pipex->array_fd[i - 1][0], STDIN_FILENO); //entrada
        dup2(pipex->array_fd[i][1], STDOUT_FILENO); //saída
    }
    else
    {
        dup2(pipex->array_fd[i - 1][0], STDIN_FILENO); //entrada
        dup2(pipex->outfd, STDOUT_FILENO); //saída
    }
    close_pipes(pipex);
    pipex->path_element = ft_strjoin(pipex->pathVec[j], pipex->bar);
    if (execve(pipex->path_element, pipex->splitted_cmd, envp) == -1)
    {	
        perror("execve error: ");
        exit(COMMAND_NOT_FOUND);
    }
    ft_printf("Algo deu errado\n");
}