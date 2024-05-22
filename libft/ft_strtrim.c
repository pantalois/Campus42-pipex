/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loigonza <loigonza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 09:55:07 by loigonza          #+#    #+#             */
/*   Updated: 2024/02/06 11:39:34 by loigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>
#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len_s1;

	if (!s1 || !set)
		return (NULL);
	while (ft_strchr(set, *s1) && *s1 != '\0')
		s1++;
	len_s1 = ft_strlen((char *)s1);
	while (ft_strchr(set, s1[len_s1]) && len_s1 != 0)
		len_s1--;
	return (ft_substr((char *)s1, 0, len_s1 + 1));
}
/*
	int	main(void)
{
	ft_strtrim("cbacxcdabcxxacxacab", "abc");
}

 15 char    *ft_strtrim(const char *s1, char const *set)
 16 {
 17
 18     size_t  i;
 19     size_t  f;
 20     size_t  j;
 21     size_t  start;
 22     size_t  end;
 23
 24     i = 0;
 25     f = ft_strlen(s1);
 26     start = 0;
 27     end = 0;
 28     while (s1[i] != '\0' && start == '\0')
 29     {
 30         j = 0;
 31         while (set[j] != '\0' && set[j] != s1[i])
 32             j++;
 33         if (set[j] == '\0')
 34             start = i;
 35         i++;
 36     }
 37     while (f >= 0 && end == '\0')
 38     {
 39         j = 0;
 40         while (set[j] != '\0' && set[j] != s1[f - 1])
 41             j++;
 42         if (set[j] == '\0')
 43             end = (f - 1);
 44         f--;
 45     }
 46     return ((char *) s1);
 47 }			
*/
