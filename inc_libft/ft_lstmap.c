/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-lang <mde-lang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 17:13:55 by mde-lang          #+#    #+#             */
/*   Updated: 2023/04/14 06:11:50 by mde-lang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_lst	*ft_lstmap(t_lst *lst, void *(*f)(void *), void (*del)(void *))
{
	t_lst	*tmp;
	t_lst	*new_element;

	if (!lst || !f)
		return (0);
	new_element = 0;
	while (lst)
	{
		tmp = (f(lst->content));
		lst = ft_lstnew(tmp);
		if (!lst)
		{
			free(tmp);
			ft_lstclear(&new_element, del);
			return (0);
		}
		ft_lstadd_back(&new_element, lst);
		lst = lst->next;
	}
	return (new_element);
}
