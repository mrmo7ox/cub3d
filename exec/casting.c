/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   casting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabounna <yabounna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 16:29:46 by moel-oua          #+#    #+#             */
/*   Updated: 2025/09/28 14:06:22 by yabounna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

bool	init_rays(t_main *main)
{
	int	i;

	main->rays = ft_malloc(main, sizeof(t_rays *) * NBR_RAYS);
	if (!main->rays)
		return (false);
	i = 0;
	while (i < NBR_RAYS)
	{
		main->rays[i] = ft_malloc(main, sizeof(t_rays));
		if (!main->rays[i])
			return (false);
		main->rays[i]->wallhitx = 0;
		main->rays[i]->wallhity = 0;
		main->rays[i]->hit_content = '0';
		i++;
	}
	return (true);
}

void	set_ray_direction(t_main *main, float ray_angle, int ray_id)
{
	main->rays[ray_id]->en_bas = false;
	main->rays[ray_id]->a_gauche = false;
	main->rays[ray_id]->en_haut = false;
	main->rays[ray_id]->a_droit = false;
	ray_angle = normalize_angle(ray_angle);
	if (ray_angle > 0 && ray_angle < M_PI)
		main->rays[ray_id]->en_bas = true;
	else
		main->rays[ray_id]->en_haut = true;
	if (ray_angle < M_PI / 2 || ray_angle > 1.5 * M_PI)
		main->rays[ray_id]->a_droit = true;
	else
		main->rays[ray_id]->a_gauche = true;
}

void	cast(t_main *main)
{
	double	fov_rad;
	float	ray_angle;
	int		ray_id;

	if (!main->rays)
		return ;
	fov_rad = FOV * M_PI / 180.0;
	ray_id = 0;
	ray_angle = main->p->angle_de_rotation - (fov_rad / 2);
	while (ray_id < NBR_RAYS)
	{
		if (!main->rays[ray_id])
		{
			ray_id++;
			continue ;
		}
		ray_angle = normalize_angle(ray_angle);
		set_ray_direction(main, ray_angle, ray_id);
		cast_ray(main, ray_angle, ray_id);
		ray_angle += fov_rad / NBR_RAYS;
		ray_id++;
	}
}
