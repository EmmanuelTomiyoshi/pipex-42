/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 12:24:30 by etomiyos          #+#    #+#             */
/*   Updated: 2022/10/02 10:40:42 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	t_pipex	pipex;
	int		i;
	int		status;

	if (error_not_enough_args(argc) == 1)
		return (1); //
	init_data(&pipex, argc, argv);
	error_not_enough_cmds(&pipex); //
	fd_memory_allocate(&pipex);
	pipe_values(&pipex);
	get_cmd_list(&pipex, argv);
	i = 0;
	while (i < pipex.how_many_cmds)
	{
		pipex.pid1 = fork();
		if (pipex.pid1 < 0)
			return (2);
		if (pipex.pid1 == 0)
			child_process_check(&pipex, envp, i);
		i++;
	}
	close_pipes(&pipex);
	waitpid(pipex.pid1, &status, 0);
	ft_printf("status:%d\nOK!\n", WEXITSTATUS(status));
	free_memory(&pipex);
	return (0);
}
