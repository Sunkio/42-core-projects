/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschmidt <tschmidt@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 12:17:00 by tschmidt          #+#    #+#             */
/*   Updated: 2021/06/08 09:20:25 by tschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*cpy_dst;
	const char	*cpy_src;

	if ((dst == src) || n == 0)
		return (dst);
	if (!dst && !src)
		return (0);
	cpy_dst = (char *)dst;
	cpy_src = (const char *)src;
	while (n--)
		cpy_dst[n] = cpy_src[n];
	return (dst);
}
