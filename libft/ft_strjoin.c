/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loigonza <loigonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 13:17:09 by loigonza          #+#    #+#             */
/*   Updated: 2024/05/21 11:05:00 by loigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	idx;
	size_t	idx_ptr;
	char	*ptr;

	idx_ptr = 0;
	if (!s1 && !s2)
		return (0);
	ptr = malloc(sizeof(char) * ((ft_strlen(s1) + ft_strlen(s2)) + 1));
	if (!ptr)
		return (0);
	idx = -1;
	while (s1[++idx] != '\0')
	{
		ptr[idx_ptr] = s1[idx];
		idx_ptr++;
	}
	idx = -1;
	while (s2[++idx] != '\0')
	{
		ptr[idx_ptr] = s2[idx];
		idx_ptr++;
	}
	ptr[idx_ptr] = '\0';
	return (ptr);
}
/*
int	main(void)
{
	const char *s1 = "hola ";
	const char *s2 = "mundo";
	printf("s3: %s\n", ft_strjoin(s1, s2));
	return (0);
}
*/
 
