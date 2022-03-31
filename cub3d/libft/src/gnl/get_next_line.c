/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarrell <cdarrell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 10:59:20 by cdarrell          #+#    #+#             */
/*   Updated: 2021/11/19 17:34:51 by cdarrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

static char	*gnl_remainder(char **rem, char	*p_n)
{
	char	*line;
	char	*tmp_rem;

	if (*rem)
	{
		p_n = ft_strchr(*rem, '\n');
		if (p_n)
		{
			tmp_rem = *rem;
			*rem = ft_strdup(p_n + 1);
			p_n = ft_memcpy(p_n, "\n\0", 2);
			line = ft_strdup(tmp_rem);
			free(tmp_rem);
		}
		else
		{
			line = *rem;
			*rem = ((void *)0);
		}
	}
	else
		line = ft_strdup("");
	return (line);
}

static char	*gnl_read(int fd, char *line, char **rem, char *p_n)
{
	char	*tmp;
	char	buf[BUFFER_SIZE + 1];
	int		r;

	r = 1;
	while (!p_n && r && line && !(*rem))
	{
		r = read(fd, buf, BUFFER_SIZE);
		if (r <= 0 && *line == '\0')
		{
			free(line);
			return ((void *)0);
		}
		buf[r] = '\0';
		p_n = ft_strchr(buf, '\n');
		if (p_n)
		{	
			*rem = ft_strdup(p_n + 1);
			p_n = ft_memcpy(p_n, "\n\0", 2);
		}
		tmp = line;
		line = ft_strjoin(line, buf);
		free(tmp);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*remainder;
	char		test_buff[1];
	char		*line;

	if (BUFFER_SIZE <= 0 || fd < 0 || read(fd, test_buff, 0) != 0)
		return ((void *)0);
	line = gnl_remainder(&remainder, ((void *)0));
	line = gnl_read(fd, line, &remainder, ((void *)0));
	return (line);
}
