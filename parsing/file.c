/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-oua <moel-oua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 17:03:57 by moel-oua          #+#    #+#             */
/*   Updated: 2025/07/20 10:38:36 by moel-oua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

char *formating(char *path, t_main *main)
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
			ft_putstr_fd("[KO][31] Formating Malloc Failed\n", 2);
			return (NULL);
		}
	}
	return (path);
}


bool	valid_ext(char *path, t_main *main)
{
	char	*ext;
	size_t	i;

	i = 0;
	while(path[i] && path[i] != '.')
		i++;
	if(i == 0 || (i + 4 > ft_strlen(path)))
	{
		ft_putstr_fd("[KO] INVALID MAP EXTENSION\n", 2);
		return (false);
	}
	ext = ft_substr(path, i, i + 4, main);
	if(!ext)
	{
		if(DEBUG)
			ft_putstr_fd("[OK] valid_path < problem on substr to get the extentsion name .cub >\n", 2);
		return (false);
	}
	if(ft_strcmp(".cub", ext))
	{
		ft_putstr_fd("[KO] INVALID MAP EXTENSION\n", 2);
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
	while(line)
	{	
		c_lines++;
		line = gnl(fd, main);
		if(!line)
			break;
	}
	return (c_lines);
}

bool	addcnt(int fd, t_main *main)
{
	char	*line;
	size_t	c_lines;

	line = gnl(fd, main);
	if(!line)
		return (false);
	c_lines = 0;
	while(line)
	{	
		main->fcnt[c_lines] = line;
		c_lines++;
		line = gnl(fd, main);
		if(!line)
			break;
	}
	main->fcnt[c_lines] = NULL;
	return (true);
}

bool	valid_path(char *path, t_main *main)
{
	int		fd;

	fd = open(path, O_RDONLY);
	if(fd == -1)
		return (false);
	main->fcnt  = ft_malloc(main, ((bfr_size(fd, main) + 1) * sizeof(char *)));
	if(!main->fcnt)
		return (false);
	close(fd);
	fd = open(path, O_RDONLY);
	if(fd == -1)
		return (false);
	if (!addcnt(fd, main))
		return (false);
	close(fd);
	return (true);
}

bool	file(char **dc , t_main *main)
{
	char	*frmt;

	frmt = formating(dc[1], main);
	if(!frmt && ft_strlen(frmt))
		return (false);
	if (!valid_ext(frmt, main))
		return (false);
	if (!valid_path(frmt, main))
		return (false);
	return (true);
}
