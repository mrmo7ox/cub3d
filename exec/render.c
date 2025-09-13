/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-oua <moel-oua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 17:03:49 by moel-oua          #+#    #+#             */
/*   Updated: 2025/09/13 21:39:02 by moel-oua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	calculate_wall_projection(t_main *main, int i, int *line_height,
		int *draw_start, int *draw_end)
{
	double	perp_dist;

	perp_dist = main->rays[i]->distance * cos(main->rays[i]->ray_angle
			- main->p->rotation_angle);
	*line_height = (int)(HEIGHT / perp_dist);
	*draw_start = -(*line_height) / 2 + HEIGHT / 2;
	if (*draw_start < 0)
		*draw_start = 0;
	*draw_end = *line_height / 2 + HEIGHT / 2;
	if (*draw_end >= HEIGHT)
		*draw_end = HEIGHT - 1;
}

int	get_wall_color(t_rays *ray)
{
	if (ray->is_vert)
	{
		if (ray->is_left)
			return (0xCC3333);
		else
			return (0x33CC33);
	}
	else
	{
		if (ray->is_up)
			return (0x3333CC);
		else
			return (0xCCCC33);
	}
}

void	draw_columns(t_main *main, int i, int draw_start, int draw_end,
		int color)
{
	for (int y = draw_start; y <= draw_end; y++)
	{
		draw_pxl(main->img, i, y, color);
	}
	for (int y = 0; y < draw_start; y++)
	{
		draw_pxl(main->img, i, y, main->colors->c);
	}
	for (int y = draw_end + 1; y > 0 && y < HEIGHT; y++)
	{
		draw_pxl(main->img, i, y, main->colors->f);
	}
}

void	render_column(t_main *main, int i)
{
	int	line_height;
	int	draw_start;
	int	draw_end;
	int	color;

	calculate_wall_projection(main, i, &line_height, &draw_start, &draw_end);
	color = get_wall_color(main->rays[i]);
	draw_columns(main, i, draw_start, draw_end, color);
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
