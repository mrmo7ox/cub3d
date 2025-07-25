/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-oua <moel-oua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 12:43:41 by moel-oua          #+#    #+#             */
/*   Updated: 2025/07/25 10:11:53 by moel-oua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	draw(t_main *main)
{
	mlx_destroy_image(main->vars->mlx, main->img->img);
	mlx_clear_window(main->vars->mlx, main->vars->win);
	main->img->img = mlx_new_image(main->vars->mlx,WIDTH, HEIGHT);
	main->img->addr = mlx_get_data_addr(main->img->img, &main->img->bits_per_pixel, &main->img->line_length,
							&main->img->endian);
	draw_map(main);
	draw_player(main);
	mlx_put_image_to_window(main->vars->mlx, main->vars->win, main->img->img, 0, 0);
}

bool	init_res(t_main *main)
{
	t_vars	*vars;
	t_data	*img;
	
	vars = ft_malloc(main, sizeof(t_vars));
	vars->main = main;
	img = ft_malloc(main, sizeof(t_data));
	if(!vars || !img)
		return (false);
	main->map->height = (HEIGHT * MSCALE);
	main->map->width = (WIDTH * MSCALE);
	main->vars = vars;
	main->img = img;
	printf("height:%d \n",main->map->height);
	printf("width:%d \n",main->map->width);
	printf("vars:%p \n",main->vars = vars);
	printf("img:%p \n",main->img = img);
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
	main->img->img = mlx_new_image(main->vars->mlx,WIDTH, HEIGHT);
	main->img->addr = mlx_get_data_addr(main->img->img, &main->img->bits_per_pixel, &main->img->line_length,
								&main->img->endian);
	draw(main);
	hooks_handler(main);
	mlx_put_image_to_window(main->vars->mlx, main->vars->win, main->img->img, 0, 0);
	mlx_loop(main->vars->mlx);
}
