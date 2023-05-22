/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-lang <mde-lang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 16:10:39 by mde-lang          #+#    #+#             */
/*   Updated: 2022/11/24 21:11:10 by mde-lang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	strlen_modified(const char *str, char c, int start)
{
	int	len;

	len = start;
	while (str[len] != '\0' && str[len] != c)
		len++;
	return (len - start);
}

static char	*algo_strings(char const *s, char c, int start)
{
	int		i;
	int		j;
	int		x;
	char	*s2;

	x = 0;
	i = start;
	j = strlen_modified(s, c, start);
	s2 = ft_calloc(sizeof(char), (j + 1));
	if (!s2)
		return (NULL);
	while (s[i])
	{
		while (s[i] == c)
		{
			if (s[i + 1] != c)
			{
				s2[x] = '\0';
				return (s2);
			}
			i++;
		}
		s2[x++] = s[i++];
	}
	return (s2);
}

static int	nb_strings(char const *s, char c)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
			counter++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (counter);
}

static char	**tab_free(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	char	**tab;
	int		start;
	int		counter;

	i = 0;
	start = 0;
	if (!s)
		return (NULL);
	counter = nb_strings(s, c);
	tab = malloc(sizeof(char *) * (counter + 1));
	if (!tab)
		return (NULL);
	while (i < counter)
	{
		while (s[start] == c)
			start++;
		tab[i] = algo_strings(s, c, start);
		if (!tab[i])
			return (tab_free(tab));
		start += ft_strlen(tab[i]);
		i++;
	}
	tab[i] = 0;
	return (tab);
}
