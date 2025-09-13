/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-oua <moel-oua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 21:29:40 by moel-oua          #+#    #+#             */
/*   Updated: 2025/09/13 21:38:41 by moel-oua         ###   ########.fr       */
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
		double *move_step_y, double move_speed)
{
	if (main->keys->w)
	{
		*move_step_x += cos(main->p->rotation_angle) * move_speed;
		*move_step_y += sin(main->p->rotation_angle) * move_speed;
	}
	if (main->keys->s)
	{
		*move_step_x -= cos(main->p->rotation_angle) * move_speed;
		*move_step_y -= sin(main->p->rotation_angle) * move_speed;
	}
	if (main->keys->a)
	{
		*move_step_x += sin(main->p->rotation_angle) * move_speed;
		*move_step_y -= cos(main->p->rotation_angle) * move_speed;
	}
	if (main->keys->d)
	{
		*move_step_x -= sin(main->p->rotation_angle) * move_speed;
		*move_step_y += cos(main->p->rotation_angle) * move_speed;
	}
}

void	handle_rotation_keys(t_main *main)
{
	if (main->keys->l)
		main->p->rotation_angle -= main->p->turn_speed;
	if (main->keys->r)
		main->p->rotation_angle += main->p->turn_speed;
	main->p->rotation_angle = normalize_angle(main->p->rotation_angle);
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
	double			move_speed;
	static clock_t	last_time = 0;

	move_step_x = 0;
	move_step_y = 0;
	move_speed = main->p->walk_speed;
	if (!should_process_move(&last_time))
		return (0);
	handle_movement_keys(main, &move_step_x, &move_step_y, move_speed);
	set_if_not_wall(main, main->p->x + move_step_x, main->p->y + move_step_y);
	handle_rotation_keys(main);
	draw(main);
	handle_exit_key(main);
	return (0);
}
