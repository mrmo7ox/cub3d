#include "../cub.h"

t_dist	*ft_newdist(t_main *main, double dist)
{
	t_dist	*node;

	node =  ft_malloc(main, sizeof(t_dist));
	if (!node)
		return (NULL);
	node->dist = dist;
	node->next = NULL;
	return (node);
}

bool	ft_adddist(t_dist **head, t_dist *node)
{
	t_dist	*last;

	if (!head || !node)
		return (false);
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
		return (false);
	}
	last->next = node;
	return (true);
}