/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-oua <moel-oua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 09:31:50 by moel-oua          #+#    #+#             */
/*   Updated: 2025/07/30 14:53:15 by moel-oua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

t_angle	get_angle(double angle)
{

	if(angle > 0 && angle < M_PI)
		return E_DOWN;
	else if (angle > 0 && angle > M_PI)
		return E_UP;
	else if (angle > 0.5 * M_PI || angle > 1.5 * M_PI)
		return E_RIGHT;
	else if (angle < 0.5 * M_PI || angle < 1.5 * M_PI)
		return E_LEFT;
	return E_NULL;
}

void	set_player_angle(t_main *main)
{
	char	player;

	player = main->map->player;
	if(player == 'S')
		main->p->rotation_angle =  M_PI / 2;
	else if(player == 'E')
		main->p->rotation_angle = 2 * M_PI;
	else if(player == 'N')
		main->p->rotation_angle =  (3 * M_PI) / 2;
	else if(player == 'W')
		main->p->rotation_angle = M_PI;
}


void	draw_ray(t_main *main , double s_x, double s_y, double nx, double ny, int color)
{
	double	end_x = nx;
	double	end_y = ny;
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
	// printf("end_x = %f ", end_x);
	// printf("end_y = %f ", end_y);
	// printf("steps = %f ", step);
	// printf("incx = %f ", incx);
	// printf("incy = %f ", incy);
	// printf("angle = %f\n", angle);
	while(i <= step)
	{
		draw_pxl(main->img, s_x, s_y, color);
		i++;
		s_x += incx;
		s_y += incy;
	}
	
}
void	ray_castring(t_main *main, double angle , double x, double y)
{
	double	xi;
	double	yi;
	double	xstep;
	double	ystep;
	double	nexthx;
	double	nexthy;

	yi = roundf(y / main->map->tsize) * main->map->tsize;
	if(get_angle(angle) == E_DOWN)
		yi += main->map->tsize;
	xi = x + (yi - y) / tan(angle); 
	
	ystep = main->map->tsize;
	if(get_angle(angle) == E_UP)
		ystep *= -1;
	xstep = main->map->tsize / tan(angle);
	if(get_angle(angle) == E_LEFT && xstep > 0)
		xstep *= -1;
	if(get_angle(angle) == E_RIGHT && xstep < 0)
		xstep *= -1;
	nexthx = xi;
	nexthy = yi;
	if(get_angle(angle) == E_UP)
		nexthy--;
	while((nexthx <= main->map->width && nexthx >= 0) && (nexthy >= 0 &&nexthy <= main->map->height))
	{
		if(iswall(main, nexthx, nexthy))
			break;
		nexthx += xstep;
		nexthy += ystep;
	}
	draw_ray(main, x, y, nexthx, nexthy, 0x2600ff);
}
