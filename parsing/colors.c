/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabounna <yabounna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 16:50:04 by moel-oua          #+#    #+#             */
/*   Updated: 2025/09/28 09:27:57 by yabounna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	parse_color(char *color, t_main *main)
{
	int		i;
	int		shift;
	char	**colors;
	int		res;

	res = 0;
	if (ft_countchr(',', color) != 2)
		return (-1);
	colors = ft_split(color, main, 0, 0);
	if (ft_dplen(colors) != 3)
		return (-1);
	shift = 16;
	i = 0;
	while (colors[i])
	{
		if (miniatoi(colors[i]) == -1)
			return (-1);
		res |= (miniatoi(colors[i])) << shift;
		i++;
		shift -= 8;
	}
	return (res);
}

bool	chckadd_clrs(char **splited, t_main *main)
{
	if (!main->txtrs || ft_dplen(splited) != 2)
		return (false);
	if (!main->colors->done)
	{
		if (!ft_strcmp("F", splited[0]))
		{
			if (main->colors->f != -69)
				return (false);
			main->colors->f = parse_color(splited[1], main);
			if (main->colors->f == -1)
				return (false);
			return (true);
		}
		if (!ft_strcmp("C", splited[0]))
		{
			if (main->colors->c != -69)
				return (false);
			main->colors->c = parse_color(splited[1], main);
			if (main->colors->c == -1)
				return (false);
			return (true);
		}
	}
	return (false);
}
