/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 12:24:30 by etomiyos          #+#    #+#             */
/*   Updated: 2022/10/03 16:28:16 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	t_pipex	pipex;
	int		i;
	int		status;
	
	init_data(&pipex, argc, argv);
	if (error_not_enough_args(&pipex) == 1)
		return (1);
	error_not_enough_cmds(&pipex);
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
			status = child_process_check(&pipex, envp, i);
		i++;
	}
	close_pipes(&pipex);
	waitpid(pipex.pid1, &status, 0);
	ft_printf("status:%d\n", WEXITSTATUS(status));
	if (status == 0)
		printf("OK!\n");
	else
		printf("KO!\n");
	free_memory(&pipex);
	return (0);
}
