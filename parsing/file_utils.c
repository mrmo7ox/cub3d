/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabounna <yabounna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 10:17:48 by moel-oua          #+#    #+#             */
/*   Updated: 2025/09/28 14:52:10 by yabounna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

static bool	check_file_validity(int *fd)
{
	if (*fd == -1)
	{
		ft_putstr_fd("Error\nFile Doesn't Exist\n", 2);
		return (false);
	}
	return (true);
}

bool	valid_path(char *path, t_main *main)
{
	int		fd;
	size_t	size;

	fd = open(path, O_RDONLY);
	if (!check_file_validity(&fd))
		return (false);
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
