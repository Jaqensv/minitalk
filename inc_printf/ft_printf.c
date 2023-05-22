/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-lang <mde-lang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 20:43:10 by mde-lang          #+#    #+#             */
/*   Updated: 2023/01/05 16:24:59 by mde-lang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>
#include <stdlib.h>

int	ft_check(va_list ap, char character)
{
	int	fly;

	fly = 0;
	if (character == '%')
		return (ft_putchar('%'));
	if (character == 'c')
		return (ft_putchar(va_arg(ap, int)));
	if (character == 's')
		return (ft_putstr(va_arg(ap, char *)));
	if (character == 'd' || character == 'i')
		return (ft_putnbr(va_arg(ap, int), fly));
	if (character == 'u')
		return (ft_putnbr(va_arg(ap, unsigned int), fly));
	if (character == 'x' || character == 'X')
		return (ft_putnbr_hexa(va_arg(ap, unsigned int), character, fly));
	if (character == 'p')
		return (ft_putnbr_hexa(va_arg(ap, unsigned long), character, fly));
	else
		if (ft_putchar(character) == -1)
			return (-1);
	return (-1);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		total_len;
	int		j;
	va_list	ap;

	va_start(ap, format);
	j = 0;
	i = -1;
	total_len = 0;
	while (format[++i])
	{
		if (format[i] == '%')
		{	
			j = ft_check(ap, format[++i]);
			if (j < 0)
				return (-1);
			total_len += j;
		}
		else if (write(1, &format[i], 1) == -1)
			return (-1);
		else
			total_len++;
	}
	va_end(ap);
	return (total_len);
}
