/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 12:24:58 by etomiyos          #+#    #+#             */
/*   Updated: 2022/10/15 22:23:40 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H

# define PIPEX_H

//build-in libraries
# include <errno.h>
# include <fcntl.h> 
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <time.h>
# include <sys/wait.h>

//custom libraries
# include "libft.h"
# include "ft_printf.h"
# include "printfcolors.h"
# include "exitcodes.h"

//macros
# define SINGLE_QUOTE 39
# define TEMP_VALUE -1
# define SPACE 32

typedef struct s_pipex
{
	int			argc;
	char		**argv;
	char		**envp;
	int			path_index;
	int			cmd_number;
	int			cmd_start;
	int			pipe_number;

	int			infd;
	int			outfd;
	int			**array_fd;
	int			*pid_fd;

	char		**cmd_list;
	char		***splitted_cmd;
	char		**envp_path_list;
	char		*path_element;
	char		*bar;
	char		*path;

	int			status;
}				t_pipex;

//initiating data
void	init_data(t_pipex *p, int argc, char *argv[], char *envp[]);
void	init_static_data(t_pipex *p, int argc);
void	init_dynamic_data(t_pipex *p, char *argv[], char *envp[]);
void	init_argv_data(t_pipex *p, char *argv[]);
void	init_fd_data(t_pipex *p, char *argv[]);
void	outfile_fd(t_pipex *p, char *argv[]);
void	infile_fd(t_pipex *p, char *argv[]);
void	fd_memory_allocate(t_pipex *p);
void	init_pipe_values(t_pipex *p);

//handling cmd and envp 
void	get_cmd_list(t_pipex *p, char *argv[]);
void	split_pathname(t_pipex *p, char *envp[]);
void	split_cmd(t_pipex *p, int ind);
void	handle_quoting(char **str, int original_value, int replaced_value);

//fork execution
void	forking(t_pipex *p, char *envp[]);
void	fork_check(t_pipex *p, int i, char *envp[]);
void	child_process_execution(t_pipex *p, char *envp[], int count);
void	child_dup_redirection(t_pipex *p, int i);
void	child_process_check(t_pipex *p, char *envp[], int i);
int		check_path(t_pipex *p, int count);

//close | free | wait
void	close_pipes(t_pipex *p);
void	free_memory(t_pipex *p);
void	free_int_array_memory(int **my_array, int count);
void	free_char_array_memory(char **my_array);
void	wait_status(t_pipex *p);

//handling errors
void	handle_error_status(int status, char *desc);
void	handle_error(t_pipex *p);

#endif