/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   casting3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-oua <moel-oua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 21:40:23 by moel-oua          #+#    #+#             */
/*   Updated: 2025/09/13 21:41:11 by moel-oua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	init_raycast(t_main *main, float ray_angle, t_raycast *rc)
{
	rc->player_x = main->p->x ;
	rc->player_y = main->p->y ;
	rc->ray_dir_x = cos(ray_angle);
	rc->ray_dir_y = sin(ray_angle);
	rc->map_x = (int)rc->player_x;
	rc->map_y = (int)rc->player_y;
	rc->delta_dist_x = fabs(1 / rc->ray_dir_x);
	rc->delta_dist_y = fabs(1 / rc->ray_dir_y);
	rc->hit = 0;
}
