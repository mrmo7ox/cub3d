/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   txtrs_clrs_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabounna <yabounna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 09:26:30 by yabounna          #+#    #+#             */
/*   Updated: 2025/09/28 09:26:38 by yabounna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

bool	txturs_test(char *path, char **txtvar)
{
	int	fd;

	if (*txtvar)
		return (false);
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (false);
	*txtvar = path;
	close(fd);
	return (true);
}

char	*orignal_path(t_main *main, char *str)
{
	str = formating(str, main);
	if (!str)
		return (NULL);
	str += 2;
	if (!str)
		return (NULL);
	str = formating(str, main);
	if (!str)
		return (NULL);
	if (!valid_ext(str, main, ".xpm"))
		return (NULL);
	return (str);
}

bool	chckadd_txtrs(char **splited, char *original, t_main *main)
{
	if (!main->txtrs->done)
	{
		if (!main->txtrs || ft_dplen(splited) < 2)
			return (false);
		else if (!ft_strcmp("SO", splited[0]))
			return (txturs_test(orignal_path(main, original),
					&main->txtrs->so));
		else if (!ft_strcmp("NO", splited[0]))
			return (txturs_test(orignal_path(main, original),
					&main->txtrs->no));
		else if (!ft_strcmp("WE", splited[0]))
			return (txturs_test(orignal_path(main, original),
					&main->txtrs->we));
		else if (!ft_strcmp("EA", splited[0]))
			return (txturs_test(orignal_path(main, original),
					&main->txtrs->ea));
	}
	return (false);
}

bool	clrs_txtrs_done(t_main *main)
{
	if (main->txtrs->so && main->txtrs->ea && main->txtrs->no
		&& main->txtrs->we)
		main->txtrs->done = (true);
	if (main->colors->c != -69 && main->colors->f != -69)
		main->colors->done = (true);
	if (main->colors->done && main->txtrs->done)
		return (true);
	return (false);
}
