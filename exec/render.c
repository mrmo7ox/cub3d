/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-oua <moel-oua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 17:03:49 by moel-oua          #+#    #+#             */
/*   Updated: 2025/09/14 10:42:29 by moel-oua         ###   ########.fr       */
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

int	get_wall_color(t_rays *ray)
{
	if (ray->is_vert)
	{
		if (ray->is_left)
			return (0xCC3333);
		return (0x33CC33);
	}
	else
	{
		if (ray->is_up)
			return (0x3333CC);
		return (0xCCCC33);
	}
}

void	render_column(t_main *main, int i)
{
	t_draw_data	data;

	calculate_wall_projection(main, i, &data);
	data.color = get_wall_color(main->rays[i]);
	draw_columns(main, i, &data);
}

void	render(t_main *main)
{
	int	i;

	i = 0;
	while (i < NBR_RAYS)
	{
		render_column(main, i);
		i++;
	}
}
