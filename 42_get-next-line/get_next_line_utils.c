/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschmidt <tschmidt@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 13:37:56 by tschmidt          #+#    #+#             */
/*   Updated: 2021/10/07 08:56:45 by tschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	char	*s2;
	int		size;
	int		i;

	s2 = (char *) s;
	size = ft_strlen(s2);
	i = 0;
	while (i <= size)
	{
		if (s[i] == (char) c)
			return (&s2[i]);
		i++;
	}
	return (0);
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;
	size_t	total_count_size;
	int		i;

	total_count_size = count * size;
	ptr = malloc(total_count_size);
	if (!ptr)
		return (0);
	i = 0;
	while (total_count_size)
	{
		ptr[i] = 0;
		i++;
		total_count_size--;
	}
	return ((void *) ptr);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*dst2;
	char	*src2;

	dst2 = (char *) dst;
	src2 = (char *) src;
	if (dst == src)
		return (dst);
	if (src2 < dst2)
	{
		while (len--)
			*(dst2 + len) = *(src2 + len);
		return (dst);
	}
	while (len--)
		*dst2++ = *src2++;
	return (dst);
}

char	*ft_strjoin(char const *s1, char const *s2, int total_str_len)
{
	size_t	i;
	size_t	j;
	char	*new;

	i = 0;
	j = 0;
	new = (char *) ft_calloc ((total_str_len + 1), sizeof(char));
	if (!new)
		return (0);
	while (s1[i])
	{
		new[j] = s1[i];
		j++;
		i++;
	}
	i = 0;
	while (s2[i] && s2[i] != '\n')
	{
		new[j] = s2[i];
		j++;
		i++;
	}
	if (s2[i] == '\n')
		new[j] = '\n';
	return (new);
}
