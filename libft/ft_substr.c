/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loigonza <loigonza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 17:47:48 by loigonza          #+#    #+#             */
/*   Updated: 2024/05/20 16:09:58 by loigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	unsigned int	j;
	char			*ptr;

	i = ft_strlen(s);
	j = 0;
	if (!s)
		return (NULL);
	if (i < start)
		len = 0;
	else if (len > ft_strlen(&s[start]))
		len = ft_strlen(&s[start]);
	ptr = malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (NULL);
	while (len--)
	{
		ptr[j] = s[start];
		start++;
		j++;
	}
	ptr[j] = '\0';
	return (ptr);
}
/*
#include <stdio.h>

int	main(void)
{
	ft_substr("hola mundo", 15, 6);
	return (0);
}
*/
