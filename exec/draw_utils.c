/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_urtils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-oua <moel-oua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 15:42:30 by moel-oua          #+#    #+#             */
/*   Updated: 2025/07/28 12:53:23 by moel-oua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	draw_pxl(t_data *img, int x, int y, int clr)
{
	if(x < 0 || x >= WIDTH || y < 0|| y >= HEIGHT)
		return ;
	my_mlx_pixel_put(img, x , y , clr);	
}

void	draw_sq(t_data *img ,size_t start_x , size_t start_y, size_t size, int color)
{
	size_t dx = start_x + size;
	size_t dy = start_y + size;
	size_t x = start_x;

	while(start_y < dy)
	{
		start_x = x;
		while(start_x < dx)
			draw_pxl(img, start_x++ , start_y, color);
		start_y++;
	}	
}


void	draw_line(t_main *main , double s_x, double s_y, double len, double angle,int color)
{
	double	end_x = s_x + cos(angle) * len;
	double	end_y = s_y + sin(angle) * len;
	double		dx = (end_x) - s_x;
	double		dy = (end_y) - s_y;
	double		step;
	double		incx;
	double		incy;
	double		i = 0;
	if(fabs(dx) > fabs(dy))
		step = fabs(dx);
	else
		step = fabs(dy);
	incx = dx / step;
	incy = dy / step;
	while(i <= step)
	{
		draw_pxl(main->img, s_x, s_y, color);
		i++;
		s_x += incx;
		s_y += incy;
	}
	
}

