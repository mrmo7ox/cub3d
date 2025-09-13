/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-oua <moel-oua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 16:27:46 by moel-oua          #+#    #+#             */
/*   Updated: 2025/09/13 21:24:37 by moel-oua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	draw_minimap_tile(t_main *main, int x, int y, int ix, int iy)
{
	if (main->map->content[iy][ix] == '0')
		draw_sq(main->img, x, y, main->map->tsize, 0);
	else if (main->map->content[iy][ix] == main->map->player)
		return ;
	else
		draw_sq(main->img, x, y, main->map->tsize, 0xFFFFFF);
}

void	process_minimap_row(t_main *main, int y, int iy)
{
	int	x;
	int	ix;

	x = 0;
	ix = 0;
	while (ix < ft_strlen(main->map->content[iy]))
	{
		draw_minimap_tile(main, x, y, ix, iy);
		x += main->map->tsize;
		ix++;
	}
}

void	minimap(t_main *main)
{
	int	y;
	int	iy;

	y = 0;
	iy = 0;
	while (iy < ft_dplen(main->map->content))
	{
		process_minimap_row(main, y, iy);
		y += main->map->tsize;
		iy++;
	}
}
