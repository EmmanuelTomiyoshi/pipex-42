/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 12:24:58 by etomiyos          #+#    #+#             */
/*   Updated: 2022/10/07 22:02:17 by etomiyos         ###   ########.fr       */
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
	int			argc;
	char		**argv;
	char		**envp;
	int			cmd_number;
	int			cmd_start;
	int			pipe_number;

	int			infd;
	int			outfd;
	int			**array_fd;
	char		***splitted_cmd;
	int			*pid_fd;
	char		**cmd_list;

	char		**envp_path_list;
	char		*path_element;
	char		*bar;
	char		*path;

	int			status;
}				t_pipex;

//init data
void	init_data(t_pipex *pipex, int argc, char *argv[], char *envp[]);
void	init_static_data(t_pipex *pipex, int argc, char *envp[]);
void	init_dynamic_data(t_pipex *pipex, char *argv[], char *envp[]);
void	init_argv_data(t_pipex *pipex, char *argv[]);
void	get_cmd_list(t_pipex *pipex, char *argv[]);
void	init_fd_data(t_pipex *p, char *argv[]);
void	fd_memory_allocate(t_pipex *pipex);
void	init_pipe_values(t_pipex *pipex);
void	split_pathname(t_pipex *pipex, char *envp[]);

//handle_error
void	error_pipex(int status, char *desc);
void	handle_error(t_pipex *pipex);
int		error_not_enough_args(t_pipex *pipex);
int		error_not_enough_cmds(t_pipex *pipex);
void	error_pipex(int status, char *desc);

//fork child
void	forking(t_pipex *pipex, char *envp[]);
void	child_process_execution(t_pipex *pipex, char *envp[], int count);
void	dup_redirection(t_pipex *pipex, int i);
int		child_process_check(t_pipex *pipex, char *envp[], int i);
int		check_path(t_pipex *pipex, int count);

//close, free and wait
void	close_pipes(t_pipex *pipex);
void	free_memory(t_pipex *pipex);
void	free_int_array_memory(int **my_array, int count);
void	free_char_array_memory(char **my_array);
void	wait_status(t_pipex *pipex);

#endif