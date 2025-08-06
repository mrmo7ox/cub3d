/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collosion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-oua <moel-oua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 00:00:00 by moel-oua          #+#    #+#             */
/*   Updated: 2025/01/15 00:00:00 by moel-oua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

bool	check_collision_at(t_main *main, double x, double y)
{
	int map_x, map_y;
	double radius = main->p->size / 2.0;

	double corners[4][2] = {
		{x - radius, y - radius},  
		{x + radius, y - radius},
		{x - radius, y + radius},
		{x + radius, y + radius}
	};

	for (int i = 0; i < 4; i++)
	{
		map_x = (int)(corners[i][0] / main->map->tsize);
		map_y = (int)(corners[i][1] / main->map->tsize);

		// Bounds check
		if (map_y < 0 || map_y >= (int)ft_dplen(main->map->content) ||
			map_x < 0 || map_x >= (int)ft_strlen(main->map->content[map_y]))
			return (true);

		// Wall check
		if (main->map->content[map_y][map_x] == '1')
			return (true);
	}
	return (false);
}

bool	collision_x(t_main *main, double new_x, double current_y)
{
	return (check_collision_at(main, new_x, current_y));
}

bool	collision_y(t_main *main, double current_x, double new_y)
{
	return (check_collision_at(main, current_x, new_y));
}

void	move_with_collision(t_main *main, double new_x, double new_y)
{
	double current_x = main->p->x;
	double current_y = main->p->y;

	// Try moving in both directions
	if (!check_collision_at(main, new_x, new_y))
	{
		main->p->x = new_x;
		main->p->y = new_y;
		return;
	}

	// Try moving only on X axis (slide along Y walls)
	if (!collision_x(main, new_x, current_y))
	{
		main->p->x = new_x;
		return;
	}

	// Try moving only on Y axis (slide along X walls)
	if (!collision_y(main, current_x, new_y))
	{
		main->p->y = new_y;
		return;
	}

	// Cannot move in any direction, stay in place
}