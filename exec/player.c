/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-oua <moel-oua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 16:31:38 by moel-oua          #+#    #+#             */
/*   Updated: 2025/08/06 18:15:36 by moel-oua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	player_move(t_main *main)
{
	double new_x, new_y;
	
	if (main->keys->w)
	{
		new_x = main->p->x + cos(main->p->rotation_angle) * main->p->moving_speed;
		new_y = main->p->y + sin(main->p->rotation_angle) * main->p->moving_speed;
		move_with_collision(main, new_x, new_y);
	}
	if (main->keys->s)
	{
		new_x = main->p->x - cos(main->p->rotation_angle) * main->p->moving_speed;
		new_y = main->p->y - sin(main->p->rotation_angle) * main->p->moving_speed;
		move_with_collision(main, new_x, new_y);
	}

	if (main->keys->d)
	{
		new_x = main->p->x + sin(main->p->rotation_angle) * main->p->moving_speed;
		new_y = main->p->y - cos(main->p->rotation_angle) * main->p->moving_speed;
		move_with_collision(main, new_x, new_y);
	}

	if (main->keys->a)
	{
		new_x = main->p->x - sin(main->p->rotation_angle) * main->p->moving_speed;
		new_y = main->p->y + cos(main->p->rotation_angle) * main->p->moving_speed;
		move_with_collision(main, new_x, new_y);
	}
	if (main->keys->l)
		main->p->rotation_angle -= main->p->rotation_speed;
	if (main->keys->r)
		main->p->rotation_angle += main->p->rotation_speed;

	main->p->rotation_angle = normalize_angle(main->p->rotation_angle);

	if (main->keys->exit)
		close_win(main);

	draw(main);
	return (0);
}

double	norm_angle(double angle)
{
	angle = fmod(angle, 2.0 * PI);
	if (angle < 0)
		angle += 2.0 * PI;
	return (angle);
}

bool	addplrcord(t_main *main)
{
	int	y;
	int	x;

	y = 0;
	while(y < (int)ft_dplen(main->map->content))
	{
		x = 0;
		while(x < (int)ft_strlen(main->map->content[y]))
		{
			if(main->map->content[y][x] == main->map->player)
			{
				main->p->x = x * main->map->tsize + main->map->tsize/2 - main->p->size/2;
				main->p->y = y * main->map->tsize + main->map->tsize/2 - main->p->size/2;
				return (true);
			}
			x++;
		}
		y++;
	}
	return (true);
}

bool	init_player(t_main *main)
{
	t_plr	*plr;

	plr = ft_malloc(main, sizeof(t_plr));
	if(!plr)
		return (false);
	plr->y = 0;
	plr->x = 0;
	plr->size = main->map->tsize / 3; 
	plr->steps = (main->map->tsize / plr->size);
	plr->radius = plr->size / 2;
	plr->turn_direction = 0;
	plr->walk_direction = 0;
	plr->rotation_angle = PI;
	plr->moving_speed = 0.5;
	plr->rotation_speed = 1 * (PI / 180);
	main->p = plr;
	if(!addplrcord(main))
		return (false);
	set_player_angle(main);
	return (true);
}