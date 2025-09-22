/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hundle_textures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-oua <moel-oua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 11:40:54 by moel-oua          #+#    #+#             */
/*   Updated: 2025/09/14 13:58:22 by moel-oua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

bool	add_imgs(t_main *main, t_txtr_cnt **txtrs_cnt)
{
	txtrs_cnt[0]->img = mlx_xpm_file_to_image(main->vars->mlx, main->txtrs->we,
			&txtrs_cnt[0]->width, &txtrs_cnt[0]->height);
	txtrs_cnt[1]->img = mlx_xpm_file_to_image(main->vars->mlx, main->txtrs->no,
			&txtrs_cnt[1]->width, &txtrs_cnt[1]->height);
	txtrs_cnt[2]->img = mlx_xpm_file_to_image(main->vars->mlx, main->txtrs->ea,
			&txtrs_cnt[2]->width, &txtrs_cnt[2]->height);
	txtrs_cnt[3]->img = mlx_xpm_file_to_image(main->vars->mlx, main->txtrs->so,
			&txtrs_cnt[3]->width, &txtrs_cnt[3]->height);
	if (!txtrs_cnt[0]->img || !txtrs_cnt[1]->img || !txtrs_cnt[2]->img
		|| !txtrs_cnt[3]->img)
		return (false);
	txtrs_cnt[0]->addr = mlx_get_data_addr(txtrs_cnt[0]->img,
			&txtrs_cnt[0]->bits_per_pixel, &txtrs_cnt[0]->line_length,
			&txtrs_cnt[0]->endian);
	txtrs_cnt[1]->addr = mlx_get_data_addr(txtrs_cnt[1]->img,
			&txtrs_cnt[1]->bits_per_pixel, &txtrs_cnt[1]->line_length,
			&txtrs_cnt[1]->endian);
	txtrs_cnt[2]->addr = mlx_get_data_addr(txtrs_cnt[2]->img,
			&txtrs_cnt[2]->bits_per_pixel, &txtrs_cnt[2]->line_length,
			&txtrs_cnt[2]->endian);
	txtrs_cnt[3]->addr = mlx_get_data_addr(txtrs_cnt[3]->img,
			&txtrs_cnt[3]->bits_per_pixel, &txtrs_cnt[3]->line_length,
			&txtrs_cnt[3]->endian);
	main->txts_cnt = txtrs_cnt;
	return (true);
}

bool	load_textures(t_main *main)
{
	t_txtr_cnt	**txts_cnt;
	int			i;

	txts_cnt = ft_malloc(main, sizeof(t_txtr_cnt *) * 4);
	if (!txts_cnt)
		return (false);
	i = 0;
	while (i < 4)
	{
		txts_cnt[i] = ft_malloc(main, sizeof(t_txtr_cnt));
		if (!txts_cnt[i])
			return (false);
		txts_cnt[i]->img = NULL;
		txts_cnt[i]->addr = NULL;
		i++;
	}
	if (!add_imgs(main, txts_cnt))
		return (false);
	main->txts_cnt = txts_cnt;
	return (true);
}

void	clean_textures(t_main *main)
{
	int	i;

	i = 0;
	if (main->txts_cnt)
	{
		while (i < 4)
		{
			if (main->txts_cnt[i] && main->txts_cnt[i]->img)
				mlx_destroy_image(main->vars->mlx, main->txts_cnt[i]->img);
			i++;
		}
	}
}
