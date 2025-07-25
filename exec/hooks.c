/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-oua <moel-oua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 13:25:37 by moel-oua          #+#    #+#             */
/*   Updated: 2025/07/24 21:04:04 by moel-oua         ###   ########.fr       */
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

void	hooks_handler(t_main *main)
{
	mlx_hook(main->vars->win, 17, 0, close_win, main);
	mlx_hook(main->vars->win, 2, 0L, player_move, main);
	mlx_key_hook(main->vars->win, key_hook, main);
	
}

int	key_hook(int keycode, t_main *main)
{
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