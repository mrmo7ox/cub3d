/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-oua <moel-oua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 09:31:50 by moel-oua          #+#    #+#             */
/*   Updated: 2025/08/06 18:15:36 by moel-oua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	set_player_angle(t_main *main)
{
	char	player = main->map->player;
	if (player == 'S')
		main->p->rotation_angle = PI / 2;
	else if (player == 'E')
		main->p->rotation_angle = 0;
	else if (player == 'N')
		main->p->rotation_angle = (3 * PI) / 2;
	else if (player == 'W')
		main->p->rotation_angle = PI;
	main->p->rotation_angle = normalize_angle(main->p->rotation_angle);
}

double	normalize_angle(double angle)
{
	while (angle < 0)
		angle += 2 * PI;
	while (angle >= 2 * PI)
		angle -= 2 * PI;
	return (angle);
}

bool is_wall_at(t_main *main, double x, double y)
{
	int map_x, map_y;
	
	map_x = (int)(x / main->map->tsize);
	map_y = (int)(y / main->map->tsize);
	
	if (map_y < 0 || map_y >= (int)ft_dplen(main->map->content) ||
		map_x < 0 || map_x >= (int)ft_strlen(main->map->content[map_y]))
		return (true);
		
	return (main->map->content[map_y][map_x] == '1');
}

double	cast_ray(t_main *main, double angle)
{
	double	ray_x = main->p->x + (main->p->size / 2.0);  
	double	ray_y = main->p->y + (main->p->size / 2.0);
	double	ray_cos = cos(angle);
	double	ray_sin = sin(angle);
	double	dist = 0;
	double	step = 0.3;
	double	max_dist = main->map->height * main->map->tsize * 2;

	while (dist < max_dist)
	{
		if (is_wall_at(main, ray_x, ray_y) ||
			is_wall_at(main, ray_x + step, ray_y) ||
			is_wall_at(main, ray_x - step, ray_y) ||
			is_wall_at(main, ray_x, ray_y + step) ||
			is_wall_at(main, ray_x, ray_y - step))
			break;
			
		ray_x += ray_cos * step;
		ray_y += ray_sin * step;
		dist += step;
	}
	
	if (dist >= max_dist)
		dist = max_dist;
		
	return (dist);
}