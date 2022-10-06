/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 14:17:48 by etomiyos          #+#    #+#             */
/*   Updated: 2022/10/06 09:34:40 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	error_not_enough_cmds(t_pipex *pipex)
{
	if (pipex->number_of_pipes == 0)
	{
		printf("Error! Command count is\n");
		return (1);
	}
	return (0);
}

int	error_not_enough_args(t_pipex *pipex)
{
	if (pipex->cmd_number < 2)
	{
		invalid_args_msg();
		return (1);
	}
	return (0);
}

void	free_memory(t_pipex *pipex)
{
	int i;
	
	free(pipex->cmd_list);	
	i = 0;
	while (i < pipex->cmd_number)
	{
		free_char_array_memory(pipex->splitted_cmd[i]);
		i++;
	}
	free(pipex->splitted_cmd);
	free_char_array_memory(pipex->path_vec);
	free_int_array_memory(pipex->array_fd, pipex->number_of_pipes);
	free(pipex->pid_fd);
	free(pipex->array_fd);
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

void	invalid_args_msg()
{
	ft_printf(INVALID_ARGS PIPEX_EXAMPLE_1 EXPECTED_EXAMPLE_1
		PIPEX_EXAMPLE_2 EXPECTED_EXAMPLE_2);
}