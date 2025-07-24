/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   txtrs_clrs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-oua <moel-oua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 10:37:20 by moel-oua          #+#    #+#             */
/*   Updated: 2025/07/22 12:54:02 by moel-oua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

bool	txturs_test(char *path, char **txtvar)
{
	int	fd;

	if(*txtvar)
		return (false);
	fd = open(path, O_RDONLY);
	if(fd == -1)
		return (false);
	*txtvar = path;
	close(fd);
	return (true);
}

bool	chckadd_txtrs(char **splited, t_main *main)
{
	if(!main->txtrs->done)
	{	
		if(!main->txtrs || ft_dplen(splited) != 2)
			return (false);
		else if(!ft_strcmp("SO", splited[0]))
			return (txturs_test(splited[1], &main->txtrs->so));
		else if(!ft_strcmp("NO", splited[0]))
			return (txturs_test(splited[1], &main->txtrs->no));
		else if(!ft_strcmp("WE", splited[0]))
			return (txturs_test(splited[1], &main->txtrs->we));
		else if(!ft_strcmp("EA", splited[0]))
			return (txturs_test(splited[1], &main->txtrs->ea));
		
	}
	return (false);
}


bool	clrs_txtrs_done(t_main *main)
{
	if (main->txtrs->so && main->txtrs->ea && main->txtrs->no && main->txtrs->we)
		main->txtrs->done = (true);
	if (main->colors->c != -69 && main->colors->f != -69)
		main->colors->done = (true);
	if(main->colors->done && main->txtrs->done)
		return (true);
	return (false);
}

bool	check_add(char **splited,t_main *main)
{
	if (!chckadd_clrs(splited, main) && !chckadd_txtrs(splited, main))
	{
		ft_putstr_fd("Error\nInvalid Colors or Textures\n", 2);
		return (false);
	}
	return (true);
}

bool	txt_clrs_init(t_main *main)
{
	main->txtrs = ft_malloc(main, sizeof(t_txtrs));
	if(!main->txtrs)
		return(false);
	main->colors = ft_malloc(main, sizeof(t_clrs));
	if(!main->colors)
		return(false);
	main->colors->c = -69;
	main->colors->f = -69;
	main->txtrs->ea = 0;
	main->txtrs->no = 0;
	main->txtrs->so = 0;
	main->txtrs->we = 0;
	return (true);
}

bool	txtrs_clrs(t_main *main)
{
	int	i;
	char **splited;

	i = 0;
	if(!main->fcnt[i] || !main->fcnt || !txt_clrs_init(main))
		return (false);
	while(main->fcnt[i])
	{
		if(!clrs_txtrs_done(main))
		{
			if(is_allwspace(main->fcnt[i]))
			{
				i++;
				continue;
			}
			splited = ft_splitwhite(main->fcnt[i], main, 0, 0);
			if(!splited)
				return (false);
			if(!check_add(splited, main))
				return (false);
		}
		else
		{
			if(!parsemap(i, main))
			{
				ft_putstr_fd("Error\nInvalid Map\n", 2);
				return (false);
			}
			return (true);
		}
		i++;
	}
	return (true);
}
