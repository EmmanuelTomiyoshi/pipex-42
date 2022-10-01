/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 15:05:07 by etomiyos          #+#    #+#             */
/*   Updated: 2022/10/01 20:10:49 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_writechar(char c)
{
	write(1, &c, 1);
}

int	check_char(const char *s, va_list ptr)
{
	int	i;
	int	len;
	int	count;
	int	var;

	len = 0;
	var = 0;
	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			count = ft_is_character(s[i + 1], ptr);
			i += 2;
		}
		if (s[i] && s[i] != '%')
		{
			ft_writechar(s[i++]);
			len++;
		}
		var += count;
		count = 0;
	}
	return (len + var);
}

int	ft_printf(const char *s, ...)
{
	va_list	ptr;
	int		len;

	len = 0;
	if (!s)
		return (0);
	va_start(ptr, s);
	len = check_char(s, ptr);
	va_end(ptr);
	return (len);
}
