/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loigonza <loigonza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 20:17:20 by loigonza          #+#    #+#             */
/*   Updated: 2024/02/12 16:04:34 by loigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	nbr;
	char	c;

	nbr = (long)n;
	if (nbr < 0)
		write(fd, "-", 1);
	if (nbr / 10 != 0)
	{
		if (nbr < 0)
			ft_putnbr_fd((nbr / 10) * -1, fd);
		else
			ft_putnbr_fd(nbr / 10, fd);
	}
	if (nbr < 0)
		c = (((nbr % 10) * -1) + '0');
	else
		c = ((nbr % 10) + '0');
	write(fd, &c, 1);
	return ;
}
/*
int main(void)
{
	int	num = -1;
	ft_putnbr_fd(num, 1);
}
*/
