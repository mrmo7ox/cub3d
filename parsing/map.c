/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-oua <moel-oua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 16:37:20 by moel-oua          #+#    #+#             */
/*   Updated: 2025/07/21 19:55:53 by moel-oua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	end_map(t_main *main)
{
	int	i;

	i = ft_dplen(main->fcnt) - 1;
	while (i > 0 && !ft_rmlstsp(main->fcnt[i], main))
		i--;
	return (i);
}

bool	getmap(int last,t_main *main)
{
	int	end;
	int	i;

	i = 0;
	end = end_map(main);
	if(end <= last)
		return (false);
	main->map->content = ft_malloc(main, ((end - last) + 2) * sizeof(char *));
	if (!main->map->content)
		return (false);
	while(end >= last)
	{
		main->map->content[i] = ft_rmlstsp(main->fcnt[last], main);
		i++;
		last++;
	}
	main->map->content[i] = NULL;
	return (true);
}

bool validchr(char c, t_main *main) {
	if(c == '0' || c == '1' || c == ' ')
		return (true);
	if(c == 'N' || c == 'S' || c == 'E' || c == 'W')
	{
		main->map->player = c;
		return (true);
	}
    return (false);
}




bool	vld_map(t_main *main)
{
	int		x;
	int		y;
	char	**map;

	map = main->map->content;
	x = 0;
	while(map[x])
	{	
		y = 0;
		while(map[x][y])
		{
			if(!validchr(map[x][y], main))
				return (false);
			if(map[x][y] == '0')
			{
				printf("%c", map[x][y]);
				if(!check_up(map, x, y))
					return (false);
				if(!check_down(map, x, y))
					return (false);
				if(!check_left(map, x, y))
					return (false);
				if(!check_right(map, x, y))
					return (false);
			}
			printf("\n");
			y++;
		}
		x++;
	}
	return (true);
}
bool	init_map(int last,t_main *main)
{
	main->map = ft_malloc(main, sizeof(t_map));
	main->map->player = 0;
	if (!main->map)
		return (false);
	if (!getmap(last, main))
		return (false);
	if (!main->map->content)
		return (false);
	if (!vld_map(main))
		return (false);
	// if (!main->map->player)
	// 	return (false);
	return (true);
}

bool    parsemap(int last, t_main *main)
{
	while (is_allwspace(main->fcnt[last]))
		last++;
	if (!init_map(last, main))
		return (false);
	return (true);
}
