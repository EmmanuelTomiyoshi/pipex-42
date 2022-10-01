/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_character.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 19:57:31 by etomiyos          #+#    #+#             */
/*   Updated: 2022/06/13 20:05:34 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_is_character(char c, va_list ptr)
{
	int	len;

	len = 1;
	if (c == 'c')
		len = condition_c(ptr);
	else if (c == 's')
		len = condition_s(ptr);
	else if (c == 'p')
		len = condition_p(ptr);
	else if (c == 'd' || c == 'i')
		len = condition_di(ptr);
	else if (c == 'u')
		len = condition_u(ptr);
	else if (c == 'x' || c == 'X')
		len = condition_x(ptr, c);
	else if (c == '%')
		write(1, "%", 1);
	return (len);
}
