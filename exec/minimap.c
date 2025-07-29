/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-oua <moel-oua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 15:41:54 by moel-oua          #+#    #+#             */
/*   Updated: 2025/07/29 19:46:53 by moel-oua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"


bool	iswall(t_main *main, double x, double y)
{
	int n_x;
	int n_y;

	n_x = x / main->map->tsize;
	n_y = y / main->map->tsize;
	if((n_y >= 0 && n_y <= (int)ft_dplen(main->map->content))
		&& (n_x >= 0 && n_x <= (int)ft_strlen(main->map->content[n_y])))
	{
		if(main->map->content[n_y][n_x] == '1')
			return (true);
	}
	n_x = (x + (main->p->size)) / main->map->tsize;
	n_y = (y + (main->p->size)) / main->map->tsize;
	draw_pxl(main->img, n_x, n_y, 0xFF0000);
	printf("x = %d y= %d\n", n_x, n_y);
	if((n_y >= 0 && n_y <= (int)ft_dplen(main->map->content))
		&& (n_x >= 0 && n_x <= (int)ft_strlen(main->map->content[n_y])))
	{
		if(main->map->content[n_y][n_x] == '1')
			return (true);
	}
	return (false);
}

void	draw_map(t_main *main)
{
	int	x;
	int y;

	y = 0;
	while(y <= (int)ft_dplen(main->map->content))
	{
		x = 0;
		while(x < (int)ft_strlen(main->map->content[y]))
		{
			if(main->map->content[y][x] == '1')
				draw_sq(main->img, x * main->map->tsize, y * main->map->tsize, main->map->tsize, 0xeb4034 + (10000 * x));
			else
				draw_sq(main->img, x * main->map->tsize, y * main->map->tsize, main->map->tsize, 0xffffff + (10000 * y));
			x++;
		}
		y++;
	}
	return ;
}