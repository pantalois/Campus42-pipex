/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loigonza <loigonza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:27:49 by loigonza          #+#    #+#             */
/*   Updated: 2024/02/05 15:24:14 by loigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>
#include <stdio.h>
#include <libc.h>
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;
	size_t				i;

	if (!dst && !src)
		return (0);
	d = (unsigned char *)dst;
	s = (const unsigned char *)src;
	i = -1;
	if (d > s)
		while (n-- > 0)
			d[n] = s[n];
	else
		while (++i < n)
			d[i] = s[i];
	return (dst);
}
/*
int	main(void)
{
	char	dst[9] = "ABCDEF--";
	char	src[10] = "asdasd";
	size_t	n = 5 * sizeof(char);

	printf("dst ft_memmove:%s\n", ft_memmove(dst, src, n));
	char	dmemmove[9] = "ABCDEF--";
	char	smemmove[10] = "asdasd";
	printf("dst memmove: %s\n", memmove(dmemmove, smemmove, n));
}

void    *ft_memmove(void *dst, const void *src, size_t n)
{
    unsigned char       *d;
    const unsigned char *s;
    size_t              i;

    d = (unsigned char *)dst;
    s = (const unsigned char *)src;
    i = -1;
    if (!d && !s)
        return (0);
    if (d > s)
        while (n-- > 0)
            //n--; Esta seria la posicion del n si no estuviera dentro del while
            d[n] = s[n];
    else
        while (++i < n)
            d[i] = s[i];
            //i++; esta seria la posicion que tendria i de no estar en el while
    return (dst);
}
*/
