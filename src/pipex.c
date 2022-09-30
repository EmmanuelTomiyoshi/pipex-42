/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 12:24:30 by etomiyos          #+#    #+#             */
/*   Updated: 2022/09/30 12:55:50 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

//while abrir os pipes de cada comando
//while executando cada comando
//while com waitpid pra organizar e deixar na sequência

//saber quantos argumentos tem --> how_many_arguments
//alocacao do meu array de fds em relação ao número de args
// // int **array_fd;
// // array_fd = calloc (sizeof(int *), args - 1); //dinâmico, de acordo com o n° de args
// // while (i < arg - 1)
// // array_fd[i] = calloc (sizeof(int), 2); //fixo, porque um pipe só tem 2 lados
//...

// COMANDO PRINCIPAL
// ./pipex file1 "sort" "uniq -c" "sort -r" "head -3" file2
int main(int argc, char *argv[], char *envp[])
{
  t_pipex	pipex;
	int i;
	int j;

	//--checking for argument errors--
	if (argc <= 1)
	{
		printf("Argumentos insuficientes\n");
		return (1);
	}

	//--initiating data--
	init_data(&pipex, argc, argv);

	printf(GREEN "\nALLOCATING MEMORY FOR FDs\n");
	printf(RESET "");
	fd_memory_allocate(&pipex);

	pipex.infd = open(argv[1], O_WRONLY); //opening fd file1
	pipex.outfd = open(argv[argc - 1], O_CREAT | O_RDWR | O_TRUNC, S_IRWXU); //fd file2
	
	printf(GREEN "\nPIPE VALUES\n");
	printf(RESET "");
	pipe_values(&pipex);
	
	printf(GREEN "\nFILE1 & FILE2 FDs\n");
	printf(RESET "");
	printf("infd(%d) | outfd(%d)\n", pipex.infd, pipex.outfd);

	get_cmd_list(&pipex, argc, argv);
	
//-----------------filho1

	i = 0;

	while (i < pipex.how_many_cmds)
	{
		pipex.pid1 = fork();
		if (pipex.pid1 < 0)
			return (2);
		
		if (pipex.pid1 == 0)
		{
			// printf(RED "OI\n");
			// printf(RESET "");
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
			printf("Algo deu errado\n");
		}
		i++;
	}

//
	int status;
	close_pipes(&pipex);
	waitpid(pipex.pid1, &status, 0);
	printf("status:%d\n", WEXITSTATUS(status));
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