/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschmidt <tschmidt@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 18:47:54 by tschmidt          #+#    #+#             */
/*   Updated: 2021/06/20 13:35:21 by tschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_find_string_length(long n)
{
	size_t	length;

	length = 0;
	if (n < 0)
	{
		length++;
		n = -n;
	}
	while (n >= 1)
	{
		length++;
		n /= 10;
	}
	return (length);
}

static char	*ft_create_string(char *string, long nbr, int string_length)
{
	int	is_negative;

	is_negative = 0;
	if (nbr != 0)
		string = malloc(sizeof(char) * (string_length + 1));
	else
		return (string = ft_strdup("0"));
	if (!string)
		return (0);
	if (nbr < 0)
	{
		is_negative++;
		nbr = -nbr;
	}
	string[string_length] = '\0';
	while (--string_length)
	{
		string[string_length] = (nbr % 10) + '0';
		nbr /= 10;
	}
	if (is_negative == 1)
		string[0] = '-';
	else
		string[0] = (nbr % 10) + '0';
	return (string);
}

char	*ft_itoa(int n)
{
	int		string_length;
	char	*string;
	long	nbr;

	nbr = n;
	string_length = ft_find_string_length(nbr);
	string = 0;
	string = ft_create_string(string, nbr, string_length);
	if (!string)
		return (0);
	return (string);
}
