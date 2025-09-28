/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabounna <yabounna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 13:51:17 by moel-oua          #+#    #+#             */
/*   Updated: 2025/09/28 14:06:22 by yabounna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

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
				main->p->x = x + 0.5;
				main->p->y = y + 0.5;
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
	main->p->height = 1;
	main->p->width = 1;
	main->p->size = main->p->height * main->p->width;
	main->p->walk_speed = 0.08;
	main->p->turn_speed = 2 * (M_PI / 180);
	return (true);
}

void	set_player_angle(t_main *main)
{
	char	player;

	player = main->map->player;
	if (player == 'S')
		main->p->angle_de_rotation = M_PI / 2;
	else if (player == 'E')
		main->p->angle_de_rotation = 0;
	else if (player == 'N')
		main->p->angle_de_rotation = (3 * M_PI) / 2;
	else if (player == 'W')
		main->p->angle_de_rotation = M_PI;
}
