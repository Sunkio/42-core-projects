/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschmidt <tschmidt@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 11:03:37 by tschmidt          #+#    #+#             */
/*   Updated: 2021/06/17 11:57:38 by tschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
	return (ptr);
}
