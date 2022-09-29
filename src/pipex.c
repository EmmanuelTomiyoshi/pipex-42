/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 12:24:30 by etomiyos          #+#    #+#             */
/*   Updated: 2022/09/29 09:22:50 by etomiyos         ###   ########.fr       */
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
	
	printf(GREEN "\nPIPE VALUES\n");
	printf(RESET "");
	pipe_values(&pipex);
	
	printf(GREEN "\nFILE1 & FILE2 FDs\n");
	printf(RESET "");
	printf("infd(%d) | outfd(%d)\n", pipex.infd, pipex.outfd);

	get_cmd_list(&pipex, argc, argv);
	
//-----------------filho1
	pipex.pid1 = fork();
	if (pipex.pid1 < 0)
		return (2);
	
	if (pipex.pid1 == 0) //child
	{
		split_pathname(&pipex, argv, envp);
		j = check_path(&pipex);
		
		dup2(pipex.array_fd[0][0], STDIN_FILENO); //redirecting
		close(pipex.array_fd[0][0]);
		close(pipex.array_fd[0][1]);
		pipex.path = ft_strjoin(pipex.pathVec[j], pipex.bar);
		
		printf(GREEN "\nFINAL RESULT:\n");
		printf(RESET "");
		printf("path: %s | splitted_cmd[%d]: %s | bar: %s\n",
				pipex.path, j, pipex.splitted_cmd[0], pipex.bar);
				
		if (execve(pipex.path, pipex.splitted_cmd, envp) == -1) //no executing after execve?
			perror("error\n");
		printf("Algo deu errado\n");
	}
// 	}

// // //------------------filho2
// // 	pipex.pid2 = fork();
// // 	if (pipex.pid2 < 0)
// // 		return (3);
		
// // 	if (pipex.pid2 == 0) //child2
// // 	{
// // 		split_pathname(&pipex, argv, envp);
// // 		j = check_path(&pipex);
		
// // //		printf(GREEN "\npathVec[j]:%s | j:%d\nbar:%s\n", pipex.pathVec[j], j, pipex.bar);
// // 		dup2(fd[1], STDIN_FILENO);
// // 		close(fd[0]);
// // 		close(fd[1]);
		
// // 		pipex.path = ft_strjoin(pipex.pathVec[j], pipex.bar);
		
// // 		if (execve(pipex.path, pipex.split_cmd, envp) == -1) //
// // 			perror("error\n");
// // 		printf("Algo deu errado\n");
// // 		printf(RESET "");
// // 	}
// // //

	//closed by only the main program
	close(pipex.array_fd[0][0]);
	close(pipex.array_fd[0][1]);
	
	waitpid(pipex.pid1, NULL, 0);
	waitpid(pipex.pid2, NULL, 0);
	
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