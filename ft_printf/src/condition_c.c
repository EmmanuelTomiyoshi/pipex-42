/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   condition_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 19:58:00 by etomiyos          #+#    #+#             */
/*   Updated: 2022/06/13 20:14:32 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	condition_c(va_list ptr)
{
	int	res;

	res = va_arg(ptr, int);
	write(1, &res, 1);
	return (1);
}
