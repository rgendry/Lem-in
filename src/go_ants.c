/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_ants.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgendry <rgendry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 17:10:52 by rgendry           #+#    #+#             */
/*   Updated: 2019/10/21 20:41:54 by rgendry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_path	*find_min_path(t_path *paths)
{
	t_path	*result;
	t_path	*path;
	int		size;

	result = paths;
	size = result->size;
	path = paths;
	while (path)
	{
		if (size > path->size)
		{
			result = path;
			size = result->size;
		}
		path = path->next;
	}
	return (result);
}

void	split_ants(t_lem *lem, t_path *paths, t_group **group)
{
	t_path	*min_way;

	while (lem->ants)
	{
		min_way = find_min_path(paths);
		if (!check_groups(*group, min_way))
			add_group(group, create_group(min_way));
		min_way->size++;
		lem->ants--;
	}
}

int		print_line(t_lem *lem, t_ant *ants)
{
	int	end;
	int	count;

	end = lem->size - 1;
	count = 0;
	while (ants)
	{
		if (ants->node != end)
		{
			ants->node = ants->way->used[ants->node];
			ft_printf("L%d-%s", ants->name, lem->map[ants->node].name);
			if (ants->next && ants->way->used[ants->next->node] != end)
				ft_printf(" ");
			count = 1;
		}
		ants = ants->next;
	}
	if (count)
		ft_printf("\n");
	return (count);
}

void	set_ants(t_lem *lem, t_group *group, t_ant **ants)
{
	int		ant;
	int		count;
	t_group	*curr;

	ant = 1;
	count = 1;
	while (count)
	{
		count = 0;
		curr = group;
		while (curr)
		{
			if (curr->ants)
			{
				add_ant(ants, create_ant(ant, curr->path));
				ant++;
				curr->ants--;
				count = 1;
			}
			curr = curr->next;
		}
		print_line(lem, *ants);
	}
}

void	go_ants(t_lem *lem, t_path *paths)
{
	int		count;
	t_ant	*ants;
	t_group	*group;

	group = NULL;
	ants = NULL;
	split_ants(lem, paths, &group);
	set_ants(lem, group, &ants);
	count = 1;
	while (count)
		count = print_line(lem, ants);
	free_groups(&group);
	free_ants(&ants);
}
