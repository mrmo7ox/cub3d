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
	angle = fmod(angle, 2 * PI);
	if (angle < 0)
		angle += 2 * PI;
	return (angle);
}

double	cast_ray(t_main *main, double angle)
{
	double	ray_x = main->p->x + (main->p->size / 2);  
	double	ray_y = main->p->y + (main->p->size / 2);
	double	ray_cos = cos(angle);
	double	ray_sin = sin(angle);
	double	dist = 0;
	double	step = 0.5;
	
	while (dist < (main->map->height * main->map->tsize))
	{
		ray_x += ray_cos * step;
		ray_y += ray_sin * step;
		dist += step;
		int map_x = (int)(ray_x / main->map->tsize);
		int map_y = (int)(ray_y / main->map->tsize);
		if (map_y < 0 || map_y >= (int)ft_dplen(main->map->content) ||
			map_x < 0 || map_x >= (int)ft_strlen(main->map->content[map_y]))
			break;
			
		if (main->map->content[map_y][map_x] == '1')
			break;
	}
	
	return (dist);
}
