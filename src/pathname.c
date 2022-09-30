/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathname.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 16:10:59 by etomiyos          #+#    #+#             */
/*   Updated: 2022/09/30 11:33:26 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int get_cmd_list(t_pipex *pipex, int argc, char **argv)
{
    int	i;
    int	j;
	
	i = 2;
	j = 0;
	pipex->cmd_list = calloc(sizeof(char **), pipex->how_many_cmds);
	printf(GREEN "\nGET_CMD_LIST\n");
	printf(RESET "");
	while (i <= pipex->how_many_cmds + 1)
	{
		pipex->cmd_list[j] = argv[i];
		printf("cmd_list[%d]:%s | argv[%d]:%s\n", j, pipex->cmd_list[j], i, argv[i]);
		i++;
		j++;
	}
	return (0);
}

void	split_pathname(t_pipex *pipex, char *argv[], char *envp[], int count)
{
	int i;
	int j;//
	int cmd_size;

	i = 0;
	j = 0;//
	cmd_size = split_count_solo(argv[count + pipex->cmd_start], ' '); //while

	pipex->splitted_cmd = ft_split(pipex->cmd_list[count], ' '); //while

	printf(GREEN "\nSPLITH PATH NAME\n");
	printf(RESET "");
	printf("size of the (%d) cmd element: %d\n", count + 1, cmd_size);

	printf(GREEN "\nSPLITTED CMD\n");
	printf(RESET "");
	
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

int	check_path(t_pipex *pipex, int count)
{
	int i;

	i = 0;
	printf(BLUE "COUNT:%d\n", count);
	printf(RESET "");
	pipex->bar = ft_strjoin("/", pipex->splitted_cmd[0]); //while
	printf("pipex->bar: %s\npipex->splitted_cmd[0]: %s\n", pipex->bar, pipex->splitted_cmd[0]);
	
	printf(GREEN "\nTHE RIGHT PATH\n");
	printf(RESET "");

	while (pipex->pathVec[i] != NULL)
	{
		pipex->var = ft_strjoin(pipex->pathVec[i], pipex->bar); // /usr/bin/ls 
		
		if (access(pipex->var, F_OK | X_OK) == 0)
		{
			printf("path: %s\n", pipex->var);
			return (i);
		}
		i++;
	}
	return (0);
}
