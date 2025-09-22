/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   txtrs_clrs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-oua <moel-oua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 10:37:20 by moel-oua          #+#    #+#             */
/*   Updated: 2025/09/14 11:32:39 by moel-oua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

bool	check_add(char **splited, char *original, t_main *main)
{
	if (!chckadd_clrs(splited, main) && !chckadd_txtrs(splited, original, main))
	{
		ft_putstr_fd("Error\nInvalid Colors or Textures\n", 2);
		return (false);
	}
	return (true);
}

bool	txt_clrs_init(t_main *main)
{
	main->txtrs = ft_malloc(main, sizeof(t_txtrs));
	if (!main->txtrs)
		return (false);
	main->colors = ft_malloc(main, sizeof(t_clrs));
	if (!main->colors)
		return (false);
	main->colors->c = -69;
	main->colors->f = -69;
	main->txtrs->ea = 0;
	main->txtrs->no = 0;
	main->txtrs->so = 0;
	main->txtrs->we = 0;
	main->txtrs->done = false;
	main->colors->done = false;
	return (true);
}

bool	handle_texture_color_line(t_main *main, int i)
{
	char	**splited;

	if (is_allwspace(main->fcnt[i]))
		return (true);
	splited = ft_splitwhite(main->fcnt[i], main, 0, 0);
	if (!splited)
		return (false);
	if (!check_add(splited, main->fcnt[i], main))
		return (false);
	return (true);
}

bool	handle_parsing_completion(t_main *main, int i)
{
	if (!parsemap(i, main))
	{
		ft_putstr_fd("Error\nInvalid Map\n", 2);
		return (false);
	}
	return (true);
}

bool	txtrs_clrs(t_main *main)
{
	int	i;

	i = 0;
	if (!main->fcnt || !main->fcnt[i] || !txt_clrs_init(main))
		return (false);
	while (main->fcnt[i])
	{
		if (!clrs_txtrs_done(main))
		{
			if (!handle_texture_color_line(main, i))
				return (false);
		}
		else
		{
			if (!handle_parsing_completion(main, i))
				return (false);
			return (true);
		}
		i++;
	}
	return (true);
}
