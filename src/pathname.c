/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathname.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 16:10:59 by etomiyos          #+#    #+#             */
/*   Updated: 2022/10/12 14:02:20 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	split_pathname(t_pipex *p, char *envp[])
{
	int	i;

	i = 0;
	p->path_element = NULL;
	while (envp[i] != NULL)
	{
		if (!ft_strncmp(envp[i], "PATH=", 5))
		{
			p->envp_path_list = ft_split(envp[i], ':');
		}
		i++;
	}
}

void	split_cmd(t_pipex *p, int ind)
{
	int		i;
	char	*aux;

	handle_quoting(&p->cmd_list[ind], SPACE, TEMP_VALUE);
	p->splitted_cmd[ind] = ft_split(p->cmd_list[ind], TEMP_VALUE);
	i = 0;
	while (p->splitted_cmd[ind][i])
	{
		handle_quoting(&p->splitted_cmd[ind][i], TEMP_VALUE, SPACE);
		aux = p->splitted_cmd[ind][i];
		p->splitted_cmd[ind][i] = ft_strtrim(p->splitted_cmd[ind][i], "'");
		free(aux);
		i++;
	}
}

int	check_path(t_pipex *p, int count)
{
	int	i;

	i = 0;
	p->bar = ft_strjoin("/", p->splitted_cmd[count][0]);
	while (p->envp_path_list[i] != NULL)
	{
		p->path = ft_strjoin(p->envp_path_list[i], p->bar);
		if (access(p->path, F_OK | X_OK) == 0)
		{
			return (i);
		}
		i++;
		free(p->path);
	}
	return (CMD_NOT_FOUND);
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
