/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-oua <moel-oua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 21:05:07 by moel-oua          #+#    #+#             */
/*   Updated: 2025/09/14 10:32:37 by moel-oua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

char	*ft_strdup(const char *source, t_main *main)
{
	char	*dup;
	int		len;

	if (!source)
		return (NULL);
	len = ft_strlen(source);
	dup = ft_malloc(main, sizeof(char) * (len + 1));
	if (dup == NULL)
		return (NULL);
	ft_memcpy(dup, source, len);
	dup[len] = '\0';
	return (dup);
}

static char	*ft_join(char *checkpoint, char *next, int read_bytes, t_main *main)
{
	next[read_bytes] = '\0';
	checkpoint = ft_strjoin(checkpoint, next, main);
	return (checkpoint);
}

static char	*ft_read_until_newline(int fd, char *checkpoint, t_main *main)
{
	char	*next;
	ssize_t	read_bytes;

	next = NULL;
	while (!ft_strchr(checkpoint, '\n'))
	{
		next = ft_malloc(main, 2);
		if (!next)
			return (checkpoint = NULL, NULL);
		read_bytes = read(fd, next, 1);
		if (read_bytes <= 0)
		{
			if (read_bytes < 0)
				return (checkpoint = NULL, NULL);
			break ;
		}
		checkpoint = ft_join(checkpoint, next, read_bytes, main);
		if (checkpoint == NULL)
			return (NULL);
		next = NULL;
	}
	return (checkpoint);
}

char	*gnl(int fd, t_main *main)
{
	static char	*checkpoint;
	char		*line;
	int			len;

	if (fd < 0)
		return (NULL);
	if (!ft_strchr(checkpoint, '\n'))
		checkpoint = ft_read_until_newline(fd, checkpoint, main);
	if (!checkpoint)
		return (NULL);
	len = 0;
	while (checkpoint[len] != '\n' && checkpoint[len] != '\0')
		len++;
	if (checkpoint[len] == '\n')
		len++;
	line = ft_substr(checkpoint, 0, len, main);
	if (!line)
		return (checkpoint = NULL, NULL);
	checkpoint = ft_substr(checkpoint, len, (ft_strlen(checkpoint) - len),
			main);
	return (line);
}
