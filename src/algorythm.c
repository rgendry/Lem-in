/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorythm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgendry <rgendry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 21:11:49 by rgendry           #+#    #+#             */
/*   Updated: 2019/10/22 18:23:56 by rgendry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		*create_arr(int size)
{
	int	i;
	int	*arr;

	i = 0;
	arr = (int *)malloc(sizeof(int) * size);
	while (i < size)
	{
		arr[i] = 0;
		i++;
	}
	return (arr);
}

t_int	*delete(t_int *links, int l)
{
	t_int	*tmp;
	t_int	*prev;

	if (links->integer == l)
	{
		tmp = links->next;
		free(links);
		return (tmp);
	}
	tmp = links;
	while (tmp)
	{
		if (tmp->integer == l)
		{
			prev->next = tmp->next;
			free(tmp);
			break ;
		}
		prev = tmp;
		tmp = tmp->next;
	}
	return (links);
}

void	del_used(t_lem *lem, int *used)
{
	int		i;
	int		end;
	int		node;
	t_int	*queue;

	i = 0;
	end = lem->size - 1;
	while (i != end)
	{
		if (used[i] != 0 && used[i] != end)
		{
			queue = lem->map[used[i]].links;
			while (queue)
			{
				node = queue->integer;
				queue = queue->next;
				lem->map[used[i]].links = delete(lem->map[used[i]].links, node);
				lem->map[node].links = delete(lem->map[node].links, used[i]);
			}
		}
		i = used[i];
	}
}

void	algorythm(t_lem *lem, t_path **paths)
{
	int		start;
	t_path	*way;

	start = 0;
	*paths = NULL;
	while (1)
	{
		index_status(lem);
		way = create_path(create_arr(lem->size), create_int(start));
		find_path(lem, way);
		if (check_path(lem, way->used))
		{
			del_path(&way);
			return ;
		}
		way->size = path_size(way->used, lem->size - 1);
		add_path(paths, way);
		del_used(lem, way->used);
		set_new_map(lem);
	}
}
