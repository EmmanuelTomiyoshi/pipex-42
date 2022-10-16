/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 09:12:48 by etomiyos          #+#    #+#             */
/*   Updated: 2022/10/15 22:21:50 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	init_data(t_pipex *p, int argc, char *argv[], char *envp[])
{
	init_static_data(p, argc);
	init_dynamic_data(p, argv, envp);
}

void	init_static_data(t_pipex *p, int argc)
{
	p->argc = argc;
	p->cmd_number = (argc - 3);
	p->pipe_number = p->cmd_number - 1;
	p->cmd_start = 2;
	p->bar = NULL;
	p->status = 0;
	p->path_index = 0;
	handle_error(p);
}

void	init_dynamic_data(t_pipex *p, char *argv[], char *envp[])
{
	p->array_fd = ft_calloc(sizeof(int *), p->pipe_number);
	p->splitted_cmd = ft_calloc(sizeof(char **), p->cmd_number + 1);
	p->pid_fd = ft_calloc(sizeof(int), p->cmd_number);
	init_argv_data(p, argv);
	get_cmd_list(p, argv);
	split_pathname(p, envp);
}
