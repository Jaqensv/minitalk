/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-lang <mde-lang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 13:07:55 by mde-lang          #+#    #+#             */
/*   Updated: 2022/12/04 09:37:38 by mde-lang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h> //pour size_t, malloc
# include <stdio.h> //pour "NULL"
# include <string.h> //pour strnstr
# include <unistd.h>
# include <limits.h> // pour int_min / int_max

int		ft_printf(const char *format, ...);
int		ft_check(va_list ap, char character);
int		ft_putchar(char c);
int		ft_putstr(char *s);
int		ft_putnbr(long n, int fly);
int		ft_putnbr_hexa(unsigned long n, char format, int fly);
int		nbrlen(unsigned long n, int fly, char *base, int stat);

#endif
