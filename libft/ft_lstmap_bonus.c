/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loigonza <loigonza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 18:30:41 by loigonza          #+#    #+#             */
/*   Updated: 2024/02/22 11:55:05 by loigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static void	*free_lst(t_list **new_list, void (*del)(void *), t_list *tmp_cnt)
{
	ft_lstclear(new_list, del);
	free(tmp_cnt);
	return (NULL);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void(*del)(void *))
{
	t_list	*new_list;
	void	*tmp_cnt;
	t_list	*tmp;

	if (!lst || !f || !del)
		return (0);
	new_list = NULL;
	while (lst)
	{
		tmp_cnt = f(lst->content);
		tmp = ft_lstnew(tmp_cnt);
		if (!tmp)
			return (free_lst(&new_list, del, tmp_cnt));
		ft_lstadd_back(&new_list, tmp);
		lst = lst->next;
	}
	return (new_list);
}
