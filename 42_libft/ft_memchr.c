/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschmidt <tschmidt@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 15:38:33 by tschmidt          #+#    #+#             */
/*   Updated: 2021/06/19 07:02:04 by tschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*s2;
	unsigned char	c2;
	size_t			i;

	i = 0;
	s2 = (unsigned char *)s;
	c2 = (unsigned char)c;
	while ((i < n) && (s2[i] != c2))
		i++;
	if ((i < n) && (s2[i] == c2))
		return (&s2[i]);
	else
		return (0);
}
