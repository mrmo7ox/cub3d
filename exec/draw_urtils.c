/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_urtils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-oua <moel-oua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 15:42:30 by moel-oua          #+#    #+#             */
/*   Updated: 2025/07/25 14:18:36 by moel-oua         ###   ########.fr       */
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

	while(start_y <= dy)
	{
		start_x = x;
		while(start_x <= dx)
			draw_pxl(img, start_x++ , start_y, color);
		start_y++;
	}	
}


void	draw_cer(t_data *img ,size_t s_x , size_t s_y, size_t r, int color)
{
	size_t	x = 0;
	size_t	y = -1 * r ;
	size_t	rad = r;
	size_t	ymid;


	while(x < (y * -1))
	{
			ymid = y + 0.5;
			if(((x * x) + (ymid * ymid)) > rad * rad)
				y = + 1;
			draw_pxl(img, s_x + x , s_y + y, color);
			draw_pxl(img, s_x - x , s_y + y, color);
			draw_pxl(img, s_x + x , s_y - y, color);
			draw_pxl(img, s_x - x , s_y - y, color);
		
			draw_pxl(img, s_x + y , s_y + x, color);
			draw_pxl(img, s_x - y , s_y + x, color);
			draw_pxl(img, s_x + y , s_y - x, color);
			draw_pxl(img, s_x - y , s_y - x, color);
			x++;
		}
}

