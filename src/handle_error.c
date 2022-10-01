/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 14:17:48 by etomiyos          #+#    #+#             */
/*   Updated: 2022/09/30 14:53:03 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int    error_not_enough_cmds(t_pipex *pipex)
{
    if (pipex->number_of_pipes == 0)
		return (printf("Error! Command number is\n"));
}

int    error_not_enough_args(t_pipex *pipex, int argc)
{  
	if (argc <= 1)
	{
		printf("Argumentos insuficientes\n");
		return (1);
	}
}