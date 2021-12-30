/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschmidt <tschmidt@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 08:44:01 by tschmidt          #+#    #+#             */
/*   Updated: 2021/06/03 09:55:39 by tschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	void	*str;
	size_t	len;

	len = ft_strlen(s1) + 1;
	str = (void *) malloc (len);
	if (!str)
		return (0);
	return (ft_memcpy(str, s1, len));
}
