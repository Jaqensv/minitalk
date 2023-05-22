/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-lang <mde-lang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 17:06:12 by mde-lang          #+#    #+#             */
/*   Updated: 2022/11/17 22:02:36 by mde-lang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *pointer, int value, size_t count)
{
	char	*pointer_size;
	size_t	i;

	i = 0;
	pointer_size = pointer;
	while (i < count)
	{
		pointer_size[i] = (unsigned char)value;
		i++;
	}
	return (pointer);
}
