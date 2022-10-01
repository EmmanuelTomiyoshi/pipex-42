/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   condition_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 19:57:44 by etomiyos          #+#    #+#             */
/*   Updated: 2022/06/13 20:10:57 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	condition_u(va_list ptr)
{
	char	*x;
	int		y;

	y = 0;
	x = ft_uns_itoa(va_arg(ptr, int));
	while (x[y])
	{
		write(1, &x[y], 1);
		y++;
	}
	free(x);
	if (y < 0)
		return (10);
	return (y);
}
