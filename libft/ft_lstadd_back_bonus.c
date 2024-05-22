/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loigonza <loigonza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 20:10:03 by loigonza          #+#    #+#             */
/*   Updated: 2024/02/06 15:00:24 by loigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (!new)
		return ;
	if (*lst == NULL)
		*lst = new;
	else
	{
		temp = ft_lstlast(*lst);
		temp->next = new;
	}
}
/*
int	main(void)
{
	char	*str = "hola que ase";
	char	*str2 = "content a anhadir";

	t_list	*lst = ft_lstnew(str);
	t_list	*new = ft_lstnew(str2);
	ft_lstadd_back(&lst, new);
	while (lst)
	{
		printf("%s\n", lst->content);
		lst = lst->next;
	}
	return (0);
}
*/
