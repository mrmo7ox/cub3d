/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rmlstsp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-oua <moel-oua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 17:57:18 by moel-oua          #+#    #+#             */
/*   Updated: 2025/09/14 10:04:28 by moel-oua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

char	*ft_rmlstsp(char *str, t_main *main)
{
	int		i;
	char	*new;

	if (!str || !*str)
		return (NULL);
	i = ft_strlen(str) - 1;
	while (i > 0 && ft_whitespaces(str[i]))
	{
		i--;
	}
	if (i <= 0)
		return (NULL);
	i++;
	new = ft_substr(str, 0, i, main);
	if (!new)
		return (NULL);
	return (new);
}

char	*ft_rmlstspmap(char *str, t_main *main)
{
	int		i;
	char	*new;

	if (!str || !*str)
		return (NULL);
	i = ft_strlen(str) - 1;
	while (i > 0 && ft_whitespaces(str[i]))
	{
		i--;
	}
	if (i <= 0)
		return (ft_strdup("", main));
	i++;
	new = ft_substr(str, 0, i, main);
	if (!new)
		return (ft_strdup("", main));
	return (new);
}
