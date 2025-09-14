/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-oua <moel-oua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 17:03:57 by moel-oua          #+#    #+#             */
/*   Updated: 2025/09/14 12:01:52 by moel-oua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

char	*formating(char *path, t_main *main)
{
	int	start;
	int	end;

	start = 0;
	end = ft_strlen(path) - 1;
	while (ft_whitespaces(path[start]) && (path[start] != '\0'))
		start++;
	while (end > 0 && ft_whitespaces(path[end]) && (path[end] != '\0'))
		end--;
	if (start <= end)
	{
		path = ft_substr(path, start, (end - start) + 1, main);
		if (!path)
		{
			ft_putstr_fd("Error\nFormating Malloc Failed\n", 2);
			return (NULL);
		}
	}
	return (path);
}

bool	valid_ext(char *path, t_main *main, char *ext_cmp)
{
	char	*ext;
	size_t	i;

	i = ft_strlen(path) - 1;
	while (i > 0 && path[i] != '.')
		i--;
	if (i + 4 < ft_strlen(path))
	{
		ft_putstr_fd("Error\nInvalid Extension\n", 2);
		return (false);
	}
	ext = ft_substr(path, i, i + 4, main);
	if (!ext)
		return (false);
	if (ft_strcmp(ext_cmp, ext))
	{
		ft_putstr_fd("Error\nInvalid Extension\n", 2);
		return (false);
	}
	return (true);
}

size_t	bfr_size(int fd, t_main *main)
{
	char	*line;
	size_t	c_lines;

	line = gnl(fd, main);
	c_lines = 0;
	while (line)
	{
		c_lines++;
		line = gnl(fd, main);
		if (!line)
			break ;
	}
	return (c_lines);
}

bool	addcnt(int fd, t_main *main)
{
	char	*line;
	size_t	c_lines;

	line = gnl(fd, main);
	if (!line)
		return (false);
	c_lines = 0;
	while (line)
	{
		main->fcnt[c_lines] = line;
		c_lines++;
		line = gnl(fd, main);
		if (!line)
			break ;
	}
	main->fcnt[c_lines] = NULL;
	return (true);
}

bool	file(char **dc, t_main *main)
{
	char	*frmt;

	frmt = formating(dc[1], main);
	if (!frmt && ft_strlen(frmt))
		return (false);
	if (!valid_ext(frmt, main, ".cub"))
		return (false);
	if (!valid_path(frmt, main))
		return (false);
	return (true);
}
