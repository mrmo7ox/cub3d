/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-oua <moel-oua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 12:43:41 by moel-oua          #+#    #+#             */
/*   Updated: 2025/07/24 10:54:28 by moel-oua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"


void	draw_pxl(t_data *img, int x, int y, int clr)
{
	if(x < 0 || x >= WIDTH || y < 0|| y >= HEIGHT)
		return ;
	my_mlx_pixel_put(img, x , y , clr);	
}


void	draw_sq(t_data *img ,size_t start_x , size_t start_y, size_t size, int color)
{
	size_t dx = start_x + size;
	size_t dy = start_y + size;
	size_t x = start_x;

	while(start_y <= dy)
	{
		start_x = x;
		while(start_x <= dx)
			draw_pxl(img, start_x++ , start_y, color);
		start_y++;
	}	
}

void	update(t_main *main)
{
	
	printf("%i %i\n", main->p->x, main->p->y);
	if((main->p->x >= main->a->x && main->p->x <= main->a->x + (TSIZE ))
	 && (main->p->y >= main->a->y && main->p->y <= main->a->y + (TSIZE )))
	{
		system("afplay /mnt/homes/moel-oua/goinfre/sound.mp3 &");
		int rnd = (rand() % 700) + TSIZE;
		main->a->x = rnd;
		main->a->y = rnd;
	
	}

	draw_sq(main->img, main->p->x, main->p->y, TSIZE, 0x4287f5);
	draw_sq(main->img, main->a->x, main->a->y, TSIZE, 0xe3024d);
}

void	draw(t_main *main)
{
	mlx_destroy_image(main->vars->mlx, main->img->img);
	mlx_clear_window(main->vars->mlx, main->vars->win);
	main->img->img = mlx_new_image(main->vars->mlx,WIDTH, HEIGHT);
	main->img->addr = mlx_get_data_addr(main->img->img, &main->img->bits_per_pixel, &main->img->line_length,
							&main->img->endian);
	update(main);
	mlx_put_image_to_window(main->vars->mlx, main->vars->win, main->img->img, 0, 0);

}

void	hooks_handler(t_main *main)
{
	mlx_hook(main->vars->win, 17, 0, close_win, main);
	mlx_key_hook(main->vars->win, key_hook, main);
}

void	run(t_main *main)
{
	t_vars	*vars;
	t_data	*img;
	t_plr	a;
	
	vars = ft_malloc(main, sizeof(t_vars));
	img = ft_malloc(main, sizeof(t_data));
	main->map->height = (HEIGHT  );
	main->map->width = (WIDTH );
	main->p->x = main->map->width / 2;
	main->p->y = main->map->height / 2;
	a.x = 400;
	a.y = 400;
	main->a = &a;
	printf("h=%d\nw=%d\n", main->map->height, main->map->width);
	if(!vars || !img)
		return ;
	main->vars = vars;
	main->img = img;
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
