/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-oua <moel-oua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 13:25:37 by moel-oua          #+#    #+#             */
/*   Updated: 2025/09/14 13:34:22 by moel-oua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

bool	initkeys(t_main *main)
{
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
	return (true);
}

int	close_win(t_main *main)
{
	if (main->img && main->img->img)
		mlx_destroy_image(main->vars->mlx, main->img->img);
	if (main->vars && main->vars->win)
		mlx_destroy_window(main->vars->mlx, main->vars->win);
	clean_textures(main);
	if (main->vars && main->vars->mlx)
	{
		mlx_destroy_display(main->vars->mlx);
		free(main->vars->mlx);
	}
	ft_cleangc(main->gc);
	exit(0);
}

int	keypress(int key_hook, t_main *main)
{
	t_keys	*keys;

	keys = main->keys;
	if (key_hook == W)
		keys->w = true;
	if (key_hook == D)
		keys->d = true;
	if (key_hook == A)
		keys->a = true;
	if (key_hook == S)
		keys->s = true;
	if (key_hook == LEFT)
		keys->l = true;
	if (key_hook == RIGHT)
		keys->r = true;
	if (key_hook == ON_DESTROY)
		keys->exit = true;
	if (key_hook == ON_EXIT)
	{
		keys->exit = true;
	}
	return (0);
}

int	keyrelease(int key_hook, t_main *main)
{
	t_keys	*keys;

	keys = main->keys;
	if (key_hook == W)
		keys->w = false;
	if (key_hook == D)
		keys->d = false;
	if (key_hook == A)
		keys->a = false;
	if (key_hook == S)
		keys->s = false;
	if (key_hook == LEFT)
		keys->l = false;
	if (key_hook == RIGHT)
		keys->r = false;
	return (0);
}

void	hooks_handler(t_main *main)
{
	mlx_hook(main->vars->win, 3, 1L << 1, keyrelease, main);
	mlx_hook(main->vars->win, 2, 1L << 0, keypress, main);
	mlx_hook(main->vars->win, 17, 0, close_win, main);
	mlx_loop_hook(main->vars->mlx, player_move, main);
}
