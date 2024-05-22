/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loigonza <loigonza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 10:02:27 by loigonza          #+#    #+#             */
/*   Updated: 2024/02/05 16:15:27 by loigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>
#include <stdio.h>
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	while (src[len] != '\0')
		len++;
	if (size != 0)
	{
		while (src[i] != '\0' && i < size - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (len);
}
/*
int	main(void)
{
	char	dst[] = "abcsdfgfdz";
	char	src[] = "holsdsdvsdvsdvsdvsdvsdvsdvv";
	size_t	size = 0;
	size_t	count = 0;
	count = ft_strlcpy(dst, src, size);
	printf("mi funcion: %s - %zu chars\n", dst, count);
	//size_t hola =
	char	d[] = "abcsdfgfdz";
	char	s[] = "holsdsdvsdvsdvsdvsdvsdvsdvv";
	count = strlcpy(d, s, size);
	printf("funcion segura: %s - %zu chars\n", d, count);
	return (0);
}
*/
