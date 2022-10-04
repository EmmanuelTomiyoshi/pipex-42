 /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 12:24:58 by etomiyos          #+#    #+#             */
/*   Updated: 2022/10/03 08:54:11 by etomiyos         ###   ########.fr       */
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
# include "libft.h"
# include "ft_printf.h"
# include "printfcolors.h"
# include "exitcodes.h"

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
	// int			the_status;
}				t_pipex;

void	init_data(t_pipex *pipex, int argc, char *argv[]);
void	pipe_values(t_pipex *pipex);
void	fd_memory_allocate(t_pipex *pipex);
int		get_cmd_list(t_pipex *pipex, char **argv);
int		path_operations(t_pipex *pipex, char *envp[], int i);
int		append_path(t_pipex *pipex);
int		check_my_path(t_pipex *pipex);
void	split_pathname(t_pipex *pipex, char *envp[], int count);
void	child_process_execution(t_pipex *pipex, char *envp[]);
int		child_process_check(t_pipex *pipex, char *envp[], int i);
int		error_not_enough_cmds(t_pipex *pipex);
int		error_not_enough_args(t_pipex *pipex);
void	close_pipes(t_pipex *pipex);
void	free_memory(t_pipex *pipex);
void	free_int_array_memory(int **my_array, int count);
void	invalid_args_msg();
void	check_status(t_pipex *pipex, int status);
void	check_error(t_pipex *pipex);

#endif