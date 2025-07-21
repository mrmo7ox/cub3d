/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-oua <moel-oua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 17:03:54 by moel-oua          #+#    #+#             */
/*   Updated: 2025/07/20 16:49:32 by moel-oua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"


int main(int ac, char **dc)
{
	t_main	main;
	t_gc	*gc;

	if(ac != 2)
	{
		ft_putstr_fd("[KO] INVALID NUMBER OF ARGS\n", 2);
		return (1);
	}
	gc = NULL;
	main.gc = &gc;
	if (!file(dc, &main) || !txtrs_clrs(&main))
		return (1);
	ft_cleangc(main.gc);
	return (0);

}