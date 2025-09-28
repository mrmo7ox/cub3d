/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabounna <yabounna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 13:51:52 by moel-oua          #+#    #+#             */
/*   Updated: 2025/09/28 13:51:14 by yabounna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

t_txtr_cnt	*get_mur_texture(t_main *main, int i)
{
	if (main->rays[i]->is_vert)
	{
		if (main->rays[i]->a_gauche)
			return (main->txts_cnt[0]);
		return (main->txts_cnt[2]);
	}
	else
	{
		if (main->rays[i]->en_haut)
			return (main->txts_cnt[1]);
		return (main->txts_cnt[3]);
	}
}

void	draw_textured_mur(t_main *main, t_txtr_cnt *texture, int i,
		t_draw_data *data)
{
	double	mur_x;
	int		tex_x;
	double	step;
	double	tex_pos;
	int		y;

	mur_x = calculate_mur_x(main->rays[i], main);
	tex_x = (int)(mur_x * texture->width);
	tex_x = clamp_tex_x(tex_x, texture->width);
	step = 1.0 * texture->height / data->line_height;
	tex_pos = (data->draw_debut - HEIGHT / 2 + data->line_height / 2) * step;
	y = data->draw_debut;
	while (y < data->draw_fin)
	{
		draw_pxl(main->img, i, y, get_pixel_color(texture, tex_x, (int)tex_pos
				% (texture->height - 1)));
		tex_pos += step;
		y++;
	}
}

double	calculate_mur_x(t_rays *ray, t_main *main)
{
	double	mur_x;

	if (ray->is_vert)
		mur_x = main->p->y + ray->distance * sin(ray->ray_angle);
	else
		mur_x = main->p->x + ray->distance * cos(ray->ray_angle);
	mur_x -= floor(mur_x);
	return (mur_x);
}

int	clamp_tex_x(int tex_x, int texture_width)
{
	if (tex_x < 0)
		return (0);
	if (tex_x >= texture_width)
		return (texture_width - 1);
	return (tex_x);
}
