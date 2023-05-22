/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-lang <mde-lang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 17:04:18 by mde-lang          #+#    #+#             */
/*   Updated: 2022/11/17 21:49:31 by mde-lang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *pointer_s, size_t n)
{
	unsigned char	*str;
	size_t			i;

	str = (unsigned char *)pointer_s;
	i = 0;
	str = pointer_s;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
	pointer_s = (void *)str;
}
