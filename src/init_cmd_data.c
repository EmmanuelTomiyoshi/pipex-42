/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cmd_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 10:20:38 by etomiyos          #+#    #+#             */
/*   Updated: 2022/10/12 14:02:13 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	init_argv_data(t_pipex *p, char *argv[])
{
	int	i;

	i = 0;
	p->argv = ft_calloc(sizeof(char *), p->argc + 1);
	while (i < p->argc)
	{
		p->argv[i] = argv[i];
		i++;
	}
}

void	get_cmd_list(t_pipex *p, char *argv[])
{
	int	i;
	int	j;

	i = 2;
	j = 0;
	p->cmd_list = ft_calloc(sizeof(char *), p->cmd_number);
	while (i <= p->cmd_number + 1)
	{
		p->cmd_list[j] = argv[i];
		i++;
		j++;
	}
}
