/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-lang <mde-lang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 21:48:07 by mde-lang          #+#    #+#             */
/*   Updated: 2022/11/22 20:10:55 by mde-lang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	startpoint;

	i = 0;
	j = 0;
	if (!haystack && !len)
		return (0);
	startpoint = 0;
	if (!needle[j])
		return ((char *)haystack);
	while (haystack[i] && len > 0)
	{
		while (haystack[i] == needle[j] && i < len)
		{
			if (needle[j + 1] == '\0')
				return ((char *)&haystack[i - j]);
			i++;
			j++;
		}
		startpoint++;
		i = startpoint;
		j = 0;
	}
	return (NULL);
}
