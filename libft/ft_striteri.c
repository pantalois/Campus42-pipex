/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loigonza <loigonza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 19:21:30 by loigonza          #+#    #+#             */
/*   Updated: 2024/02/06 13:39:15 by loigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int	i;

	i = 0;
	if (!s || !f)
		return ;
	while (s[i] != '\0')
	{
		f(i, &s[i]);
		i++;
	}
}
/*
#include <stdio.h>

void example_function(unsigned int index, char *character)
{
	index = 0;
    *character = 'X';
}

int main(void)
{
    char str[] = "Hello, World!";
	printf("Initial string:  __%s__\n", str);
    ft_striteri(str, example_function);
    printf("Modified string: __%s__\n", str);
    return (0);
}
*/
