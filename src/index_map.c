/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfahey <mfahey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 19:44:03 by rgendry           #+#    #+#             */
/*   Updated: 2019/10/19 15:11:17 by mfahey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		find_link(t_node *node, char *name, int size)
{
	while (node)
	{
		size--;
		if (!ft_strcmp(node->name, name))
			return (size);
		node = node->next;
	}
	error();
	return (0);
}

void	set_map(t_lem *lem)
{
	int		x;
	int		y;
	t_link	*link;

	link = lem->links;
	while (link)
	{
		x = find_link(lem->nodes, link->name1, lem->size);
		y = find_link(lem->nodes, link->name2, lem->size);
		add_int(&(lem->map)[x].links, create_int(y));
		add_int(&(lem->map)[y].links, create_int(x));
		lem->map[x].name = link->name1;
		lem->map[y].name = link->name2;
		link = link->next;
	}
}

t_map	*create_map(int size)
{
	int		i;
	t_map	*new;

	i = 0;
	if (!(new = (t_map *)malloc(sizeof(t_map) * size)))
		error();
	while (i < size)
	{
		new[i].links = NULL;
		new[i].name = NULL;
		new[i].status = 2147483647;
		i++;
	}
	return (new);
}

void	index_map(t_lem *lem)
{
	lem->map = create_map(lem->size);
	set_map(lem);
}

void	set_new_map(t_lem *lem)
{
	int	i;

	i = 0;
	while (i < lem->size)
	{
		lem->map[i].status = 2147483647;
		i++;
	}
}
