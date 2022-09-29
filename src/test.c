/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 20:02:39 by etomiyos          #+#    #+#             */
/*   Updated: 2022/09/28 19:36:01 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h> 
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <time.h>
# include <sys/wait.h>
# include <errno.h>

int main(int argc, char **argv, char **envp)
{
    int fd1[2];
    int fd2[2];

    char fixed_str[] = "in.c";
    char input_str[] = "Hello.world.";
    pid_t p;

    if (pipe(fd1) == -1) //main
    {
        fprintf(stderr, "pipe1 failed");
        return (1);
    }
    if (pipe(fd2) == -1) //main
    {
        fprintf(stderr, "pipe2 failed");
        return (1);
    }

    p = fork(); //main
    
    if (p < 0)
    {
        fprintf(stderr, "fork failed");
    }

    //parent
    else if (p > 0)
    {
        char concat_str[100];
        close(fd1[0]); //close reading end
        
        write(fd1[1], input_str, strlen(input_str) + 1);
        close(fd1[1]);
        
        wait(NULL);
        close(fd2[1]);
        read(fd2[0], concat_str, 100);
        printf("Concatenated string is: %s\n", concat_str);
        close(fd2[0]);
    }

    //child
    else {
        int k;
        int i;
        char concat_str[100];
        

        close(fd1[1]);
        read(fd1[0], concat_str, 100);

        k = strlen(concat_str);
        while (i < strlen(fixed_str))
        {
            concat_str[k] = fixed_str[i];
            i++;
            k++;
        }
        concat_str[k];
        
        close(fd1[0]);
        close(fd2[0]);

        write(fd2[1], concat_str, strlen(concat_str) + 1);
        close(fd2[1]);

        exit(0);
    }
    
}
