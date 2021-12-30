/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschmidt <tschmidt@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 12:05:49 by tschmidt          #+#    #+#             */
/*   Updated: 2021/06/23 11:00:08 by tschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*new;

	i = 0;
	j = 0;
	new = (char *) malloc ((sizeof * s1) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!new)
		return (0);
	while (s1[i])
	{
		new[j] = s1[i];
		j++;
		i++;
	}
	i = 0;
	while (s2[i])
	{
		new[j] = s2[i];
		j++;
		i++;
	}
	new[j] = 0;
	return (new);
}
