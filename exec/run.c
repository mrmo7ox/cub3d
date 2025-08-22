/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-oua <moel-oua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 12:43:41 by moel-oua          #+#    #+#             */
/*   Updated: 2025/08/06 18:15:36 by moel-oua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	draw(t_main *main)
{
	mlx_destroy_image(main->vars->mlx, main->img->img);
	main->img->img = mlx_new_image(main->vars->mlx, WIDTH, HEIGHT);
	main->img->addr = mlx_get_data_addr(main->img->img, &main->img->bits_per_pixel, 
										&main->img->line_length, &main->img->endian);
	draw_bg_2(main);
	draw_minimap(main);
	render_3d_view(main);
	mlx_put_image_to_window(main->vars->mlx, main->vars->win, main->img->img, 0, 0);
}

bool	init_res(t_main *main)
{
	t_vars	*vars;
	t_data	*img;
	t_keys	*keys;

	keys = ft_malloc(main, sizeof(t_keys));
	if (!keys)
		return (false);
		
	keys->a = false;
	keys->w = false;
	keys->s = false;
	keys->d = false;
	keys->l = false;
	keys->r = false;
	keys->exit = false;
	main->keys = keys;
	
	vars = ft_malloc(main, sizeof(t_vars));
	img = ft_malloc(main, sizeof(t_data));
	if(!vars || !img)
		return (false);
		
	int max_map_width = 0;
	int map_height = ft_dplen(main->map->content);
	
	for (int i = 0; i < map_height; i++)
	{
		int row_width = ft_strlen(main->map->content[i]);
		if (row_width > max_map_width)
			max_map_width = row_width;
	}
	
	main->map->tsize = fmin((WIDTH - 250) / max_map_width, (HEIGHT - 50) / map_height);
	if (main->map->tsize < 10)
		main->map->tsize = 10;
	
	printf("Tile size: %d\n", main->map->tsize);
	printf("Map height: %d\n", map_height);
	printf("Map width: %d\n", max_map_width);
	
	main->vars = vars;
	main->img = img;
	return (true);
}

void	run(t_main *main)
{
	if(!init_res(main) || !init_player(main))
		return ;
	main->vars->mlx = mlx_init();
	if(!main->vars->mlx)
		return ;
	main->vars->win = mlx_new_window(main->vars->mlx, WIDTH, HEIGHT, TITLE);
	if(!main->vars->win)
		return ;
	main->img->img = mlx_new_image(main->vars->mlx, WIDTH, HEIGHT);
	main->img->addr = mlx_get_data_addr(main->img->img, &main->img->bits_per_pixel, 
										&main->img->line_length, &main->img->endian);
	draw(main);
	hooks_handler(main);
	mlx_hook(main->vars->win, 17, 0, close_win, main);  // Handle window close
	mlx_put_image_to_window(main->vars->mlx, main->vars->win, main->img->img, 0, 0);
	mlx_loop(main->vars->mlx);
}