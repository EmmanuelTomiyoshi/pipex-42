/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 12:24:58 by etomiyos          #+#    #+#             */
/*   Updated: 2022/09/24 12:23:27 by etomiyos         ###   ########.fr       */
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
	char		**cmd;
	char 		*path;
	char		*var;
	char		*bar;
	char		**pathVec;
}				t_pipex;

int		check_path(t_pipex *pipex);
void	split_pathname(t_pipex *pipex, char *argv[], char *envp[]);

#endif