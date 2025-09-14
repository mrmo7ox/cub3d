/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-oua <moel-oua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 10:14:01 by moel-oua          #+#    #+#             */
/*   Updated: 2025/09/14 10:16:39 by moel-oua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

bool	map_checker(char **map, int x, int y)
{
	if (!check_up(map, x, y))
		return (false);
	if (!check_down(map, x, y))
		return (false);
	if (!check_left(map, x, y))
		return (false);
	if (!check_right(map, x, y))
		return (false);
	return (true);
}
