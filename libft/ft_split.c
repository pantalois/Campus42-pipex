/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loigonza <loigonza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 11:24:32 by loigonza          #+#    #+#             */
/*   Updated: 2024/05/21 11:09:12 by loigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_word(char const *s, char c)
{
	int	i;
	int	cont;

	i = 0;
	cont = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
		{
			i++;
		}
		if (s[i])
		{
			cont++;
		}
		while (s[i] && s[i] != c)
		{
			i++;
		}
	}
	return (cont);
}

static char	**ft_free_malloc(char **str, size_t j)
{
	size_t	i;

	i = 0;
	while (i < j)
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		i;
	int		j;
	int		start;

	res = (char **)malloc(sizeof(char *) * (ft_count_word(s, c) + 1));
	if (res == NULL)
		return (NULL);
	i = 0;
	j = 0;
	start = 0;
	while (s[i] != '\0')
	{
		if (i > 0 && s[i] != c && s[i - 1] == c)
			start = i;
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
		{
			res[j++] = ft_substr(s, start, i - start + 1);
			if (res[j - 1] == NULL)
				return (ft_free_malloc(res, j - 1));
		}
		i++;
	}
	res[j] = NULL;
	return (res);
}
/*
int	main(void)
{
	char s[] = "hola,    que, tal";
	char c = ',';
	int i = 0;
	printf("escribe esto:%d", ft_count_word(s, c));
	char **res = ft_split(s, c);
	while (res[i])
	{
		printf("%s\n",res[i]);
		i++;

	}
}
*/
/*
int main(void)
{
	char const *s = "    hola   mundo   hola   ";
	char	c = ' ';
	char	**array;
	int		i = 0;

	array = ft_split(s,c);
	while (array[i] != NULL)
	{
		printf("%s\n",array[i]);
		i++;
	}

	ft_free_malloc(array, i);
	return (0);
}
*/
