/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabounna <yabounna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 17:03:49 by moel-oua          #+#    #+#             */
/*   Updated: 2025/09/28 14:06:22 by yabounna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	calculate_mur_projection(t_main *main, int i, t_draw_data *data)
{
	double	perp_dist;

	perp_dist = main->rays[i]->distance * cos(main->rays[i]->ray_angle
			- main->p->angle_de_rotation);
	data->line_height = (int)(HEIGHT / perp_dist);
	data->draw_debut = -(data->line_height) / 2 + HEIGHT / 2;
	if (data->draw_debut < 0)
		data->draw_debut = 0;
	data->draw_fin = data->line_height / 2 + HEIGHT / 2;
	if (data->draw_fin >= HEIGHT)
		data->draw_fin = HEIGHT - 1;
}

void	render_textured_column(t_main *main, int i)
{
	t_draw_data	data;
	t_txtr_cnt	*texture;

	calculate_mur_projection(main, i, &data);
	texture = get_mur_texture(main, i);
	draw_textured_mur(main, texture, i, &data);
	draw_plafond(main, i, data.draw_debut);
	draw_sol(main, i, data.draw_fin);
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
