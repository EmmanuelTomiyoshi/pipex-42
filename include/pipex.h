/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 12:24:58 by etomiyos          #+#    #+#             */
/*   Updated: 2022/09/29 09:19:03 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H

# define PIPEX_H
//open
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h> 

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <time.h>
# include <sys/wait.h>
# include <errno.h>
# include "libft.h"
# include "printfcolors.h"


typedef struct	s_pipex
{
	int			infd;
	int			outfd;
	int			**array_fd;
	int 		pid1;
	int			pid2;
	char		**splitted_cmd;
	char 		*path;
	char		*var;
	char		*bar;
	char		**pathVec;
	char		**lista;
	int			how_many_cmds;
	int			number_of_pipes;
}				t_pipex;

void	init_data(t_pipex *pipex, int argc, char *argv[]);
void	fd_memory_allocate(t_pipex *pipex);
void    pipe_values(t_pipex *pipex);
int		check_path(t_pipex *pipex);
void	split_pathname(t_pipex *pipex, char *argv[], char *envp[]);
int		get_cmd_list(t_pipex *pipex, int argc, char **argv);

#endif