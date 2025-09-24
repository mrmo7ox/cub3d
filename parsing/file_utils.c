/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-oua <moel-oua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 10:17:48 by moel-oua          #+#    #+#             */
/*   Updated: 2025/09/14 12:00:13 by moel-oua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

bool	valid_path(char *path, t_main *main)
{
	int		fd;
	size_t	size;

	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("Error\nFile Doesn't Exist\n", 2);
		return (false);
	}
	size = bfr_size(fd, main);
	if (size == 0)
	{
		close(fd);
		ft_putstr_fd("Error\nEmpty file\n", 2);
		return (false);
	}
	main->fcnt = ft_malloc(main, (size + 1) * sizeof(char *));
	if (!main->fcnt)
		return (close(fd), false);
	close(fd);
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (false);
	if (!addcnt(fd, main))
		return (close(fd), false);
	close(fd);
	return (true);
}
