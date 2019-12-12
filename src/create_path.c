/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgendry <rgendry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 17:53:58 by rgendry           #+#    #+#             */
/*   Updated: 2019/10/12 18:00:35 by rgendry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_path	*create_path(int *used, t_int *queue)
{
	t_path	*new;

	if (!(new = (t_path *)malloc(sizeof(t_path))))
		error();
	new->size = 0;
	new->used = used;
	new->queue = queue;
	new->next = NULL;
	return (new);
}

int		path_size(int *used, int end)
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	while (i != end)
	{
		size++;
		if (!used[i])
			return (i);
		i = used[i];
	}
	return (size);
}

int		check_path(t_lem *lem, int *used)
{
	int	i;
	int	end;

	i = 0;
	end = lem->size - 1;
	if (!used[i])
		return (1);
	while (i != end)
	{
		if (!used[i])
			return (i);
		i = used[i];
	}
	return (0);
}

void	del_path(t_path **way)
{
	t_path	*head;

	while (*way)
	{
		head = (*way)->next;
		(void)(*way)->size;
		free((*way)->used);
		free(*way);
		(*way) = head;
	}
}

void	add_path(t_path **head, t_path *data)
{
	t_path	*next;

	next = *(head);
	if (next)
	{
		while (next->next)
			next = next->next;
		next->next = data;
	}
	else
		*head = data;
}
