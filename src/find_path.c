/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgendry <rgendry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 14:06:12 by rgendry           #+#    #+#             */
/*   Updated: 2019/10/14 18:33:04 by rgendry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		find_min_status(t_lem *lem, t_int *queue, t_path *way)
{
	int	status;
	int	node;

	status = 2147483647;
	node = -1;
	while (queue)
	{
		if (!way->used[queue->integer] &&
			status > lem->map[queue->integer].status)
		{
			status = lem->map[queue->integer].status;
			node = queue->integer;
		}
		queue = queue->next;
	}
	return (node);
}

void	find_path(t_lem *lem, t_path *way)
{
	int	end;
	int	node;
	int	curr;

	end = lem->size - 1;
	if (way->queue)
	{
		curr = get_int(&(way->queue));
		node = find_min_status(lem, lem->map[curr].links, way);
		if (node == -1 || curr >= lem->size)
			return ;
		if (lem->map[curr].status > lem->map[node].status &&
			(!way->used[node] || node == end))
		{
			way->used[curr] = node;
			if (node != end)
			{
				add_int(&way->queue, create_int(node));
				find_path(lem, way);
			}
		}
	}
}
