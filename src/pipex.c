/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 12:24:30 by etomiyos          #+#    #+#             */
/*   Updated: 2022/10/06 09:35:27 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	t_pipex	pipex;
	int		i;
	int		status;
	
	pipex.fd_debug = open("debug.txt", O_CREAT | O_RDWR, 0777); //>
	status = 0; //>
	init_data(&pipex, argc, argv);
	if (error_not_enough_args(&pipex) == 1)
		return (1);
	error_not_enough_cmds(&pipex);
	fd_memory_allocate(&pipex);
	pipe_values(&pipex);
	get_cmd_list(&pipex, argv);
	split_pathname(&pipex, envp);
	i = 0;
	while (i < pipex.cmd_number)
	{
		pipex.splitted_cmd[i] = ft_split(pipex.cmd_list[i], ' '); //
		pipex.pid_fd[i] = fork();
		if (pipex.pid_fd[i] < 0)
			return (2);
		if (pipex.pid_fd[i] == 0)
			status = child_process_check(&pipex, envp, i);
		i++;
	}
	
	close_pipes(&pipex);

	i = 0;
	while (i < pipex.cmd_number)
	{
		waitpid(pipex.pid_fd[i], &status, 0);
		ft_printf("status:%d\n", WEXITSTATUS(status));
		
		if (WIFEXITED(status))
			status = WEXITSTATUS(status);
		if (status != 0)
			error_pipex(status, pipex.splitted_cmd[i][0]);
		i++;
	}
	
	close(pipex.fd_debug); //

	if (status == 0)
		printf("OK!\n");
	else
		printf("KO!\n");
	free_memory(&pipex);
	return (0);
}

//pegar o pid de todos
//while pid, waitpid();
//wexitstatus em cada pid