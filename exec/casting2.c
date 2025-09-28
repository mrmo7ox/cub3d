/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   casting2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabounna <yabounna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 21:18:27 by moel-oua          #+#    #+#             */
/*   Updated: 2025/09/28 14:01:38 by yabounna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	calc_step_and_side_dist(t_raycast *rc)
{
	if (rc->ray_dir_x < 0)
	{
		rc->step_x = -1;
		rc->cote_dist_x = (rc->player_x - rc->map_x) * rc->delta_dist_x;
	}
	else
	{
		rc->step_x = 1;
		rc->cote_dist_x = (rc->map_x + 1.0 - rc->player_x) * rc->delta_dist_x;
	}
	if (rc->ray_dir_y < 0)
	{
		rc->step_y = -1;
		rc->cote_dist_y = (rc->player_y - rc->map_y) * rc->delta_dist_y;
	}
	else
	{
		rc->step_y = 1;
		rc->cote_dist_y = (rc->map_y + 1.0 - rc->player_y) * rc->delta_dist_y;
	}
}

void	performer_dda(t_main *main, t_raycast *rc)
{
	while (rc->hit == 0)
	{
		if (rc->cote_dist_x < rc->cote_dist_y)
		{
			rc->cote_dist_x += rc->delta_dist_x;
			rc->map_x += rc->step_x;
			rc->side = 0;
		}
		else
		{
			rc->cote_dist_y += rc->delta_dist_y;
			rc->map_y += rc->step_y;
			rc->side = 1;
		}
		if (rc->map_x < 0 || rc->map_x >= (int)ft_strlen(main->map->content[0])
			|| rc->map_y < 0 || rc->map_y >= (int)ft_dplen(main->map->content))
		{
			rc->hit = 1;
			break ;
		}
		if (main->map->content[rc->map_y][rc->map_x] == '1')
			rc->hit = 1;
	}
}

void	calc_perp_mur_dist(t_raycast *rc)
{
	if (rc->side == 0)
		rc->perp_mur_dist = (rc->map_x - rc->player_x + (1 - rc->step_x) / 2)
			/ rc->ray_dir_x;
	else
		rc->perp_mur_dist = (rc->map_y - rc->player_y + (1 - rc->step_y) / 2)
			/ rc->ray_dir_y;
}

void	stock_ray_result(t_main *main, t_raycast *rc, int ray_id,
		float ray_angle)
{
	main->rays[ray_id]->ray_angle = ray_angle;
	main->rays[ray_id]->distance = rc->perp_mur_dist;
	main->rays[ray_id]->wallhitx = (rc->player_x + rc->ray_dir_x
			* rc->perp_mur_dist) * main->map->tsize;
	main->rays[ray_id]->wallhity = (rc->player_y + rc->ray_dir_y
			* rc->perp_mur_dist) * main->map->tsize;
	main->rays[ray_id]->hit_content = '1';
	main->rays[ray_id]->is_vert = (rc->side == 0);
	main->rays[ray_id]->en_haut = (rc->side == 1 && rc->ray_dir_y < 0);
	main->rays[ray_id]->en_bas = (rc->side == 1 && rc->ray_dir_y > 0);
	main->rays[ray_id]->a_gauche = (rc->side == 0 && rc->ray_dir_x < 0);
	main->rays[ray_id]->a_droit = (rc->side == 0 && rc->ray_dir_x > 0);
}

void	cast_ray(t_main *main, float ray_angle, int ray_id)
{
	t_raycast	rc;

	raycast_initial(main, ray_angle, &rc);
	calc_step_and_side_dist(&rc);
	performer_dda(main, &rc);
	calc_perp_mur_dist(&rc);
	stock_ray_result(main, &rc, ray_id, ray_angle);
}
