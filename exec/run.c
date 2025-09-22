/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-oua <moel-oua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 12:43:41 by moel-oua          #+#    #+#             */
/*   Updated: 2025/09/14 14:03:29 by moel-oua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	draw(t_main *main)
{
	main->img->img = mlx_new_image(main->vars->mlx, WIDTH, HEIGHT);
	main->img->addr = mlx_get_data_addr(main->img->img,
			&main->img->bits_per_pixel, &main->img->line_length,
			&main->img->endian);
	cast(main);
	render(main);
	mlx_put_image_to_window(main->vars->mlx, main->vars->win, main->img->img, 0,
		0);
	mlx_destroy_image(main->vars->mlx, main->img->img);
	main->img->img = NULL;
}

bool	init_res(t_main *main)
{
	t_vars	*vars;
	t_data	*img;

	vars = ft_malloc(main, sizeof(t_vars));
	img = ft_malloc(main, sizeof(t_data));
	if (!vars || !img || !initkeys(main))
		return (false);
	main->map->tsize = WIDTH / TSIZE;
	main->vars = vars;
	main->img = img;
	return (true);
}

void	run(t_main *main)
{
	if (!init_res(main) || !init_player(main) || !init_rays(main))
		return ;
	main->vars->mlx = mlx_init();
	if (!main->vars->mlx)
		return ;
	if (!load_textures(main))
	{
		close_win(main);
	}
	main->vars->win = mlx_new_window(main->vars->mlx, WIDTH, HEIGHT, TITLE);
	if (!main->vars->win)
	{
		close_win(main);
	}
	draw(main);
	hooks_handler(main);
	mlx_loop(main->vars->mlx);
}
