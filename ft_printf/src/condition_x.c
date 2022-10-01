/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   condition_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 19:57:36 by etomiyos          #+#    #+#             */
/*   Updated: 2022/06/27 19:11:14 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	convert_hex(size_t res, char c)
{
	char		temp;
	static int	i = 0;
	int			j;
	int			is_case;

	j = i;
	if (c == 'x')
		is_case = 0;
	else
		is_case = 32;
	if (res != 0)
	{
		convert_hex(res / 16, c);
		if (res % 16 < 10)
			temp = res % 16 + 48;
		else
			temp = res % 16 - 10 + 'a' - is_case;
		write(1, &temp, 1);
		i++;
	}
	j = i - j;
	return (j);
}

int	condition_x(va_list ptr, char c)
{
	unsigned int	res;
	int				i;

	i = 0;
	res = va_arg(ptr, unsigned int);
	if (res == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	i = convert_hex(res, c);
	return (i);
}
