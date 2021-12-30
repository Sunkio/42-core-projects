/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschmidt <tschmidt@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 10:15:29 by tschmidt          #+#    #+#             */
/*   Updated: 2021/06/07 10:22:37 by tschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f) (unsigned int, char))
{
	unsigned int	i;
	char			*str;

	i = 0;
	if (s == 0 || f == 0)
		return (0);
	str = (char *) malloc (sizeof (char) * (ft_strlen(s) + 1));
	if (str == 0)
		return (0);
	while (s[i])
	{
		str[i] = (f(i, s[i]));
		i++;
	}
	str[i] = 0;
	return (str);
}
