/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschmidt <tschmidt@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 15:42:50 by tschmidt          #+#    #+#             */
/*   Updated: 2021/11/23 17:50:40 by tschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# include <unistd.h>

int	print_char(char c);
int	print_string(char *s);
int	print_integer(int n);
int	print_unsigned_int(unsigned int n);
int	print_lower_case_hex(unsigned long x);
int	print_upper_case_hex(unsigned int x_upper);
int	print_pointer(unsigned long p);

#endif
