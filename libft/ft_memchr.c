/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loigonza <loigonza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 19:42:01 by loigonza          #+#    #+#             */
/*   Updated: 2024/02/06 09:39:24 by loigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <string.h>
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	let;

	i = 0;
	str = (unsigned char *)s;
	let = (unsigned char)c;
	while (i < n)
	{
		if (str[i] == let)
			return (&str[i]);
		i++;
	}
	return (0);
}
/*
int	main(void)
{
	char	s[10] = "la mondo";
	char	x[10] = "la mondo";
	size_t	n = 3;
	printf("mi funcion: %s\n", ft_memchr(s, 2, n));
	printf("la funcion: %s\n", memchr(x, 2, n));
	return (0);
}
*/	
