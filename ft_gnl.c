/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztune <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 13:35:18 by ztune             #+#    #+#             */
/*   Updated: 2021/08/20 13:35:20 by ztune            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	gnl_after(char **after0, char **after1, char **line, int before)
{
	*line = NULL;
	if (*after0 == NULL)
		return (before);
	if (*after1 == NULL)
		*after1 = *after0;
	before = gnl_strchr_length(*after1, '\n');
	if (before >= 0)
	{
		(*after1)[before] = '\0';
		*line = ft_strdup(*after1);
		*after1 += (before + 1);
	}
	if (before == -1)
	{
		*line = ft_strdup(*after1);
		*after1 = NULL;
	}
	if (before == -1 || *line == NULL)
	{
		free(*after0);
		*after0 = NULL;
	}
	if (*line == NULL)
		return (-2);
	return (before);
}

static int	gnl_prestart(int fd, char **buf, int *bytes, char **line)
{
	if (fd < 0 || GNL_BUFF_SIZE <= 0 || line == NULL)
	{
		return (-1);
	}
	*buf = malloc(sizeof(char) * (GNL_BUFF_SIZE + 1));
	if (*buf == NULL)
	{
		return (-1);
	}
	*bytes = 1;
	return (1);
}

static int	gnl_return(int bytes, char *line, int before, char *after)
{
	if (bytes == -1 || (bytes > 0 && !line) || (before >= 0 && !after))
	{
		return (-1);
	}
	if (bytes == 0)
	{
		return (0);
	}
	return (1);
}

int	get_next_line(int fd, char **line, char **after)
{
	char		*buf;
	int			bytes;
	int			before;
	static char	*after_tmp;

	if (gnl_prestart(fd, &buf, &bytes, line) == -1)
		return (-1);
	before = gnl_after(after, &after_tmp, line, -1);
	while (before == -1 && bytes > 0)
	{
		bytes = read(fd, buf, GNL_BUFF_SIZE);
		if (bytes != -1)
		{
			buf[bytes] = '\0';
			before = gnl_strchr_length(buf, '\n');
			if (before >= 0)
			{
				buf[before] = '\0';
				*after = ft_strdup(&buf[before + 1]);
			}
			*line = gnl_strjoin(line, buf, &before);
		}
	}
	free(buf);
	return (gnl_return(bytes, *line, before, *after));
}
