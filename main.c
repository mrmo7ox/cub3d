/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-oua <moel-oua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 17:03:54 by moel-oua          #+#    #+#             */
/*   Updated: 2025/07/22 17:35:32 by moel-oua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void ff() {
	system("leaks cub");
}

int main(int ac, char **dc)
{
	// atexit(ff);
	t_main	main;
	t_gc	*gc;
	t_dist *dst;

	dst = NULL;
	main.dist = &dst;

	if(ac != 2)
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