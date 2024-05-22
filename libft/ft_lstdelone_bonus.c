/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loigonza <loigonza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 12:23:37 by loigonza          #+#    #+#             */
/*   Updated: 2024/02/06 15:00:16 by loigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst)
	{
		del(lst->content);
		free(lst);
	}
}
/*static void del(void *content)
{
	free(content);
}
int	main(void)
{
	t_list	*lst = ft_lstnew("Hola mundo");
	printf("%s\n", lst->content);
	ft_lstdelone(lst, del);
	printf("%s\n", lst->content);
	return (0);
}*/
