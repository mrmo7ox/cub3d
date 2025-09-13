/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-oua <moel-oua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 21:23:47 by moel-oua          #+#    #+#             */
/*   Updated: 2025/09/13 21:39:34 by moel-oua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	calculate_corners(t_main *main, double new_x, double new_y,
		t_corners *corners)
{
	double	player_size;

	player_size = (double)main->p->height / main->map->tsize;
	corners->top_left_x = (int)floor(new_x);
	corners->top_left_y = (int)floor(new_y);
	corners->top_right_x = (int)floor(new_x + player_size);
	corners->top_right_y = (int)floor(new_y);
	corners->bottom_left_x = (int)floor(new_x);
	corners->bottom_left_y = (int)floor(new_y + player_size);
	corners->bottom_right_x = (int)floor(new_x + player_size);
	corners->bottom_right_y = (int)floor(new_y + player_size);
}

bool	is_within_bounds(int map_width, int map_height, t_corners *corners)
{
	if (corners->top_left_x < 0 || corners->top_left_x >= map_width
		|| corners->top_left_y < 0 || corners->top_left_y >= map_height)
		return (false);
	if (corners->top_right_x < 0 || corners->top_right_x >= map_width
		|| corners->top_right_y < 0 || corners->top_right_y >= map_height)
		return (false);
	if (corners->bottom_left_x < 0 || corners->bottom_left_x >= map_width
		|| corners->bottom_left_y < 0 || corners->bottom_left_y >= map_height)
		return (false);
	if (corners->bottom_right_x < 0 || corners->bottom_right_x >= map_width
		|| corners->bottom_right_y < 0 || corners->bottom_right_y >= map_height)
		return (false);
	return (true);
}

bool	is_not_wall(t_main *main, t_corners *c)
{
	if (main->map->content[c->top_left_y][c->top_left_x] == '1')
		return (false);
	if (main->map->content[c->top_right_y][c->top_right_x] == '1')
		return (false);
	if (main->map->content[c->bottom_left_y][c->bottom_left_x] == '1')
		return (false);
	if (main->map->content[c->bottom_right_y][c->bottom_right_x] == '1')
		return (false);
	return (true);
}

void	set_if_not_wall(t_main *main, double new_x, double new_y)
{
	int			map_width;
	int			map_height;
	t_corners	corners;

	map_width = ft_strlen(main->map->content[0]);
	map_height = ft_dplen(main->map->content);
	calculate_corners(main, new_x, new_y, &corners);
	if (!is_within_bounds(map_width, map_height, &corners))
		return ;
	if (!is_not_wall(main, &corners))
		return ;
	main->p->x = new_x;
	main->p->y = new_y;
}
