/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniatoi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-oua <moel-oua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 11:23:21 by moel-oua          #+#    #+#             */
/*   Updated: 2025/09/14 10:03:36 by moel-oua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	miniatoi(const char *ptr)
{
	int		sign;
	long	total;

	sign = 1;
	total = 0;
	if (!ptr || !*ptr)
		return (-1);
	while (*ptr == ' ' || *ptr == '\t')
		ptr++;
	while (*ptr >= '0' && *ptr <= '9')
	{
		total = (total * 10) + (*ptr - '0');
		if (total > 255)
			return (-1);
		ptr++;
	}
	if (*ptr && (*ptr < '0' || *ptr > '9'))
		return (-1);
	return ((int)(total * sign));
}
