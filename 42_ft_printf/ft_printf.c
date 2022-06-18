/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschmidt <tschmidt@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 06:29:09 by tschmidt          #+#    #+#             */
/*   Updated: 2021/11/23 17:50:52 by tschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	create_print(va_list args, int i, const char *str)
{
	int				char_count_temp;

	char_count_temp = 0;
	if (str[i] == 'c')
		char_count_temp += print_char(va_arg(args, int));
	else if (str[i] == 's')
		char_count_temp += print_string(va_arg(args, char *));
	else if (str[i] == 'p')
		char_count_temp += print_pointer((unsigned long)va_arg(args, void *));
	else if (str[i] == 'i' || str[i] == 'd')
		char_count_temp += print_integer(va_arg(args, int));
	else if (str[i] == 'u')
		char_count_temp += print_unsigned_int(va_arg(args, unsigned int));
	else if (str[i] == 'x')
		char_count_temp += print_lower_case_hex(va_arg(args, unsigned int));
	else if (str[i] == 'X')
		char_count_temp += print_upper_case_hex(va_arg(args, unsigned int));
	else if (str[i] == '%')
		char_count_temp += write(1, "%", 1);
	return (char_count_temp);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		printed_chars_count;
	va_list	args;

	va_start(args, format);
	i = 0;
	printed_chars_count = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			printed_chars_count += create_print(args, i, format);
		}
		else
			printed_chars_count += write(1, &format[i], 1);
		i++;
	}
	va_end(args);
	return (printed_chars_count);
}
