/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschmidt <tschmidt@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 09:09:41 by tschmidt          #+#    #+#             */
/*   Updated: 2021/06/28 11:32:44 by tschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_count_elements(const char *str, char c)
{
	int	i;
	int	elements;

	elements = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i + 1] == c || str[i + 1] == '\0') && (str[i] != c))
			elements++;
		i++;
	}
	return (elements);
}

static void	ft_create_element(char *dest, const char *src, char c)
{
	int	i;

	i = 0;
	while (src[i] != c && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

static int	ft_free_memory(char **str, int size)
{
	while (size--)
		free(str[size]);
	return (-1);
}

static int	ft_create_split(char **split_strings, const char *str, char c)
{
	int		i;
	int		j;
	int		elements;

	elements = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c || str[i] == '\0')
			i++;
		else
		{
			j = 0;
			while (str[i + j] != c && str[i + j] != '\0')
				j++;
			split_strings[elements] = (char *)malloc(sizeof (char) * (j + 1));
			if (split_strings[elements] == 0)
				return (ft_free_memory(split_strings, elements - 1));
			ft_create_element(split_strings[elements], str + i, c);
			i += j;
			elements++;
		}
	}
	return (0);
}

char	**ft_split(const char *str, char c)
{
	char	**split_strings;
	int		elements;

	if (!str)
		return (0);
	elements = ft_count_elements(str, c);
	split_strings = (char **) malloc(sizeof (char *) * (elements + 1));
	if (!split_strings)
		return (0);
	split_strings[elements] = 0;
	if (ft_create_split(split_strings, str, c) == -1)
		return (0);
	return (split_strings);
}
