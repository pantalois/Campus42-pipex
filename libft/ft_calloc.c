/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loigonza <loigonza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 10:33:02 by loigonza          #+#    #+#             */
/*   Updated: 2024/02/28 17:57:58 by loigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = malloc(count * size);
	if (!ptr)
		return (0);
	ft_bzero (ptr, size * count);
	return (ptr);
}
/*
int	main(void)
{
	size_t	a = 1;
	size_t	b = 1;
	printf("ft_calloc: %p\n", ft_calloc(a, b));
	printf("calloc: %p\n", calloc(a, b));
	return (0);
}
*/
