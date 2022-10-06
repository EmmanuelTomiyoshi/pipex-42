/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 09:12:48 by etomiyos          #+#    #+#             */
/*   Updated: 2022/10/06 11:29:02 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	init_data(t_pipex *pipex, int argc, char *argv[], char *envp[])
{
	init_static_data(pipex, argc, envp);
	init_dynamic_data(pipex, argv);
	init_fd_data(pipex);
	init_pipe_values(pipex);
}

void	init_static_data(t_pipex *pipex, int argc, char *envp[])
{
	pipex->argc = argc;
	pipex->cmd_number = (argc - 3);
	pipex->cmd_start = 2;
	pipex->pipe_number = pipex->cmd_number - 1;
	split_pathname(pipex, envp);
}

void	init_dynamic_data(t_pipex *pipex, char *argv[])
{
	pipex->array_fd = ft_calloc(sizeof(int *), pipex->pipe_number);
	pipex->splitted_cmd = ft_calloc(sizeof(char **), pipex->cmd_number + 1);
	pipex->pid_fd = ft_calloc(sizeof(int), pipex->cmd_number);
	init_argv_data(pipex, argv);
	get_cmd_list(pipex, argv);
}