/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabounna <yabounna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 17:03:54 by moel-oua          #+#    #+#             */
/*   Updated: 2025/09/28 09:27:38 by yabounna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	main(int ac, char **dc)
{
	t_main	main;
	t_gc	*gc;
	t_dist	*dst;

	dst = NULL;
	main.dist = &dst;
	if (ac != 2)
	{
		ft_putstr_fd("Error\nInvalid Args Number\n", 2);
		return (1);
	}
	gc = NULL;
	main.gc = &gc;
	if (!file(dc, &main) || !txtrs_clrs(&main))
	{
		ft_cleangc(main.gc);
		return (1);
	}
	run(&main);
	ft_cleangc(main.gc);
	return (0);
}
