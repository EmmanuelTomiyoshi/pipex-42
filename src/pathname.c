/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathname.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 16:10:59 by etomiyos          #+#    #+#             */
/*   Updated: 2022/09/29 09:28:41 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int get_cmd_list(t_pipex *pipex, int argc, char **argv)
{
    int	i;
    int	j;
	
	i = 2;
	j = 0;
	pipex->lista = calloc(sizeof(char **), pipex->how_many_cmds);
	printf(GREEN "\nGET_CMD_LIST\n");
	printf(RESET "");
	while (i <= pipex->how_many_cmds + 1)
	{
		pipex->lista[j] = argv[i];
		printf("lista[%d]:%s | argv[%d]:%s\n", j, pipex->lista[j], i, argv[i]);
		i++;
		j++;
	}
	return (0);
}

void split_pathname(t_pipex *pipex, char *argv[], char *envp[])
{
	int i;
	int j;//
	int cmd_size;

	i = 0;
	j = 0;//
	cmd_size = split_count_solo(argv[2], ' '); //while
	pipex->splitted_cmd = ft_split(pipex->lista[0], ' ');

	printf(GREEN "\nSPLITH PATH NAME\n");
	printf(RESET "");
	printf("size of the very first individual cmd: %d\n", cmd_size);
	

	printf(GREEN "\nSPLITTED CMD\n");
	printf(RESET "");
	while (j < cmd_size)
	{
		printf("%d) %s\n", j, pipex->splitted_cmd[j]);
		j++;
	}

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

int	check_path(t_pipex *pipex)
{
	int i;

	i = 0;
	pipex->bar = ft_strjoin("/", pipex->splitted_cmd[0]); //while
	printf("pipex->bar: %s\npipex->splitted_cmd[0]: %s\n", pipex->bar, pipex->splitted_cmd[0]);
	
	printf(GREEN "\nTHE RIGHT PATH\n");
	printf(RESET "");
	while (pipex->pathVec[i] != NULL)
	{
		pipex->var = ft_strjoin(pipex->pathVec[i], pipex->bar); // /usr/bin/ls 
		
		if (access(pipex->var, F_OK | X_OK) == 0) //
		{
			printf("path: %s\n", pipex->var);
			//printf("entrou\n");
			return (i);
		}
		//else { do check with array elements length later }
		i++;
	}
	return (0);
}
