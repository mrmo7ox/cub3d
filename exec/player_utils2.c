/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabounna <yabounna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 21:29:40 by moel-oua          #+#    #+#             */
/*   Updated: 2025/09/28 14:06:22 by yabounna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

bool	should_process_move(clock_t *last_time)
{
	clock_t	current_time;

	current_time = clock();
	if (current_time - *last_time < CLOCKS_PER_SEC / 60)
		return (false);
	*last_time = current_time;
	return (true);
}

void	handle_movement_keys(t_main *main, double *move_step_x,
		double *move_step_y, double vitesse_mvt)
{
	if (main->keys->w)
	{
		*move_step_x += cos(main->p->angle_de_rotation) * vitesse_mvt;
		*move_step_y += sin(main->p->angle_de_rotation) * vitesse_mvt;
	}
	if (main->keys->s)
	{
		*move_step_x -= cos(main->p->angle_de_rotation) * vitesse_mvt;
		*move_step_y -= sin(main->p->angle_de_rotation) * vitesse_mvt;
	}
	if (main->keys->a)
	{
		*move_step_x += sin(main->p->angle_de_rotation) * vitesse_mvt;
		*move_step_y -= cos(main->p->angle_de_rotation) * vitesse_mvt;
	}
	if (main->keys->d)
	{
		*move_step_x -= sin(main->p->angle_de_rotation) * vitesse_mvt;
		*move_step_y += cos(main->p->angle_de_rotation) * vitesse_mvt;
	}
}

void	handle_rotation_keys(t_main *main)
{
	if (main->keys->l)
		main->p->angle_de_rotation -= main->p->turn_speed;
	if (main->keys->r)
		main->p->angle_de_rotation += main->p->turn_speed;
	main->p->angle_de_rotation = normalize_angle(main->p->angle_de_rotation);
}

void	handle_exit_key(t_main *main)
{
	if (main->keys->exit)
		close_win(main);
}

int	player_move(t_main *main)
{
	double			move_step_x;
	double			move_step_y;
	double			vitesse_mvt;
	static clock_t	last_time = 0;

	move_step_x = 0;
	move_step_y = 0;
	vitesse_mvt = main->p->walk_speed;
	if (!should_process_move(&last_time))
		return (0);
	handle_movement_keys(main, &move_step_x, &move_step_y, vitesse_mvt);
	set_if_not_wall(main, main->p->x + move_step_x, main->p->y + move_step_y);
	handle_rotation_keys(main);
	draw(main);
	handle_exit_key(main);
	return (0);
}
