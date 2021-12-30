/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschmidt <tschmidt@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 13:37:59 by tschmidt          #+#    #+#             */
/*   Updated: 2021/10/07 09:53:16 by tschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*save_next_line_start(char *buf)
{
	char	*next_line_start;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!buf)
		return (0);
	while (buf && buf[i] != '\n')
		i++;
	i++;
	next_line_start = (char *) ft_calloc ((ft_strlen(buf) - i + 1),
			sizeof(char));
	while (buf[i] != '\0')
	{
		next_line_start[j] = buf[i];
		i++;
		j++;
	}
	next_line_start[j] = 0;
	return (next_line_start);
}

static char	*create_new_buf(int ret, char *buf)
{
	char	*tmp;
	int		i;

	i = 0;
	if (ret == BUFFER_SIZE || (ft_strchr(buf, '\n') != 0))
	{
		tmp = save_next_line_start(buf);
		while (i <= BUFFER_SIZE)
		{
			buf[i] = 0;
			i++;
		}
		ft_memmove(buf, tmp, ft_strlen(tmp));
		free (tmp);
	}
	else
	{		
		while (i <= BUFFER_SIZE)
		{
			buf[i] = 0;
			i++;
		}
	}
	return (buf);
}

static char	*join_strings(char *current_line, char *buf)
{
	char	*joined_str;
	int		total_str_len;

	total_str_len = ft_strlen(current_line) + ft_strlen(buf);
	joined_str = ft_strjoin(current_line, buf, total_str_len);
	free (current_line);
	return (joined_str);
}

static char	*create_line(int ret, int fd, char *buf, char *current_line)
{
	if (buf[0] != '\0')
		current_line = join_strings(current_line, buf);
	if (ft_strchr(current_line, '\n') == 0)
	{
		while ((ft_strchr(buf, '\n') == 0) && (ret == BUFFER_SIZE))
		{	
			ret = read(fd, buf, BUFFER_SIZE);
			if (buf[0] == '\0')
			{
				free (current_line);
				return (0);
			}
			buf[ret] = '\0';
			current_line = join_strings(current_line, buf);
		}
	}
	buf = create_new_buf(ret, buf);
	if ((buf[0] == '\0') && (current_line[0] == '\0'))
	{
		free (current_line);
		return (0);
	}
	return (current_line);
}

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	char		*current_line;
	int			ret;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0)
		return (0);
	ret = BUFFER_SIZE;
	current_line = (char *)ft_calloc(1, sizeof(char));
	return (create_line(ret, fd, buf, current_line));
}
