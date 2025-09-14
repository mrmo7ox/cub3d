/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-oua <moel-oua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 13:51:52 by moel-oua          #+#    #+#             */
/*   Updated: 2025/09/14 14:01:27 by moel-oua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

t_txtr_cnt	*get_wall_texture(t_main *main, int i)
{
	if (main->rays[i]->is_vert)
	{
		if (main->rays[i]->is_left)
			return (main->txts_cnt[0]);
		return (main->txts_cnt[2]);
	}
	else
	{
		if (main->rays[i]->is_up)
			return (main->txts_cnt[1]);
		return (main->txts_cnt[3]);
	}
}

void	draw_textured_wall(t_main *main, t_txtr_cnt *texture, int i,
		t_draw_data *data)
{
	double	wall_x;
	int		tex_x;
	double	step;
	double	tex_pos;
	int		y;

	wall_x = calculate_wall_x(main->rays[i], main);
	tex_x = (int)(wall_x * texture->width);
	tex_x = clamp_tex_x(tex_x, texture->width);
	step = 1.0 * texture->height / data->line_height;
	tex_pos = (data->draw_start - HEIGHT / 2 + data->line_height / 2) * step;
	y = data->draw_start;
	while (y < data->draw_end)
	{
		draw_pxl(main->img, i, y, get_pixel_color(texture, tex_x,
				(int)tex_pos & (texture->height - 1)));
		tex_pos += step;
		y++;
	}
}

double	calculate_wall_x(t_rays *ray, t_main *main)
{
	double	wall_x;

	if (ray->is_vert)
		wall_x = main->p->y + ray->distance * sin(ray->ray_angle);
	else
		wall_x = main->p->x + ray->distance * cos(ray->ray_angle);
	wall_x -= floor(wall_x);
	return (wall_x);
}

int	clamp_tex_x(int tex_x, int texture_width)
{
	if (tex_x < 0)
		return (0);
	if (tex_x >= texture_width)
		return (texture_width - 1);
	return (tex_x);
}
