/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-oua <moel-oua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 13:51:17 by moel-oua          #+#    #+#             */
/*   Updated: 2025/09/14 14:02:49 by moel-oua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

bool	is_wall(t_main *main, double new_x, double new_y)
{
	int	map_width;
	int	map_height;
	int	top_left_x;
	int	top_left_y;

	map_width = ft_strlen(main->map->content[0]);
	map_height = ft_dplen(main->map->content);
	top_left_x = (int)floor(new_x / main->map->tsize);
	top_left_y = (int)floor(new_y / main->map->tsize);
	if (top_left_x < 0 || top_left_x >= map_width || top_left_y < 0
		|| top_left_y >= map_height)
		return (true);
	if (main->map->content[top_left_y][top_left_x] == '1')
		return (true);
	return (false);
}

bool	player_pos(t_main *main)
{
	int	x;
	int	y;

	y = 0;
	while (main->map->content[y])
	{
		x = 0;
		while (main->map->content[y][x])
		{
			if (main->map->content[y][x] == main->map->player)
			{
				main->p->x = x;
				main->p->y = y;
				return (true);
			}
			x++;
		}
		y++;
	}
	return (false);
}

bool	init_player(t_main *main)
{
	t_plr	*p;

	p = ft_malloc(main, sizeof(t_plr));
	if (!p)
		return (false);
	main->p = p;
	if (!player_pos(main))
		return (false);
	set_player_angle(main);
	main->p->height = 5;
	main->p->width = 5;
	main->p->size = main->p->height * main->p->width * MINIMAP_SCALE;
	main->p->turn_direction = 0;
	main->p->walk_direction = 0;
	main->p->walk_speed = 0.08;
	main->p->turn_speed = 2 * (M_PI / 180);
	return (true);
}

void	draw_player(t_main *main)
{
	t_square_params	sq_params;

	sq_params.size = main->p->size / 2;
	sq_params.start_x = main->p->x * main->map->tsize;
	sq_params.start_y = main->p->y * main->map->tsize;
	sq_params.color = 0xfc0398;
	draw_sq(main->img, &sq_params);
}

void	set_player_angle(t_main *main)
{
	char	player;

	player = main->map->player;
	if (player == 'S')
		main->p->rotation_angle = M_PI / 2;
	else if (player == 'E')
		main->p->rotation_angle = 0;
	else if (player == 'N')
		main->p->rotation_angle = (3 * M_PI) / 2;
	else if (player == 'W')
		main->p->rotation_angle = M_PI;
}
