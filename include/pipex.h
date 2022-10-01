/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 12:24:58 by etomiyos          #+#    #+#             */
/*   Updated: 2022/10/01 20:30:24 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H

# define PIPEX_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h> 
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <time.h>
# include <sys/wait.h>
# include <errno.h>
# include "libft.h"
# include "ft_printf.h"
# include "printfcolors.h"

# define COMMAND_NOT_FOUND 127

typedef struct s_cmd
{
	int			fd_stdin;
	int			fd_stdout;
	char		**args;
}				t_cmd;
typedef struct s_pipex
{
	int			infd;
	int			outfd;
	int			**array_fd;
	int			pid1;
	char		**path_vec;
	char		**splitted_cmd;
	char		**cmd_list;
	char		*path_element;
	char		*bar;
	char		*path;
	int			how_many_cmds;
	int			cmd_start;
	int			number_of_pipes;
}				t_pipex;

void	init_data(t_pipex *pipex, int argc, char *argv[]);
void	pipe_values(t_pipex *pipex);
void	fd_memory_allocate(t_pipex *pipex);
int		get_cmd_list(t_pipex *pipex, char **argv);
int		path_operations(t_pipex *pipex, char *envp[], int i);
int		check_path(t_pipex *pipex);
void	split_pathname(t_pipex *pipex, char *envp[], int count);
void	child_process_execution(t_pipex *pipex, char *envp[]);
void	child_process_check(t_pipex *pipex, char *envp[], int i);
int		error_not_enough_cmds(t_pipex *pipex);
int		error_not_enough_args(int argc);
void	close_pipes(t_pipex *pipex);
void	free_memory(t_pipex *pipex);
void	free_int_array_memory(int **my_array, int count);

#endif