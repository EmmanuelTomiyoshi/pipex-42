/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathname.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 16:10:59 by etomiyos          #+#    #+#             */
/*   Updated: 2022/09/24 15:14:47 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	check_path(t_pipex *pipex)
{
	int i;

	i = 0;
	//ele sempre tá pegando o cmd[0], por isso tá dando errado
	pipex->bar = ft_strjoin("/", pipex->cmd[0]);
	while (pipex->pathVec[i] != NULL)
	{
		pipex->var = ft_strjoin(pipex->pathVec[i], pipex->bar); // /usr/bin/ls
		
		if (access(pipex->var, F_OK) == 0)
		{
			//printf("entrou\n");
			return (i);
		}
		//else { do check with array elements length later }
		i++;
	}
	printf(RESET"");
	return (0);
}

void split_pathname(t_pipex *pipex, char *argv[], char *envp[])
{
	int i;

	i = 0;
	pipex->cmd = ft_split(argv[2], ' ');
	while (envp[i] != NULL)
	{
		if (!ft_strncmp(envp[i], "PATH=", 5))
		{
			pipex->path = envp[i];
			pipex->pathVec = ft_split(pipex->path, ':');
		}
		i++;
	}	
}