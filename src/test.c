/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 20:02:39 by etomiyos          #+#    #+#             */
/*   Updated: 2022/09/23 16:09:02 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char **argv, char **envp)
{
    
    // if (access("/usr/bin", X_OK) == -1)
    //     perror("an error occured with access fn\n");
    // printf("bad error\n");
    // return (0);
}








// int main(void)
// {
//     int pipefd[2];
    
//     pipe(pipefd);

//     int childPid = fork();
//     if (childPid == 0)
//     {
//         char *av[] = {"/bin/echo", "hello_ _world", NULL};
    
//         close(pipefd[0]);
//         dup2(pipefd[1], 1);
//         close(pipefd[1]);

//         if (execv(av[0], av) == -1)
//         {
//             perror("execv: ");
//         }
//         exit(0);
//     }

//     char *av[] = {"/usr/bin/tr", "-d", "_", NULL};

//     close(pipefd[1]);
//     dup2(pipefd[0], 0);
//     close(pipefd[0]);
//     if (execv(av[0], av) == -1)
//     {
//         perror("execv: ");
//     }
//     return (0);
// }


//COMMUNICATION
// int main(int argc, char *argv[])
// {
//     //fd[0] - read
//     //fd[1] - write
//     int fd[2];
//     int id;
//     int x;
//     int y;

//     if (argc <= 1)
// 		exit(1);
// 	else if (argc == 2 && !strncmp(argv[1], "mandelbrot", 10))
//         printf("OOooii\n");

//     if (pipe(fd) == -1) //error
//     {
//         printf("Um erro ocorreu com pipe\n");
//         return (1);
//     }
//     id = fork();
//     if (id == -1) //error
//     {
//         printf("Um erro ocorreu com fork\n");
//         return (4);
//     }
//     if (id == 0) //child process
//     {
//         close(fd[0]); //close the read end of the pipe
//         printf("Input a number: ");
//         scanf("%d", &x);
//         if (write(fd[1], &x, sizeof(int)) == -1)
//         {
//             printf("Um erro ocorreu com write\n");
//             return (2);
//         }
//         close(fd[1]);
//     }
//     else
//     {
//         close(fd[1]); //i'm not using write here, then close
//         if (read(fd[0], &y, sizeof(int)) == -1)
//         {
//             printf("Um erro ocorreu com read\n");
//             return (3);
//         }
//         close(fd[0]);
//         printf("Seu número é %d\n", y);
//     }
// }
