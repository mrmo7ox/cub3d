/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-oua <moel-oua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 15:42:30 by moel-oua          #+#    #+#             */
/*   Updated: 2025/09/14 10:56:27 by moel-oua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	draw_pxl(t_data *img, int x, int y, int clr)
{
	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	my_mlx_pixel_put(img, x, y, clr);
}

void	init_line_data(t_line_params *params, double *incx, double *incy,
		double *step)
{
	double	end_x;
	double	end_y;
	double	dx;
	double	dy;

	end_x = params->start_x + cos(params->angle) * params->len;
	end_y = params->start_y + sin(params->angle) * params->len;
	dx = end_x - params->start_x;
	dy = end_y - params->start_y;
	if (fabs(dx) > fabs(dy))
		*step = fabs(dx);
	else
		*step = fabs(dy);
	*incx = dx / *step;
	*incy = dy / *step;
}

void	draw_line(t_main *main, t_line_params *params)
{
	t_line_vars	vars;

	init_line_data(params, &vars.incx, &vars.incy, &vars.step);
	vars.i = 0;
	vars.current_x = params->start_x;
	vars.current_y = params->start_y;
	while (vars.i <= vars.step)
	{
		draw_pxl(main->img, vars.current_x, vars.current_y, params->color);
		vars.i++;
		vars.current_x += vars.incx;
		vars.current_y += vars.incy;
	}
}
