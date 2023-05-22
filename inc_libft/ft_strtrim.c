/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-lang <mde-lang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 21:58:00 by mde-lang          #+#    #+#             */
/*   Updated: 2022/11/19 19:53:35 by mde-lang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int	i;

	if (!s1 || !set)
		return (NULL);
	while (*s1 && ft_strchr((char *)set, s1[0]))
		s1++;
	i = ft_strlen(s1) - 1;
	while (i > 0 && ft_strrchr((char *)set, s1[i]))
		i--;
	return (ft_substr(s1, 0, (i + 1)));
}
