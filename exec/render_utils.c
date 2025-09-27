/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-oua <moel-oua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 10:36:51 by moel-oua          #+#    #+#             */
/*   Updated: 2025/09/14 13:50:12 by moel-oua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	draw_plafond(t_main *main, int i, int draw_debut)
{
	int	y;

	y = 0;
	while (y < draw_debut)
	{
		draw_pxl(main->img, i, y, main->colors->c);
		y++;
	}
}

void	draw_sol(t_main *main, int i, int draw_fin)
{
	int	y;

	y = draw_fin + 1;
	while (y < HEIGHT)
	{
		draw_pxl(main->img, i, y, main->colors->f);
		y++;
	}
}

unsigned int	get_pixel_color(t_txtr_cnt *texture, int x, int y)
{
	char	*dst;
	int		offset;

	if (!texture || !texture->addr || x < 0 || x >= texture->width || y < 0
		|| y >= texture->height)
		return (0xFF0000);
	offset = y * texture->line_length + x * (texture->bits_per_pixel / 8);
	dst = texture->addr + offset;
	return (*(unsigned int *)dst);
}
