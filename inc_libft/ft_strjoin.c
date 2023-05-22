/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-lang <mde-lang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 20:46:38 by mde-lang          #+#    #+#             */
/*   Updated: 2022/11/17 22:09:47 by mde-lang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	int		s3len;
	char	*s3;

	i = 0;
	j = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	s3len = ft_strlen(s1) + ft_strlen(s2);
	s3 = malloc(sizeof(char) * (s3len + 1));
	if (!s3)
		return (NULL);
	while (j < s3len)
	{
		while (s1[i])
			s3[j++] = s1[i++];
		i = 0;
		while (s2[i])
			s3[j++] = s2[i++];
	}
	s3[j] = '\0';
	return (s3);
}
