/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschmidt <tschmidt@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 17:12:58 by tschmidt          #+#    #+#             */
/*   Updated: 2021/11/23 17:50:22 by tschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static char	lower_case_helper(unsigned long n)
{
	char	c;

	if (n < 10)
		c = n + 48;
	else
		c = n + 87;
	return (c);
}

static char	upper_case_helper(unsigned long n)
{
	char	c;

	if (n < 10)
		c = n + 48;
	else
		c = n + 55;
	return (c);
}

int	print_lower_case_hex(unsigned long n)
{
	char	c[100];
	int		i;
	int		count;
	int		remainder;

	i = 0;
	count = 0;
	while (n > 15)
	{
		remainder = n % 16;
		c[i] = lower_case_helper(remainder);
		i++;
		n = n / 16;
	}
	c[i] = lower_case_helper(n);
	i++;
	while (i > 0)
	{
		i--;
		count += print_char(c[i]);
	}
	return (count);
}

int	print_upper_case_hex(unsigned int n)
{
	char	c[11];
	int		i;
	int		count;
	int		remainder;

	i = 0;
	count = 0;
	while (n > 15)
	{
		remainder = n % 16;
		c[i] = upper_case_helper(remainder);
		i++;
		n = n / 16;
	}
	c[i] = upper_case_helper(n);
	i++;
	while (i > 0)
	{
		i--;
		count += print_char(c[i]);
	}
	return (count);
}

int	print_pointer(unsigned long p)
{
	int	count;

	count = 0;
	count += write (1, "0x", 2);
	count += print_lower_case_hex(p);
	return (count);
}
