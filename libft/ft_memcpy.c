/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loigonza <loigonza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 12:19:40 by loigonza          #+#    #+#             */
/*   Updated: 2024/02/05 15:10:21 by loigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stddef.h>
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	const unsigned char	*s;
	unsigned char		*d;

	i = 0;
	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	if (!d && !s)
		return (0);
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}
/*
#include <string.h>

int	main(void)
{
	char	a[]  = "Hola";
	char	b[]  = "Mundo";

	ft_memcpy(a, b, 1);
	printf("ft_memcpy: %s\n", a);
	memcpy(a, b, 1);
	printf("memcpy: %s\n", a);
	return (0);
}
*/
