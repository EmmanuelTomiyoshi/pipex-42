/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 12:24:30 by etomiyos          #+#    #+#             */
/*   Updated: 2022/10/06 19:28:51 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	t_pipex	pipex;

	pipex.fd_debug = open("debug.txt", O_CREAT | O_RDWR, 0777);
	pipex.status = 0;
	init_data(&pipex, argc, argv, envp);
	handle_error(&pipex);
	forking(&pipex, envp);
	close_pipes(&pipex);
	wait_status(&pipex);
	close(pipex.fd_debug);
	free_memory(&pipex);
	return (pipex.status);
}
