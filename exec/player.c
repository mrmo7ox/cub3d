/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-oua <moel-oua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 16:31:38 by moel-oua          #+#    #+#             */
/*   Updated: 2025/07/25 14:20:35 by moel-oua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"


int	player_move(int keycode, t_main *main)
{
	printf("keycode = %d\n",keycode);
	if(124 == keycode)
		main->p->x  += 0.3;
	else if(123 == keycode)		
		main->p->x  -= 0.3;
	else if(125 == keycode)
		main->p->y  += 0.3;
	else if(126 == keycode)
		main->p->y  -= 0.3;
	draw(main);
	return (0);
}
void	draw_player(t_main *main)
{
	draw_sq(main->img,main->p->x * 10, main->p->y * 10, 10, 0x000000);
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
				main->p->x = x;
				main->p->y = y;
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
	plr->radius = 0;
	plr->turn_direction = 0;
	plr->walk_direction = 0;
	plr->rotation_angle = PI / 2;
	plr->moving_speed = 3.0;
	plr->rotation_speed = 3 * (PI / 180); 
	main->p = plr;
	if(!addplrcord(main))
		return (false);
	return (true);
}