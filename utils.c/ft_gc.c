/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-oua <moel-oua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 17:19:41 by moel-oua          #+#    #+#             */
/*   Updated: 2025/07/20 11:33:43 by moel-oua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"


t_gc	*ft_newgc(void *addres)
{
	t_gc	*node;

	node = malloc(sizeof(t_gc));
	if (!node)
	{
	   	if(DEBUG)
			ft_putstr_fd("[24] ft_newgc < i can't allocate using malloc>\n", 2);
		return (NULL);
	}
	node->addres = addres;
	node->next = NULL;
	return (node);
}

bool	ft_addgc(t_gc **head, t_gc *node)
{
	t_gc	*last;

	if (!head || !node)
	{
		if(DEBUG)
			ft_putstr_fd("[39] ft_addgc < i can't find one of theses !head || *head || !node >\n", 2);
		return (false);
	}
	if (!*head)
	{
		*head = node;
		return (true);
	}

	last = *head;
	while(last->next)
		last = last->next;
	if(!last)
	{
		if(DEBUG)
			ft_putstr_fd("[48] ft_addgc < problem with the last veraible he is NULL >\n", 2);
		return (false);
	}
	last->next = node;
	return (true);
}

void	*ft_malloc(t_main *main, size_t size)
{
	void	*el;

	el = malloc(size);
	if (!el)
		return (NULL);
	if(!ft_addgc(main->gc, ft_newgc(el)))
	{
		free(el);
		if(DEBUG)
			ft_putstr_fd("[53] ft_malloc < i can't add addres to the list>\n", 2);
		return (NULL);
	}
	return (el);
}

void   ft_cleangc(t_gc **head)
{
	t_gc	*tmp;
	t_gc	*next;

	if(!*head || !head)
		return ;
	tmp = *head;
	while(tmp)
	{
		next = tmp->next;
		free(tmp->addres);
		free(tmp);
 		tmp = next;
	}
}