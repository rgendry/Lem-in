/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgendry <rgendry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 21:52:01 by rgendry           #+#    #+#             */
/*   Updated: 2019/10/14 18:20:54 by rgendry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	set_status(t_lem *lem, t_int **path)
{
	int		end;
	t_int	*queue;

	end = get_int(path);
	queue = lem->map[end].links;
	while (queue)
	{
		if (queue->integer && queue->integer != lem->size - 1 &&
			lem->map[queue->integer].status == 2147483647)
		{
			if (lem->map[queue->integer].status > lem->map[end].status + 1 ||
				lem->map[queue->integer].status == 2147483647)
				lem->map[queue->integer].status = lem->map[end].status + 1;
			add_int(path, create_int(queue->integer));
		}
		queue = queue->next;
	}
}

void	index_status(t_lem *lem)
{
	int		end;
	t_int	*path;

	end = lem->size - 1;
	path = create_int(end);
	lem->map[end].status = 0;
	while (path)
		set_status(lem, &path);
}
