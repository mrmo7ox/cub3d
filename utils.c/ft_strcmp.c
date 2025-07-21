/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-oua <moel-oua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 17:54:28 by moel-oua          #+#    #+#             */
/*   Updated: 2025/07/19 17:54:47 by moel-oua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	if (!s1 || !s2)
		return (1);
	while ((unsigned char)s1[i] == (unsigned char)s2[i] && s1[i] != '\0'
		&& s2[i] != '\0')
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
