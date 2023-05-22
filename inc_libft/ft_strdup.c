/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-lang <mde-lang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 19:17:43 by mde-lang          #+#    #+#             */
/*   Updated: 2022/11/17 22:08:50 by mde-lang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		i;
	char	*c;

	i = 0;
	c = malloc(ft_strlen(s) + 1);
	if (!c)
		return (NULL);
	while (i < (int)ft_strlen(s))
	{
		c[i] = s[i];
		i++;
	}
	c[i] = 0;
	return (c);
}
