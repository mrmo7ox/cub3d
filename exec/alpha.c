/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alpha.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-oua <moel-oua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 13:47:54 by moel-oua          #+#    #+#             */
/*   Updated: 2025/07/28 14:22:27 by moel-oua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	draw_bg(t_main *main)
{
	int		x;
	int		y;
	bool	flag;

	y = 0;
	flag = false;
	while((y * 10) <= MSIZE)
	{
		x = 0;
		while((x * 10 ) <= MSIZE)
		{
			if(!flag)
				draw_sq(main->img, x * 10 , y * 10, 10 ,0xcfcfcf);
			else
				draw_sq(main->img, x * 10 , y * 10, 10, 0x8a8888);
			flag = !flag;
			x += 1;
		}
		y += 1;
	}
	y = 0;
	while((y * 5) <= MSIZE + 5)
	{
		x = 0;
		while((x * 5) <= MSIZE + 5)
		{
			if(x == 0)
				draw_sq(main->img, x * 5 , y * 5, 5 ,0xff0000);
			if(y == 0)
				draw_sq(main->img, x * 5 , y * 5, 5 ,0xff0000);
			if((x * 5) == MSIZE + 5)
				draw_sq(main->img, x * 5 , y * 5, 5 ,0xff0000);
			if((y * 5) == MSIZE + 5)
				draw_sq(main->img, x * 5 , y * 5, 5 ,0xff0000);
			x += 1;
		}
		y += 1;
	}

}

void	draw_bg_2(t_main *main)
{
	int		x;
	int		y;
	bool	flag;
	int size;

	size = 50;
	y = 0;
	flag = false;
	while((y * size) <= HEIGHT)
	{
		x = 0;
		while((x * size ) <= WIDTH)
		{
			if(!flag)
				draw_sq(main->img, x * size , y * size, size ,0xcfcfcf);
			else
				draw_sq(main->img, x * size , y * size, size, 0x8a8888);
			flag = !flag;
			x += 1;
		}
		y += 1;
	}
}