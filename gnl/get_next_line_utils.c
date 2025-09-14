/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-oua <moel-oua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 13:47:56 by moel-oua          #+#    #+#             */
/*   Updated: 2025/07/20 09:47:33 by moel-oua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

char	*ft_strjoin(const char *s1, const char *s2, t_main *main)
{
	int		len_s1;
	int		len_s2;
	char	*new;

	if (!s1)
		return (ft_strdup(s2, main));
	if (!s2)
		return (ft_strdup(s1, main));
	if (!s2 && !s1)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	new = ft_malloc(main, sizeof(char) * (1 + len_s1 + len_s2));
	if (new == NULL)
		return (NULL);
	ft_memcpy (new, s1, len_s1);
	ft_memcpy (new + len_s1, s2, len_s2);
	new[len_s1 + len_s2] = '\0';
	return (new);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}
