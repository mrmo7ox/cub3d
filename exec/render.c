/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-oua <moel-oua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 17:03:49 by moel-oua          #+#    #+#             */
/*   Updated: 2025/09/14 13:56:58 by moel-oua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	calculate_wall_projection(t_main *main, int i, t_draw_data *data)
{
	double	perp_dist;

	perp_dist = main->rays[i]->distance * cos(main->rays[i]->ray_angle
			- main->p->rotation_angle);
	data->line_height = (int)(HEIGHT / perp_dist);
	data->draw_start = -(data->line_height) / 2 + HEIGHT / 2;
	if (data->draw_start < 0)
		data->draw_start = 0;
	data->draw_end = data->line_height / 2 + HEIGHT / 2;
	if (data->draw_end >= HEIGHT)
		data->draw_end = HEIGHT - 1;
}

void	render_textured_column(t_main *main, int i)
{
	t_draw_data	data;
	t_txtr_cnt	*texture;

	calculate_wall_projection(main, i, &data);
	texture = get_wall_texture(main, i);
	draw_textured_wall(main, texture, i, &data);
	draw_ceiling(main, i, data.draw_start);
	draw_floor(main, i, data.draw_end);
}

void	render(t_main *main)
{
	int	i;

	i = 0;
	while (i < NBR_RAYS)
	{
		render_textured_column(main, i);
		i++;
	}
}
