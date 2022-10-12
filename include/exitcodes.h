/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exitcodes.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 08:54:29 by etomiyos          #+#    #+#             */
/*   Updated: 2022/10/12 11:12:16 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXITCODES_H

# define EXITCODES_H

# include <errno.h>

# define USUAL_ERROR 1
# define CMD_CANT_EXECUTE 126
# define CMD_NOT_FOUND 127
# define EX_INVALID_ARG 128
# define MSG_CMD_NOT_FOUND "command not found\n"
# define NO_FILE "No such file or directory\n"
# define SINGLE_QUOTE 39
# define TEMP_VALUE -1
# define SPACE 32

# define INVALID_ARGS "bash: syntax error near unexpected token `newline'\n"

# define PIPEX_EXAMPLE_1 "1) ./pipex file1 \"ls -l\" \"wc -l\" file2\n"
# define EXPECTED_EXAMPLE_1 "Should behave like: \
< file1 ls -l | wc -w > file2\n\n"

# define PIPEX_EXAMPLE_2 "2) ./pipex file1 \"grep a1\" \"wc -w\" file2\n"
# define EXPECTED_EXAMPLE_2 "Should behave like: \
< file1 grep a1 | wc -w file2\n\n"

#endif