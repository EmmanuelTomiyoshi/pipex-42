/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 20:02:39 by etomiyos          #+#    #+#             */
/*   Updated: 2022/09/29 20:45:48 by etomiyos         ###   ########.fr       */
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
	int fd;

	fd = open("file1.txt", O_WRONLY | O_APPEND);

	dup2(fd, STDOUT_FILENO);
	
	printf("Ola ola ola");
}
