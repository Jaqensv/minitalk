/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-lang <mde-lang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 18:07:57 by mde-lang          #+#    #+#             */
/*   Updated: 2022/11/19 23:35:40 by mde-lang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	algo_m(int i, int m)
{
	while (m != 0)
	{
		m = m / 10;
		i++;
	}
	return (i);
}

static int	algo_calloc(char **s, int *i, int n)
{
	*s = NULL;
	if (n < 0)
	{
		*s = ft_calloc((*i) + 2, sizeof(char));
		if (!*s)
			return (0);
		(*s)[0] = '-';
		n = n * -1;
	}
	else
	{
		*s = ft_calloc((*i) + 1, sizeof(char));
		*i -= 1;
	}
	return (n);
}

char	*ft_itoa(int n)
{
	int		i;
	char	*s;
	int		m;

	m = n;
	i = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	i = algo_m(i, m);
	n = algo_calloc(&s, &i, n);
	if (!s)
		return (NULL);
	while (i >= 0)
	{
		if (n > 9)
			s[i] = n % 10 + '0';
		else if (s[i] != '-')
			s[i] = n + '0';
		n = n / 10;
		i--;
	}
	return (s);
}
