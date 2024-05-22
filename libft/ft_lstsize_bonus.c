/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loigonza <loigonza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 19:20:43 by loigonza          #+#    #+#             */
/*   Updated: 2024/02/06 14:14:21 by loigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	lst_size;

	lst_size = 0;
	while (lst != NULL)
	{
		lst_size++;
		lst = lst->next;
	}
	return (lst_size);
}
/*
int	main(void)
{
	char *str = "holamundo";
	t_list *lst = ft_lstnew(str);
	ft_lstsize(lst);
	printf("tamanho: %d\n", ft_lstsize(lst));
	return (0);
}
*/
