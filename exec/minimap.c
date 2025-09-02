/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-oua <moel-oua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 15:41:54 by moel-oua          #+#    #+#             */
/*   Updated: 2025/08/06 18:15:36 by moel-oua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

bool	iswall(t_main *main, double x, double y)
{
	int map_x, map_y;
	double radius = main->p->size / 2.0;

	double corners[4][2] = {
		{x - radius, y - radius},  
		{x + radius, y - radius},
		{x - radius, y + radius},
		{x + radius, y + radius}
	};

	for (int i = 0; i < 4; i++)
	{
		map_x = (int)(corners[i][0] / main->map->tsize);
		map_y = (int)(corners[i][1] / main->map->tsize);
		if (map_y < 0 || map_y >= (int)ft_dplen(main->map->content) ||
			map_x < 0 || map_x >= (int)ft_strlen(main->map->content[map_y]))
			return (true);
		if (main->map->content[map_y][map_x] == '1')
			return (true);
	}
	return (false);
}

void draw_minimap_border(t_main *main)
{
	int minimap_size = 200;
	int border_thickness = 2;
	
	for (int i = 0; i < border_thickness; i++)
	{
		draw_line(main, 10 - i, 10 - i, minimap_size + 2*i, 0, 0xffffff);
		draw_line(main, 10 - i, 10 + minimap_size + i, minimap_size + 2*i, 0, 0xffffff);
		draw_line(main, 10 - i, 10 - i, minimap_size + 2*i, PI/2, 0xffffff);
		draw_line(main, 10 + minimap_size + i, 10 - i, minimap_size + 2*i, PI/2, 0xffffff);
	}
}

void draw_minimap(t_main *main)
{
	int minimap_size = 200;
	double scale_x = (double)minimap_size / (main->map->height * main->map->tsize);
	double scale_y = (double)minimap_size / (main->map->width * main->map->tsize);
	double scale = fmin(scale_x, scale_y);
	
	draw_sq(main->img, 10, 10, minimap_size, 0x000000);
	
	for (int y = 0; y < main->map->width; y++)
	{
		int cols = ft_strlen(main->map->content[y]);
		for (int x = 0; x < cols; x++)
		{
			int mini_x = 10 + (int)(x * main->map->tsize * scale);
			int mini_y = 10 + (int)(y * main->map->tsize * scale);
			int tile_size = (int)(main->map->tsize * scale);
			if (tile_size < 1) tile_size = 1;
			
			if (main->map->content[y][x] == '1')
				draw_sq(main->img, mini_x, mini_y, tile_size, main->colors->c);
			else
				draw_sq(main->img, mini_x, mini_y, tile_size, main->colors->f);
		}
	}
	
	double player_mini_x = 10 + (main->p->x * scale);
	double player_mini_y = 10 + (main->p->y * scale);
	double player_mini_size = main->p->size * scale;
	if (player_mini_size < 3) player_mini_size = 3;
	
	draw_sq(main->img, (int)player_mini_x, (int)player_mini_y, (int)player_mini_size, 0xff0000); 
	
	double fov = FOV * PI / 180;
	int num_rays = 50;
	
	for (int i = 0; i <= num_rays; i++)
	{
		double ray_angle = main->p->rotation_angle - (fov / 2) + ((double)i * fov / (double)num_rays);
		ray_angle = normalize_angle(ray_angle);
		
		double dist = cast_ray(main, ray_angle);
		double scaled_dist = dist * scale;
		
		if (scaled_dist > minimap_size * 0.8) 
			scaled_dist = minimap_size * 0.8;
		
		draw_line(main, player_mini_x + player_mini_size/2, player_mini_y + player_mini_size/2,
				  scaled_dist, ray_angle, 0x00ff00);
	}
	
	double center_ray_angle = normalize_angle(main->p->rotation_angle);
	double center_dist = cast_ray(main, center_ray_angle);
	double center_scaled_dist = center_dist * scale;
	if (center_scaled_dist > minimap_size * 0.8) 
		center_scaled_dist = minimap_size * 0.8;
	
	draw_line(main, player_mini_x + player_mini_size/2, player_mini_y + player_mini_size/2,
			  center_scaled_dist, center_ray_angle, 0xfc032c);
	
	draw_minimap_border(main);
}