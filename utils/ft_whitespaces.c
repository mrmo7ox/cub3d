/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_whitespaces.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-oua <moel-oua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 18:06:23 by moel-oua          #+#    #+#             */
/*   Updated: 2025/09/14 10:03:41 by moel-oua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

bool	ft_whitespaces(char chr)
{
	if ((chr >= 9 && chr <= 13) || (chr == ' '))
		return (true);
	return (false);
}

bool	is_allwspace(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (NULL);
	while (ft_whitespaces(str[i]))
		i++;
	if (i == ft_strlen(str))
		return (true);
	return (false);
}
