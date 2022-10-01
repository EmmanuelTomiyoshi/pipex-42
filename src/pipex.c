/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 12:24:30 by etomiyos          #+#    #+#             */
/*   Updated: 2022/10/01 13:10:29 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int argc, char *argv[], char *envp[])
{
	t_pipex	pipex;
	int		i;
	int		status;

	error_not_enough_args(&pipex, argc);
	init_data(&pipex, argc);
	error_not_enough_cmds(&pipex);

	ft_printf(GREEN "\nALLOCATING MEMORY FOR FDs\n" RESET);
	fd_memory_allocate(&pipex);

	pipex.infd = open(argv[1], O_WRONLY);
	pipex.outfd = open(argv[argc - 1], O_CREAT | O_RDWR | O_TRUNC, S_IRWXU);
	
	ft_printf(GREEN "\nPIPE VALUES\n" RESET);
	pipe_values(&pipex);
	
	ft_printf(GREEN "\nFILE1 & FILE2 FDs\n" RESET);
	ft_printf("infd(%d) | outfd(%d)\n", pipex.infd, pipex.outfd);

	get_cmd_list(&pipex, argv);

	i = 0;
	while (i < pipex.how_many_cmds)
	{
		pipex.pid1 = fork();
		if (pipex.pid1 < 0)
			return (2);
		if (pipex.pid1 == 0)
		{	
			child_process_execution(&pipex, argv, envp, i);
		}
		i++;
	}
	close_pipes(&pipex);
	waitpid(pipex.pid1, &status, 0);
	ft_printf("status:%d\n", WEXITSTATUS(status));
	
	return (0);
}