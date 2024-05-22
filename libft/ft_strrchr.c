/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loigonza <loigonza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 17:39:39 by loigonza          #+#    #+#             */
/*   Updated: 2024/02/05 16:53:50 by loigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int			i;
	char		chr;

	i = 0;
	chr = (char)c;
	while (s[i] != '\0')
		i++;
	while (i >= 0)
	{
		if (s[i] == chr)
			return ((char *) &s[i]);
		i--;
	}
	return (0);
}
/*
#include <string.h>
int	main(void)
{
	const char	*s = "asdfghPaaaa";
	int	c  = 80;
	printf("ft_strrchr comprobacion: %s\n", ft_strrchr(s, c));
	printf("strrchr comprobacion: %s\n", strrchr(s, c));
	return (0);
}
*/
