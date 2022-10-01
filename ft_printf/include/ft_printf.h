/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 15:04:29 by etomiyos          #+#    #+#             */
/*   Updated: 2022/09/30 15:04:30 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

int		ft_printf(const char *s, ...);
int		condition_c(va_list ptr);
int		condition_s(va_list ptr);
int		condition_p(va_list ptr);
int		condition_di(va_list ptr);
int		condition_u(va_list ptr);
int		condition_x(va_list ptr, char c);
int		ft_is_character(char c, va_list ptr);
char	*ft_itoa(int n);
char	*ft_uns_itoa(unsigned int n);

#endif