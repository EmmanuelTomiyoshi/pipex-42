/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cmd_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 10:20:38 by etomiyos          #+#    #+#             */
/*   Updated: 2022/10/12 11:21:28 by etomiyos         ###   ########.fr       */
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

void	handle_quoting(char **str, int original_value, int replaced_value)
{
	size_t	i;
	int		quotes;
	char	*aux_str;

	i = 0;
	aux_str = *str;
	quotes = 0;
	while (aux_str[i])
	{
		if (aux_str[i] == SINGLE_QUOTE)
			quotes = !quotes;
		else if (aux_str[i] == original_value && !quotes)
			aux_str[i] = replaced_value;
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
