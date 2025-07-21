/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-oua <moel-oua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 19:34:54 by moel-oua          #+#    #+#             */
/*   Updated: 2025/07/21 19:48:29 by moel-oua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

bool    check_up(char **map, int x, int y)
{
	while(x >= 0)
	{
		if((int)ft_strlen(map[x]) >= y && map[x][y] == '1')
			return (true);
		x--;
	}
	return (false);	
}

bool    check_down(char **map, int x, int y)
{
	while(map[x])
	{
		if((int)ft_strlen(map[x]) >= y && map[x][y] == '1')
			return (true);
		x++;
	}
	return (false);	
}

bool    check_left(char **map, int x, int y)
{
	if(!map && !*map)
		return (false);
	while(map[x][y])
	{
		if((int)ft_strlen(map[x]) >= y && map[x][y] == '1')
			return (true);
		y++;
	}
	return (false);	
}

bool    check_right(char **map, int x, int y)
{
	if(!map && !*map)
		return (false);
	while(map[x][y])
	{
		if((int)ft_strlen(map[x]) >= y && map[x][y] == '1')
			return (true);
		y--;
	}
	return (false);	
}

