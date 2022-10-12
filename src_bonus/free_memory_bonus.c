/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 10:35:29 by etomiyos          #+#    #+#             */
/*   Updated: 2022/10/12 13:22:28 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_memory(t_pipex *p)
{
	int	i;

	free(p->cmd_list);
	free(p->argv);
	if (p->bar != NULL)
		free(p->bar);
	free_int_array_memory(p->array_fd, p->pipe_number);
	i = 0;
	while (i < p->cmd_number)
	{
		free_char_array_memory(p->splitted_cmd[i]);
		i++;
	}
	free(p->splitted_cmd);
	free(p->pid_fd);
	free(p->array_fd);
	free_char_array_memory(p->envp_path_list);
}

void	free_char_array_memory(char **my_array)
{
	int	i;

	i = 0;
	if (my_array == NULL || *my_array == NULL)
		return ;
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
