/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathname.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 16:10:59 by etomiyos          #+#    #+#             */
/*   Updated: 2022/10/07 21:25:17 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	split_pathname(t_pipex *pipex, char *envp[])
{
	int	i;

	i = 0;
	pipex->path_element = NULL;
	while (envp[i] != NULL)
	{
		if (!ft_strncmp(envp[i], "PATH=", 5))
		{
			pipex->envp_path_list = ft_split(envp[i], ':');
		}
		i++;
	}
}

int	check_path(t_pipex *pipex, int count)
{
	int	i;

	i = 0;
	pipex->bar = ft_strjoin("/", pipex->splitted_cmd[count][0]);
	while (pipex->envp_path_list[i] != NULL)
	{
		pipex->path = ft_strjoin(pipex->envp_path_list[i], pipex->bar);
		if (access(pipex->path, F_OK | X_OK) == 0)
		{
			return (i);
		}
		i++;
	}
	return (CMD_NOT_FOUND);
}
