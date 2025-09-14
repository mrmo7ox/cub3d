/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   casting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-oua <moel-oua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 16:29:46 by moel-oua          #+#    #+#             */
/*   Updated: 2025/09/14 10:46:09 by moel-oua         ###   ########.fr       */
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

void	render_rays(t_main *main)
{
	int				i;
	double			px;
	double			py;
	t_line_params	params;

	i = 0;
	px = main->p->x * main->map->tsize + (main->p->width / 2);
	py = main->p->y * main->map->tsize + (main->p->height / 2);
	while (i < NBR_RAYS)
	{
		if (main->rays[i] && main->rays[i]->wallhitx > 0
			&& main->rays[i]->wallhity > 0)
		{
			params.start_x = px;
			params.start_y = py;
			params.len = sqrt(pow(main->rays[i]->wallhitx - px, 2)
					+ pow(main->rays[i]->wallhity - py, 2));
			params.angle = atan2(main->rays[i]->wallhity - py,
					main->rays[i]->wallhitx - px);
			params.color = 0xFF0000;
			draw_line(main, &params);
		}
		i++;
	}
}

void	set_ray_direction(t_main *main, float ray_angle, int ray_id)
{
	main->rays[ray_id]->is_down = false;
	main->rays[ray_id]->is_left = false;
	main->rays[ray_id]->is_up = false;
	main->rays[ray_id]->is_right = false;
	ray_angle = normalize_angle(ray_angle);
	if (ray_angle > 0 && ray_angle < M_PI)
		main->rays[ray_id]->is_down = true;
	else
		main->rays[ray_id]->is_up = true;
	if (ray_angle < M_PI / 2 || ray_angle > 1.5 * M_PI)
		main->rays[ray_id]->is_right = true;
	else
		main->rays[ray_id]->is_left = true;
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
	ray_angle = main->p->rotation_angle - (fov_rad / 2);
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
