/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loigonza <loigonza@student.42carcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 10:59:24 by loigonza          #+#    #+#             */
/*   Updated: 2024/04/16 12:53:02 by loigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9' && str[i] != '\0')
	{
		result = result * 10 + (str[i] - 48);
		i++;
	}
	result *= sign;
	return (result);
}
/*
#include <stdlib.h>

int	main(void)
{
	int h = ft_atoi("   asd-++-+-+-435647654asda    874wdcdsc");
	int g = atoi("    asd-++-+-+-435647654asda    874wdcdsc");
	printf("%d\n", h);
	printf("%d\n", g);
}
*/
