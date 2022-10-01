/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 12:24:30 by etomiyos          #+#    #+#             */
/*   Updated: 2022/09/30 15:34:53 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int argc, char *argv[], char *envp[])
{
	t_pipex	pipex;
	int		i;
	int		j;

	error_not_enough_args(&pipex, argc);
	init_data(&pipex, argc);
	error_not_enough_cmds(&pipex);
//
	ft_printf(GREEN "\nALLOCATING MEMORY FOR FDs\n");
	ft_printf(RESET "");
	fd_memory_allocate(&pipex);

	pipex.infd = open(argv[1], O_WRONLY); //opening fd file1
	pipex.outfd = open(argv[argc - 1], O_CREAT | O_RDWR | O_TRUNC, S_IRWXU); //fd file2
	
	ft_printf(GREEN "\nPIPE VALUES\n");
	ft_printf(RESET "");
	pipe_values(&pipex);
	
	ft_printf(GREEN "\nFILE1 & FILE2 FDs\n");
	ft_printf(RESET "");
	ft_printf("infd(%d) | outfd(%d)\n", pipex.infd, pipex.outfd);

	get_cmd_list(&pipex, argv);
	
//-----------------filho1

	i = 0;

	while (i < pipex.how_many_cmds)
	{
		pipex.pid1 = fork();
		if (pipex.pid1 < 0)
			return (2);
		
		if (pipex.pid1 == 0)
		{
			// ft_printf(RED "OI\n");
			// ft_printf(RESET "");
			split_pathname(&pipex, argv, envp, i);
			j = check_path(&pipex, i);
//
			if (i == 0)
			{
				dup2(pipex.infd, STDIN_FILENO); //entrada
				dup2(pipex.array_fd[i][1], STDOUT_FILENO); //saída
			}
			else if (i != (pipex.how_many_cmds - 1))
			{
				dup2(pipex.array_fd[i - 1][0], STDIN_FILENO); //entrada
				dup2(pipex.array_fd[i][1], STDOUT_FILENO); //saída
			}
			else
			{
				dup2(pipex.array_fd[i - 1][0], STDIN_FILENO); //entrada
				dup2(pipex.outfd, STDOUT_FILENO); //saída
			}
			close_pipes(&pipex);
//
			pipex.path = ft_strjoin(pipex.pathVec[j], pipex.bar);
			if (execve(pipex.path, pipex.splitted_cmd, envp) == -1)
			{	
				perror("execve error: ");
				exit(COMMAND_NOT_FOUND);
			}
			ft_printf("Algo deu errado\n");
		}
		i++;
	}

//
	int status;
	close_pipes(&pipex);
	waitpid(pipex.pid1, &status, 0);
	ft_printf("status:%d\n", WEXITSTATUS(status));
//
	
	return (0);
}

//instruções e etc

//pegar o comando 
//concatenar com /usr/bin = /usr/bin/<comando>
//executar ele no infile
//uso o pipe para pegar escrever o meu input

//pegar o comando
//concatenar com /usr/bin = /usr/bin/<comando>
//executar ele no outfile
//uso o pipe para pegar ler o meu input

//open, close, read, write, malloc, free
//perror, strerror, access, dup, dup2,
//execve, exit, fork, pipe
//unlink, wait, waitpid