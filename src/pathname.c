/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathname.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 16:10:59 by etomiyos          #+#    #+#             */
/*   Updated: 2022/10/06 09:35:09 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	get_cmd_list(t_pipex *pipex, char **argv)
{
	int	i;
	int	j;

	i = 2;
	j = 0;
	pipex->cmd_list = calloc(sizeof(char **), pipex->cmd_number);

	while (i <= pipex->cmd_number + 1)
	{
		pipex->cmd_list[j] = argv[i];
		i++;
		j++;
	}
	return (0);
}

void	split_pathname(t_pipex *pipex, char *envp[])
{
	int		i;

	i = 0;
	pipex->path_element = NULL;
	while (envp[i] != NULL)
	{
		if (!ft_strncmp(envp[i], "PATH=", 5))
		{
			pipex->path_vec = ft_split(envp[i], ':');
		}
		i++;
	}
}


int	check_path(t_pipex *pipex, int count)
{
	int	i;
	
	i = 0;
	pipex->bar = ft_strjoin("/", pipex->splitted_cmd[count][0]);
	while (pipex->path_vec[i] != NULL)
	{
		pipex->path = ft_strjoin(pipex->path_vec[i], pipex->bar);
		if (access(pipex->path, F_OK | X_OK) == 0)
		{
			return (i);
		}
		i++;
	}
	return (-1);
}

// void	status_fd(t_pipex *pipex)
// {
// 	int i;

// 	i = 0;
// 	while (i < pipex->cmd_number)
// 	{
		
// 	}
// 	//pipex->splitted_cmd[i][0]
// }

void	error_pipex(int status, char *desc)
{
	if (status == 127)
	{
		write(2, desc, ft_strlen(desc));
		write(2, ": ", 2);
		write(2, MSG_CMD_NOT_FOUND, ft_strlen(MSG_CMD_NOT_FOUND));
	}
	else
		strerror(status);
}