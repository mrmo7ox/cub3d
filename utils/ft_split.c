/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-oua <moel-oua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 10:40:10 by moel-oua          #+#    #+#             */
/*   Updated: 2025/09/14 10:04:20 by moel-oua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

static void	ft_copy(char *dest, char *src, int len)
{
	int	i;

	i = 0;
	while (src[i] && i < len)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

static int	strlen_mod(char *str)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (str[i] != '\0')
	{
		while (ft_whitespaces(str[i]) && str[i] != '\0')
			i++;
		if (!ft_whitespaces(str[i]) && str[i] != '\0')
			words++;
		while (!ft_whitespaces(str[i]) && str[i] != '\0')
			i++;
	}
	return (words);
}

size_t	ft_dplen(char **dp)
{
	size_t	i;

	if (!dp || !*dp)
		return (0);
	i = 0;
	while (dp[i])
	{
		i++;
	}
	return (i);
}

char	**ft_splitwhite(char *str, t_main *main, int i, int j)
{
	char	**res;
	int		words;

	words = strlen_mod(str);
	res = ft_malloc(main, sizeof(char *) * (words + 1));
	if (!res)
		return (NULL);
	i = 0;
	words = 0;
	while (str[i])
	{
		while (str[i] && ft_whitespaces(str[i]))
			i++;
		j = i;
		while (str[i] && !ft_whitespaces(str[i]))
			i++;
		if (i > j)
		{
			res[words] = ft_malloc(main, sizeof(char) * ((i - j) + 1));
			if (!res[words])
				return (NULL);
			(ft_copy(res[words], &str[j], (i - j)), words++);
		}
	}
	return (res[words] = NULL, res);
}
