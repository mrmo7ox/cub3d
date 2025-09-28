/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabounna <yabounna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 15:56:42 by moel-oua          #+#    #+#             */
/*   Updated: 2025/09/28 14:00:06 by yabounna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

double	normalize_angle(double angle)
{
	while (angle < 0)
		angle += 2.0 * M_PI;
	while (angle >= 2.0 * M_PI)
		angle -= 2.0 * M_PI;
	return (angle);
}
