/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-oua <moel-oua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 15:41:54 by moel-oua          #+#    #+#             */
/*   Updated: 2025/07/24 20:49:40 by moel-oua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

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
				draw_sq(main->img, x * 10, y * 10, 10, 0xeb4034);
			else
				draw_sq(main->img, x * 10, y * 10, 10, 0xffffff);
			x++;
		}
		y++;
	}
	return ;
}