/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 14:17:48 by etomiyos          #+#    #+#             */
/*   Updated: 2022/10/12 17:27:38 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	handle_error(t_pipex *p)
{
	if (p->argc != 5)
	{
		ft_printf(INVALID_ARGS);
		exit(1);
	}
}

void	handle_error_status(int status, char *desc)
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
