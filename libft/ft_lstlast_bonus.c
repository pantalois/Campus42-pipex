/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loigonza <loigonza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 19:35:50 by loigonza          #+#    #+#             */
/*   Updated: 2024/02/06 14:16:03 by loigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*last_pos;

	if (!lst)
		return (lst);
	while (lst->next != NULL)
		lst = lst->next;
	last_pos = lst;
	return (last_pos);
}
