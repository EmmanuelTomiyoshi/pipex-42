/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 12:24:30 by etomiyos          #+#    #+#             */
/*   Updated: 2022/09/24 15:15:31 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int argc, char *argv[], char *envp[])
{
	// pid_t pid = getpid();
	// < file1 cmd1 | cmd2 > file2
	// ./pipex infile "ls -l" "wc -l" outfile

	//-----EXAMPLE----
	//./pipex file1 "ls -l"

	//stdin 0
	//stdout 1
	//stderr 2
	
    t_pipex	pipex;
	int j;
	int fd[2];
	int pid1;
	int pid2;
	int argcount;
	
	if (argc <= 1)
	{
		printf("Argumentos insuficientes\n");
		return (1);
	}
	if (pipe(fd) == -1)
		return (1);

	pipex.infd = open(argv[1], O_WRONLY); //opening fd file1
	pipex.outfd = open(argv[argc - 1], O_CREAT | O_RDWR | O_TRUNC, S_IRWXU); //fd file2

	fd[0] = pipex.infd;
	fd[1] = pipex.outfd;
	printf("fd[0]: %d | fd[1]: %d\n", fd[0], fd[1]);


	pid1 = fork();
	if (pid1 < 0)
		return (2);
	
	if (pid1 == 0) //child
	{
		split_pathname(&pipex, argv, envp);
		j = check_path(&pipex);
		
		dup2(fd[0], STDOUT_FILENO); //redirecting
		close(fd[0]);
		close(fd[1]);		
		pipex.path = ft_strjoin(pipex.pathVec[j], pipex.bar);
		if (execve(pipex.path, pipex.cmd, envp) == -1)
			perror("error\n");
		printf("Algo deu errado\n");
	}

//
	pid2 = fork();
	if (pid2 < 0)
		return (3);
		
	if (pid2 == 0) //child2
	{
		
		split_pathname(&pipex, argv, envp);
		j = check_path(&pipex);
		
		printf(GREEN "\npathVec[j]:%s | j:%d\nbar:%s\n", pipex.pathVec[j], j, pipex.bar);
		dup2(fd[1], STDIN_FILENO);
		close(fd[0]);
		close(fd[1]);
		
		pipex.path = ft_strjoin(pipex.pathVec[j], pipex.bar);
		
		if (execve(pipex.path, pipex.cmd, envp) == -1) //
			perror("error\n");
		printf("Algo deu errado\n");
		printf(RESET "");
	}
//

	//closed by only the main program
	close(fd[0]);
	close(fd[1]);
	
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	
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