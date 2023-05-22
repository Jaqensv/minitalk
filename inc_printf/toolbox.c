/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toolbox.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MAIN <MAIN@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 13:05:46 by mde-lang          #+#    #+#             */
/*   Updated: 2023/05/22 17:47:45 by MAIN             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>
#include <stdlib.h>

int	ft_putchar(char c)
{
	if (write(1, &c, 1) == -1)
		return (-1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
	{
		if (write(1, "(null)", 6) == -1)
			return (-1);
		return (6);
	}
	while (s[i])
		if (write(1, &s[i++], 1) == -1)
			return (-1);
	return (i);
}

int	nbrlen(unsigned long n, int fly, char *base, int stat)
{
	int				i;
	unsigned long	cm;

	i = 1;
	cm = 0;
	if (!stat)
		return (-1);
	while (base[cm])
		cm++;
	while (n >= cm && i++)
		n /= cm;
	return (i + fly);
}

int	ft_putnbr(long n, int fly)
{
	static int	stat;

	stat = 1;
	if (n < 0)
	{
		if (ft_putchar('-') == -1)
			return (-1);
		n *= -1;
		fly = 1;
	}
	if (n > 9)
		if (ft_putnbr(n / 10, fly) == -1)
			return (-1);
	if (stat && ft_putchar((n % 10) + 48) == -1)
	{
		stat = 0;
		return (-1);
	}
	return (nbrlen(n, fly, "0123456789", stat));
}

int	ft_putnbr_hexa(unsigned long n, char format, int fly)
{
	char		*hexa;
	static int	stat;

	stat = 1;
	if (format == 'p' && !fly)
	{
		if (write (1, "0x", 2) == -1)
			return (-1);
		fly += 2;
	}
	if (format == 'X')
		hexa = "0123456789ABCDEF";
	else
		hexa = "0123456789abcdef";
	if (n > 15)
		if (ft_putnbr_hexa(n / 16, format, fly) == -1)
			return (-1);
	if (stat && ft_putchar(hexa[n % 16]) == -1)
	{
		stat = 0;
		return (-1);
	}
	return (nbrlen(n, fly, hexa, stat));
}
