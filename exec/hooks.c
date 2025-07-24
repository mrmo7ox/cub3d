/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-oua <moel-oua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 13:25:37 by moel-oua          #+#    #+#             */
/*   Updated: 2025/07/24 09:56:39 by moel-oua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	close_win(t_main *main)
{
	mlx_destroy_image(main->vars->mlx, main->img->img);
	mlx_destroy_window(main->vars->mlx, main->vars->win);
    ft_cleangc(main->gc);
	exit(1);
}

int	key_hook(int keycode, t_main *main)
{
	printf("%d\n", keycode);
	
	if(124 == keycode)
	{
		if(main->p->x + (int)TSIZE < (int)main->map->width)
			main->p->x  += (int)TSIZE;
		else
			main->p->x  = TSIZE;
	}
	if(123 == keycode)
	{
		if(main->p->x - (int)TSIZE > 0)
			main->p->x  -= (int)TSIZE;
		else
			main->p->x  = (int)main->map->width + (int)TSIZE;
	}
	
	if(125 == keycode)
	{
		if(main->p->y + (int)TSIZE < (int)main->map->height)
			main->p->y  += (int)TSIZE;
		else
			main->p->y  = TSIZE;
	}
	if(126 == keycode)
	{
		if(main->p->y - (int)TSIZE > 0)
			main->p->y  -= (int)TSIZE;
		else
			main->p->y = (int)main->map->height + (int)TSIZE;
	}


	draw(main);
	if (53 == keycode)
	{
		mlx_destroy_image(main->vars->mlx, main->img->img);
		mlx_destroy_window(main->vars->mlx, main->vars->win);
        ft_cleangc(main->gc);
		exit(1);
	}
	return (0);
}