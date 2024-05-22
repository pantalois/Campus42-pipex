/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loigonza <loigonza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:52:46 by loigonza          #+#    #+#             */
/*   Updated: 2024/02/05 16:40:28 by loigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	value;

	i = 0;
	j = 0;
	if (size == 0)
		return (ft_strlen(src));
	else if (size < ft_strlen(dst))
		value = ft_strlen(src) + size;
	else
		value = ft_strlen(dst) + ft_strlen(src);
	while (dst[i] != '\0')
		i++;
	while ((src[j] != '\0') && ((i < (size - 1))))
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (value);
}
/*
int	main(void)
{
	char	d[10] = "hola";
	char	s[] = "mundo";
	char	dst[10] = "hola";
	char	src[] = "mundo";

	ft_strlcat(d, s, 6);
	printf("mi funcion: %s\n", d);
	strlcat(dst, src, 6);
	printf("funcion segura: %s\n", dst);
	return (0);
}
*/
