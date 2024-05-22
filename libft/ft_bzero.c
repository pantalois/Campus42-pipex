/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loigonza <loigonza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 12:56:50 by loigonza          #+#    #+#             */
/*   Updated: 2024/02/28 17:58:02 by loigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*dest;
	size_t	i;

	dest = (char *)s;
	i = 0;
	while (i != n)
	{
		dest[i] = '\0';
		i++;
	}
}
/*
#include <strings.h>

int	main(void)
{
	char	dest[5] = "hola";
	ft_bzero(dest, 1);
	printf("%s\n", dest);
	bzero(dest, 1);
	printf("%s\n", dest);
	return (0);
}
*/
