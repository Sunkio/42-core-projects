/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschmidt <tschmidt@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 13:02:06 by tschmidt          #+#    #+#             */
/*   Updated: 2021/06/05 09:09:28 by tschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	c[12];
	int		i;

	i = 0;
	if (n == -2147483648)
		ft_putstr_fd("-2147483648", fd);
	if (n < 0 && n > -2147483648)
	{
		write(fd, "-", 1);
		n = -n;
	}
	if (n >= 0 && n <= 9)
		ft_putchar_fd(n + 48, fd);
	if (n >= 10)
	{
		i++;
		c[i] = n % 10 + 48;
		n = n / 10;
		ft_putnbr_fd(n, fd);
	}
	if (i > 0)
	{
		ft_putchar_fd(c[i], fd);
		i--;
	}
}
