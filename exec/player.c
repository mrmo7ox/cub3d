/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-oua <moel-oua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 16:31:38 by moel-oua          #+#    #+#             */
/*   Updated: 2025/07/30 14:54:39 by moel-oua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"


int	player_move(t_main *main)
{
	double	hx = ((main->p->moving_speed) * cos(main->p->rotation_angle)) + main->p->x;
	double	hy = ((main->p->moving_speed) * sin(main->p->rotation_angle)) + main->p->y;
	double	vx = ((main->p->moving_speed) * sin(main->p->rotation_angle)) + main->p->x;
	double	vy = ((main->p->moving_speed) * cos(main->p->rotation_angle)) + main->p->y;
	if(main->keys->d && !iswall(main, vx, vy))
	{
		main->p->y  += (main->p->moving_speed) * cos(main->p->rotation_angle);
		main->p->x  += (main->p->moving_speed) * sin(main->p->rotation_angle);	
	}
	if(main->keys->a && !iswall(main, vx, vy))
	{
		main->p->y  -= (main->p->moving_speed) * cos(main->p->rotation_angle);
		main->p->x  -= (main->p->moving_speed) * sin(main->p->rotation_angle);			
	}
	if(main->keys->s && !iswall(main, hx, hy))
	{
		main->p->y  -= (main->p->moving_speed) * sin(main->p->rotation_angle);
		main->p->x  -= (main->p->moving_speed) * cos(main->p->rotation_angle);	
	}
	if(main->keys->w && !iswall(main, hx, hy))
	{
		main->p->y  += (main->p->moving_speed) * sin(main->p->rotation_angle);
		main->p->x  += (main->p->moving_speed) * cos(main->p->rotation_angle);	
	}
	if(main->keys->l)
		main->p->rotation_angle += main->p->rotation_speed;
	if(main->keys->r)
		main->p->rotation_angle -= main->p->rotation_speed;
	// if (main->p->rotation_angle < 0)
	// 	main->p->rotation_angle += 2 * M_PI;
	// if (main->p->rotation_angle > 2 * M_PI)
	// 	main->p->rotation_angle -= 2 * M_PI;
	if(main->keys->exit)
		close_win(main);
	draw(main);
	return (0);
}
double	norm_angle(double angle)
{
	angle = fmod(angle, 2.0 * M_PI);
	if (angle < 0)
		angle += 2.0 * M_PI;
	return (angle);
}

void	draw_player(t_main *main)
{
	int i;
	draw_sq(main->img, main->p->x ,	main->p->y, main->p->size, 0xffffff);
	// draw_line(main, (main->p->x + main->p->size / 2),
	// (main->p->y + main->p->size / 2), 40,
	// main->p->rotation_angle ,0x2600ff);
	// i = norm_angle(main->p->rotation_angle - FOV / 2.0);
	ray_castring(main, main->p->rotation_angle , main->p->x + main->p->size / 2, main->p->y + main->p->size / 2);

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
				main->p->x = x * main->map->tsize;
				main->p->y = y * main->map->tsize;
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
	plr->size =  main->map->tsize / 4;
	plr->steps = (main->map->tsize / plr->size);
	plr->radius = 0;
	plr->turn_direction = 0;
	plr->walk_direction = 0;
	plr->rotation_angle = M_PI;
	plr->moving_speed = plr->steps * 0.08;
	plr->rotation_speed = 3 * (M_PI / 180);
	main->p = plr;
	if(!addplrcord(main))
		return (false);
	set_player_angle(main);
	return (true);
}