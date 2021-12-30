/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschmidt <tschmidt@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 13:00:38 by tschmidt          #+#    #+#             */
/*   Updated: 2021/06/07 09:02:17 by tschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_char_equals_set(char c, const char *set)
{
	while (*set)
		if (c == *set++)
			return (0);
	return (1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*new;

	if (!s1)
		return (0);
	if (!set)
		return (ft_strdup(s1));
	start = 0;
	end = ft_strlen(s1);
	while (ft_char_equals_set(s1[start], set) == 0)
		start++;
	if (start == ft_strlen(s1))
	{
		new = ft_strdup("");
		if (!new)
			return (0);
		else
			return (new);
	}
	while (ft_char_equals_set(s1[end - 1], set) == 0)
		end--;
	new = ft_substr(s1, start, end - start);
	return (new);
}
