/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 10:35:29 by etomiyos          #+#    #+#             */
/*   Updated: 2022/10/07 21:23:30 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_memory(t_pipex *pipex)
{
	int	i;

	free(pipex->cmd_list);
	free(pipex->argv);
	free_int_array_memory(pipex->array_fd, pipex->pipe_number);
	i = 0;
	while (i < pipex->cmd_number)
	{
		free_char_array_memory(pipex->splitted_cmd[i]);
		i++;
	}
	free(pipex->splitted_cmd);
	free(pipex->pid_fd);
	free(pipex->array_fd);
	free_char_array_memory(pipex->envp_path_list);
}

void	free_char_array_memory(char **my_array)
{
	int	i;

	i = 0;
	while (my_array[i] != NULL)
	{
		free(my_array[i]);
		i++;
	}
	free(my_array);
}

void	free_int_array_memory(int **my_array, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(my_array[i]);
		i++;
	}
}
