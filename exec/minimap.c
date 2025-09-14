/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-oua <moel-oua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 16:27:46 by moel-oua          #+#    #+#             */
/*   Updated: 2025/09/14 10:47:48 by moel-oua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	draw_minimap_tile(t_minimap_data *data)
{
	char			**map;
	t_square_params	sq_params;

	map = data->main->map->content;
	sq_params.start_x = data->x;
	sq_params.start_y = data->y;
	sq_params.size = data->main->map->tsize;
	if (map[data->iy][data->ix] == '0'
		|| map[data->iy][data->ix] == data->main->map->player)
	{
		sq_params.color = 0;
		draw_sq(data->main->img, &sq_params);
	}
	else
	{
		sq_params.color = 0xFFFFFF;
		draw_sq(data->main->img, &sq_params);
	}
}

void	process_minimap_row(t_main *main, int y, int iy)
{
	t_minimap_data	data;
	int				x;
	int				ix;

	x = 0;
	ix = 0;
	data.main = main;
	data.y = y;
	data.iy = iy;
	while (ix < ft_strlen(main->map->content[iy]))
	{
		data.x = x;
		data.ix = ix;
		draw_minimap_tile(&data);
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
