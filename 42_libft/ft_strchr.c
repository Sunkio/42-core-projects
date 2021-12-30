/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschmidt <tschmidt@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 15:52:16 by tschmidt          #+#    #+#             */
/*   Updated: 2021/06/19 20:45:17 by tschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
