/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschmidt <tschmidt@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 14:19:02 by tschmidt          #+#    #+#             */
/*   Updated: 2021/06/17 12:20:34 by tschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*cpy_dst;
	const unsigned char	*cpy_src;
	unsigned char		cpy_end;
	size_t				i;

	cpy_dst = (unsigned char *) dst;
	cpy_src = (const unsigned char *) src;
	cpy_end = (unsigned char) c;
	i = 0;
	while (i < n)
	{
		cpy_dst[i] = cpy_src[i];
		if (cpy_src[i] == cpy_end)
			return (dst + i + 1);
		i++;
	}
	return (0);
}
