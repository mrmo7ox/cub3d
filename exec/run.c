/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-oua <moel-oua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 12:43:41 by moel-oua          #+#    #+#             */
/*   Updated: 2025/07/30 13:08:19 by moel-oua         ###   ########.fr       */
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
	draw_bg_2(main);
	draw_bg(main);
	draw_map(main);
	draw_player(main);
	mlx_put_image_to_window(main->vars->mlx, main->vars->win, main->img->img, 0, 0);
}

bool	init_res(t_main *main)
{
	t_vars	*vars;
	t_data	*img;
	t_keys	*keys;

	keys = ft_malloc(main, sizeof(t_keys));
	keys->a = false;
	keys->w = false;
	keys->s = false;
	keys->d = false;
	keys->l = false;
	keys->r = false;
	main->keys = keys;
	vars = ft_malloc(main, sizeof(t_vars));
	vars->main = main;
	img = ft_malloc(main, sizeof(t_data));
	if(!vars || !img)
		return (false);
	main->map->tsize = MSIZE / ft_strlen(main->map->content[0]);
	printf("main->map->still %d\n", main->map->tsize);
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
