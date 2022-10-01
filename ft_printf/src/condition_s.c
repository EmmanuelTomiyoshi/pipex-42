/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   condition_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 19:57:49 by etomiyos          #+#    #+#             */
/*   Updated: 2022/06/13 20:11:32 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	condition_s(va_list ptr)
{
	char	*x;
	int		y;

	y = 0;
	x = va_arg(ptr, char *);
	if (x == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (x[y])
	{
		write(1, &x[y], 1);
		y++;
	}
	return (y);
}
