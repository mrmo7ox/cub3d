/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-oua <moel-oua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 16:31:38 by moel-oua          #+#    #+#             */
/*   Updated: 2025/07/29 19:47:19 by moel-oua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"


int	player_move(int keycode, t_main *main)
{
	if(D == keycode && !iswall(main, main->p->x + main->p->steps, main->p->y))
		main->p->x  += main->p->steps;
	else if(A == keycode && !iswall(main, main->p->x - main->p->steps, main->p->y))		
		main->p->x  -= main->p->steps;
	else if(S == keycode && !iswall(main, main->p->x, main->p->y + main->p->steps))
		main->p->y  += main->p->steps;
	else if(W == keycode && !iswall(main, main->p->x, main->p->y - main->p->steps))
		main->p->y  -= main->p->steps;
	else if(LEFT == keycode)
		main->p->rotation_angle -= 0.5;
	else if(RIGHT == keycode)
		main->p->rotation_angle += 0.5;
	draw(main);
	return (0);
}
void	draw_player(t_main *main)
{
	int i;
	// printf("p y = %f p x = %f\n",main->p->y , main->p->x);
	draw_sq(main->img, main->p->x ,	main->p->y, main->p->size, 0xffffff);
	i = 0;
	while (i <= 60)
	{
		draw_line(main, (main->p->x + main->p->size / 2),
		(main->p->y + main->p->size / 2), 100,
		main->p->rotation_angle + torad(i) ,0x2600ff);
		i++;
	}
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
	plr->steps = main->map->tsize / plr->size;
	printf("%f\n", plr->steps);
	plr->radius = 0;
	plr->turn_direction = 0;
	plr->walk_direction = 0;
	plr->rotation_angle = M_PI;
	plr->moving_speed = 3.0;
	plr->rotation_speed = 3 * (M_PI / 180);
	main->p = plr;
	if(!addplrcord(main))
		return (false);
	return (true);
}