/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loigonza <loigonza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 16:11:36 by loigonza          #+#    #+#             */
/*   Updated: 2024/02/06 14:09:51 by loigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}
/*
int	main(void)
{
	char	*str = "hola que ase";
	char	*str2 = "content a anhadir";

	t_list	*lst = ft_lstnew(str);
	t_list	*new = ft_lstnew(str2);
	ft_lstadd_front(&lst, new);
	while (lst)
	{
		printf("%s\n", lst->content);
		lst = lst->next;
	}
	return (0);
}
*/
