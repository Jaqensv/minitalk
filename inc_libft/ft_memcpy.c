/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-lang <mde-lang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 17:06:04 by mde-lang          #+#    #+#             */
/*   Updated: 2022/11/17 22:00:32 by mde-lang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *destination, const void *source, size_t size)
{
	char	*destination2;
	char	*source2;
	size_t	i;

	destination2 = (char *)destination;
	source2 = (char *)source;
	i = 0;
	if (destination2 == source2)
		return (destination);
	while (i < size)
	{
		destination2[i] = source2[i];
		i++;
	}
	return (destination);
}
