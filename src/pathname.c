/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathname.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 16:10:59 by etomiyos          #+#    #+#             */
/*   Updated: 2022/10/01 20:09:03 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	get_cmd_list(t_pipex *pipex, char **argv)
{
	int	i;
	int	j;

	i = 2;
	j = 0;
	pipex->cmd_list = calloc(sizeof(char **), pipex->how_many_cmds);
	while (i <= pipex->how_many_cmds + 1)
	{
		pipex->cmd_list[j] = argv[i];
		i++;
		j++;
	}
	return (0);
}

void	split_pathname(t_pipex *pipex, char *envp[], int count)
{
	int	i;

	i = 0;
	pipex->splitted_cmd = ft_split(pipex->cmd_list[count], ' ');
	while (envp[i] != NULL)
	{
		if (!ft_strncmp(envp[i], "PATH=", 5))
		{
			pipex->path_element = envp[i];
			pipex->path_vec = ft_split(pipex->path_element, ':');
		}
		i++;
	}
}

int	check_path(t_pipex *pipex)
{
	int	i;

	i = 0;
	pipex->bar = ft_strjoin("/", pipex->splitted_cmd[0]);
	while (pipex->path_vec[i] != NULL)
	{
		pipex->path = ft_strjoin(pipex->path_vec[i], pipex->bar);
		if (access(pipex->path, F_OK | X_OK) == 0)
		{
			return (i);
		}
		i++;
	}
	return (0);
}
