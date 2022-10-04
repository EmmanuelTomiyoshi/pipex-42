/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 14:17:48 by etomiyos          #+#    #+#             */
/*   Updated: 2022/10/03 15:13:57 by etomiyos         ###   ########.fr       */
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
	if (pipex->how_many_cmds < 2)
	{
		invalid_args_msg();
		return (1);
	}
	return (0);
}

void	free_memory(t_pipex *pipex)
{
	free(pipex->cmd_list);
	free(pipex->splitted_cmd);
	free_int_array_memory(pipex->array_fd, pipex->number_of_pipes);
	free(pipex->array_fd);
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