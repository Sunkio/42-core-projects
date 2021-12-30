/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschmidt <tschmidt@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 10:53:38 by tschmidt          #+#    #+#             */
/*   Updated: 2021/06/19 19:51:24 by tschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	src_length;
	size_t	dst_length;
	size_t	i;
	size_t	j;

	src_length = ft_strlen(src);
	dst_length = ft_strlen(dst);
	i = 0;
	j = dst_length;
	if (dstsize == 0)
		return (src_length);
	if (dstsize < dst_length)
		return (src_length + dstsize);
	else
	{
		while (src[i] && (dst_length + i) < dstsize)
			dst[j++] = src[i++];
		if ((dst_length + i) == dstsize && dst_length < dstsize)
			dst[--j] = '\0';
		else
			dst[j] = '\0';
		return (src_length + dst_length);
	}
}
