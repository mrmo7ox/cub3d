/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabounna <yabounna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 16:37:20 by moel-oua          #+#    #+#             */
/*   Updated: 2025/09/28 09:27:04 by yabounna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

bool	getmap(int last, t_main *main)
{
	int	end;
	int	i;

	i = 0;
	end = end_map(main);
	if (end <= last)
		return (false);
	main->map->content = ft_malloc(main, ((end - last) + 2) * sizeof(char *));
	if (!main->map->content)
		return (false);
	while (end >= last)
	{
		main->map->content[i] = ft_rmlstspmap(main->fcnt[last], main);
		i++;
		last++;
	}
	main->map->content[i] = NULL;
	return (true);
}

bool	validchr(char c, t_main *main)
{
	if (c == '0' || c == '1' || c == ' ')
		return (true);
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
	{
		if (main->map->player)
			return (false);
		main->map->player = c;
		return (true);
	}
	return (false);
}

bool	vld_map(t_main *main)
{
	int		x;
	int		y;
	char	**map;

	map = main->map->content;
	x = 0;
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			if (!validchr(map[x][y], main))
				return (false);
			if (map[x][y] == '0')
			{
				if (!map_checker(map, x, y))
					return (false);
			}
			y++;
		}
		x++;
	}
	return (true);
}

bool	init_map(int last, t_main *main)
{
	int	i;

	i = 0;
	main->map = ft_malloc(main, sizeof(t_map));
	main->map->player = 0;
	if (!main->map)
		return (false);
	if (!getmap(last, main))
		return (false);
	if (!main->map->content)
		return (false);
	if (!vld_map(main))
		return (false);
	if (!main->map->player)
		return (false);
	return (true);
}

bool	parsemap(int last, t_main *main)
{
	while (is_allwspace(main->fcnt[last]))
		last++;
	if (!init_map(last, main))
		return (false);
	return (true);
}
