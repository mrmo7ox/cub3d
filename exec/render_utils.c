/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-oua <moel-oua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 10:36:51 by moel-oua          #+#    #+#             */
/*   Updated: 2025/09/14 10:41:34 by moel-oua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	draw_ceiling(t_main *main, int i, int draw_start)
{
	int	y;

	y = 0;
	while (y < draw_start)
	{
		draw_pxl(main->img, i, y, main->colors->c);
		y++;
	}
}

void	draw_floor(t_main *main, int i, int draw_end)
{
	int	y;

	y = draw_end + 1;
	while (y < HEIGHT)
	{
		draw_pxl(main->img, i, y, main->colors->f);
		y++;
	}
}

void	draw_wall(t_main *main, int i, t_draw_data *data)
{
	int	y;

	y = data->draw_start;
	while (y <= data->draw_end)
	{
		draw_pxl(main->img, i, y, data->color);
		y++;
	}
}

void	draw_columns(t_main *main, int i, t_draw_data *data)
{
	draw_ceiling(main, i, data->draw_start);
	draw_wall(main, i, data);
	draw_floor(main, i, data->draw_end);
}
