/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschmidt <tschmidt@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 13:58:25 by tschmidt          #+#    #+#             */
/*   Updated: 2021/11/26 06:34:42 by tschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static int	negatives_helper(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
	{
		count = print_string("-2147483648");
		return (count);
	}
	if (n < 0 && n > -2147483648)
	{
		count += write(1, "-", 1);
	}
	return (count);
}

int	print_string(char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
	{
		write(1, "(null)", 6);
		i = 6;
		return (i);
	}
	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

int	print_char(char c)
{
	write(1, &c, 1);
	return (1);
}

int	print_integer(int n)
{
	char	c[12];
	int		i;
	int		count;

	i = 0;
	count = 0;
	count += negatives_helper(n);
	if (n < 0)
		n = -n;
	if (n >= 0 && n <= 9)
		count += print_char(n + 48);
	if (n >= 10)
	{
		i++;
		c[i] = n % 10 + 48;
		n = n / 10;
		count += print_integer(n);
	}
	if (i > 0)
	{
		count += print_char(c[i]);
		i--;
	}
	return (count);
}

int	print_unsigned_int(unsigned int n)
{
	char			c[11];
	long long int	i;
	int				count;

	i = 0;
	count = 0;
	if (n <= 9)
		count += print_char(n + 48);
	if (n >= 10)
	{
		i++;
		c[i] = n % 10 + 48;
		n = n / 10;
		count += print_unsigned_int(n);
	}
	if (i > 0)
	{
		count += print_char(c[i]);
		i--;
	}
	return (count);
}
