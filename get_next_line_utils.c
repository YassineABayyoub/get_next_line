/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabouayy <yabouayy@student.1337.ma>        +#+  +:+       +#+        */
/*                                                + +#+#+#+#+#+ +#+           */
/*   Created: 2026/11/26 13:00:02 by yabouayy          #+#    #+#             */
/*   Updated: 2026/11/26 13:00:02 by yabouayy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		++i;
	return (i);
}

int	has_new_line(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == '\n')
			return (1);
		++i;
	}
	return (0);
}

size_t	find_new_line(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != '\n')
		++i;
	if (s[i] == '\n')
		++i;
	return (i);
}

char	*ft_strjoin_free(char *s1, const char *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (free(s1), NULL);
	i = 0;
	j = 0;
	while (s1 && s1[j])
		str[i++] = s1[j++];
	j = 0;
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	free(s1);
	return (str);
}

char	*ft_substr(const char *s, size_t start, size_t len)
{
	char	*sub;
	size_t	len_s;
	size_t	i;

	len_s = ft_strlen(s);
	if (start >= len_s)
		len = 0;
	else if (len > len_s - start)
		len = len_s - start;
	sub = malloc(len + 1);
	if (!sub)
		return (NULL);
	i = 0;
	while (i < len)
	{
		sub[i] = s[start + i];
		++i;
	}
	sub[i] = '\0';
	return (sub);
}