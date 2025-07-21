/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   txtrs_clrs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-oua <moel-oua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 10:37:20 by moel-oua          #+#    #+#             */
/*   Updated: 2025/07/20 19:57:58 by moel-oua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

bool	chckadd_txtrs(char **splited, t_main *main)
{
	if(!main->txtrs->done)
	{	
		if(!main->txtrs || ft_dplen(splited) != 2)
			return (false);
		if(!ft_strcmp("SO", splited[0]))
		{
			main->txtrs->so = splited[1];
			return (true);
		}
		if(!ft_strcmp("NO", splited[0]))
		{
			main->txtrs->no = splited[1];
			return (true);
		}
		if(!ft_strcmp("WE", splited[0]))
		{
			main->txtrs->we = splited[1];
			return (true);
		}
		if(!ft_strcmp("EA", splited[0]))
		{
			main->txtrs->ea = splited[1];
			return (true);
		}
	}
	return (false);
}


bool	clrs_txtrs_done(t_main *main)
{
	if (main->txtrs->so && main->txtrs->ea && main->txtrs->no && main->txtrs->we)
		main->txtrs->done = (true);
	if (main->colors->c && main->colors->f)
		main->colors->done = (true);
	if(main->colors->done && main->txtrs->done)
		return (true);
	return (false);
}

bool	check_add(char **splited,t_main *main)
{
	if (!chckadd_clrs(splited, main) && !chckadd_txtrs(splited, main))
		return (false); 
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
	main->colors->c = 0;
	main->colors->f = 0;
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
				printf("invalid map\n");
				return (false);
			}
			printf("{OK} valid map\n");
			return (true);
		}
		// printf("=====================\n");
		// printf("%s\n", main->txtrs->ea);
		// printf("%s\n", main->txtrs->so);
		// printf("%s\n", main->txtrs->we);
		// printf("%s\n", main->txtrs->no);
		// printf("%d\n", main->colors->c);
		// printf("%d\n", main->colors->f);
		// printf("%d\n", main->colors->done);
		// printf("%d\n", main->txtrs->done);
		i++;
	}
	return (true);
}
