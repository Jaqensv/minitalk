/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-lang <mde-lang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 17:07:11 by mde-lang          #+#    #+#             */
/*   Updated: 2022/11/17 21:58:09 by mde-lang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *memoryBlock, int searchedChar, size_t size)
{
	char	*mem;
	char	chr;
	size_t	i;

	i = 0;
	mem = (char *)memoryBlock;
	chr = (char)searchedChar;
	while (i < size)
	{
		if (mem[i] == chr)
			return (&mem[i]);
		i++;
	}
	return (NULL);
}
