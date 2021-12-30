/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschmidt <tschmidt@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 17:22:41 by tschmidt          #+#    #+#             */
/*   Updated: 2021/05/28 14:06:21 by tschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int	neg;
	int	i;
	int	conv;

	neg = 0;
	i = 0;
	conv = 0;
	while (*str == ' ' || *str == '\n' || *str == '\f' || *str == '\r'
		|| *str == '\t' || *str == '\v')
		str++;
	if (*str == '-')
		neg = 1;
	if (*str == '-' || *str == '+')
		str++;
	while (str[i] >= 48 && str[i] <= 57)
	{
		conv = (str[i] - 48) + (10 * conv);
		i++;
	}
	if (neg == 1)
		conv = conv * -1;
	return (conv);
}
