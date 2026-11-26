/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabouayy <yabouayy@student.1337.ma>        +#+  +:+       +#+        */
/*                                                + +#+#+#+#+#+ +#+           */
/*   Created: 2026/11/26 12:50:50 by yabouayy          #+#    #+#             */
/*   Updated: 2026/11/26 12:50:50 by yabouayy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_until_newline(char *line, int fd)
{
	char	*buf;
	ssize_t	bytes_read;

	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (free(line), NULL);
	bytes_read = 1;
	while (!has_new_line(line) && bytes_read > 0)
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read < 0)
			return (free(buf), free(line), NULL);
		buf[bytes_read] = '\0';
		line = ft_strjoin_free(line, buf);
		if (!line)
			return (free(buf), NULL);
	}
	free(buf);
	if (!*line)
		return (free(line), NULL);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*line;
	char		*ret_line;
	char		*temp;
	size_t		i;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = read_until_newline(line, fd);
	if (!line)
		return (NULL);
	i = find_new_line(line);
	ret_line = ft_substr(line, 0, i);
	temp = ft_substr(line, i, ft_strlen(line) - i);
	free(line);
	line = temp;
	if (!ret_line || !line)
	{
		free(ret_line);
		free(line);
		line = NULL;
		return (NULL);
	}
	return (ret_line);
}