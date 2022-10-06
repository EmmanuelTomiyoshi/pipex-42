/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 14:17:48 by etomiyos          #+#    #+#             */
/*   Updated: 2022/10/06 11:50:10 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	handle_error(t_pipex *pipex)
{
	if (error_not_enough_args(pipex) == 1)
		exit(1);
	if (error_not_enough_cmds(pipex) == 1)
		exit(1);
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

int	error_not_enough_cmds(t_pipex *pipex)
{
	if (pipex->pipe_number == 0)
	{
		printf("Error! Command count is\n");
		return (1);
	}
	return (0);
}

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

void	invalid_args_msg(void)
{
	ft_printf(INVALID_ARGS PIPEX_EXAMPLE_1 EXPECTED_EXAMPLE_1
		PIPEX_EXAMPLE_2 EXPECTED_EXAMPLE_2);
}
