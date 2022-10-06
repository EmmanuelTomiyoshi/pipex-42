/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cmd_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 10:20:38 by etomiyos          #+#    #+#             */
/*   Updated: 2022/10/06 18:57:26 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	init_argv_data(t_pipex *pipex, char *argv[])
{
	int	i;

	i = 0;
	pipex->argv = ft_calloc(sizeof(char *), pipex->argc + 1);
	while (i < pipex->argc)
	{
		pipex->argv[i] = argv[i];
		i++;
	}
}

void	get_cmd_list(t_pipex *pipex, char *argv[])
{
	int	i;
	int	j;

	i = 2;
	j = 0;
	pipex->cmd_list = ft_calloc(sizeof(char *), pipex->cmd_number);
	while (i <= pipex->cmd_number + 1)
	{
		pipex->cmd_list[j] = argv[i];
		i++;
		j++;
	}
}
