/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 08:51:32 by etomiyos          #+#    #+#             */
/*   Updated: 2022/10/06 10:01:42 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// typedef struct  s_pipex
// {
//     char    **argv;
//     int     argc;
// }               t_pipex;

// void	ft_bzero(void *s, size_t n)
// {
// 	memset(s, '\0', n);
// }

// void	*ft_calloc(size_t nelem, size_t elsize)
// {
// 	void	*ptr;

// 	ptr = malloc(nelem * elsize);
// 	if (ptr == NULL)
// 		return (NULL);
// 	ft_bzero(ptr, (nelem * elsize));
// 	return (ptr);
// }


// void	dynamic_data(t_pipex *pipex, char *argv[] /*char *envp[]*/)
// {
// 	int i;

// 	i = 0;
// 	pipex->argv = ft_calloc(sizeof(char *), pipex->argc + 1);
    
//     pipex->argv[i] = ft_calloc(sizeof(char), strlen(argv[i]) + 1);
	
// 	while (i < pipex->argc)
// 	{
// 		pipex->argv[i] = argv[i];
// 		printf("%d) argv[%d] = %s\n", i, i, pipex->argv[i]);
// 		i++;
// 	}
// }


// int main(int argc, char *argv[], char *envp[])
// {
//     t_pipex	pipex;
    
//     pipex.argc = argc;
//     printf("argc: %d\n", argc);

//     dynamic_data(&pipex, argv);
//     return (0);
// }