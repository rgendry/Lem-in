/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_ants.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 13:54:41 by rgendry           #+#    #+#             */
/*   Updated: 2019/09/26 23:08:33 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int     calc_path(t_allway *map, int ants)
{
	int     paths;
	int     i;
	int     j;
	int     t;

	while (map->next)
		map = map->next;
	paths = 1;
	i = map->size + ants;
	j = 0;
	if (ants < map->gap)
		return (paths);
	while (map && map->prev)
	{
		t = (ants - map->gap) / paths;
		map = map->prev;
		j = map->size + t;
		if (j > i)
			return (paths--);
		i = j;
		paths++;
	}
	return (paths--);
}

size_t  len_list_map(t_allway *map)
{
	size_t len;

	len = 0;
	while (map->next)
	{
		len++;
		map = map->next;
	}
	return (len);
}

void	print_list(t_allway *list)
{
	t_allway *tmp;

	tmp = list;
	while (tmp)
	{
		printf("list->size: %d\n", tmp->size);
		tmp = tmp->next;
	}
}

int		check_head(t_allway *a)
{
	if (!a->prev)
		return (1);
	return (0);
}

t_allway	*swap_elems(t_allway *a, t_allway *b, t_allway **map)
{
	t_allway *a_prev;
	t_allway *b_next;

	if (check_head(a))
		*map = b;
	a_prev = a->prev;
	b_next = b->next;
	if (a_prev)
		a_prev->next = b;
	b->prev = a_prev;
	b->next = a;
	a->prev = b;
	a->next = b_next;
	if (b_next)
		b_next->prev = a;
	return b;
}

void    sort_list(t_allway **map)
{
	t_allway	*tmp;

	if (!map || !*map)
		return ;
	tmp = *map;
	while (tmp && tmp->next)
	{
		if (tmp->size > tmp->next->size)
		{
			tmp = swap_elems(tmp, tmp->next, map);
			if (tmp->prev)
				tmp = tmp->prev;
			continue ;
		}
		tmp = tmp->next;
	}
	printf("\n");
	print_list(*map);
}

void    go_ants(t_allway *map_oneway, t_allway *map, t_flag *fl)
{
	int         last_size;
	t_way       *temp;
	t_allway    *temp1;
	t_allway    *temp2;

	last_size = 2147483647;
	temp = map_oneway->go;
	map_oneway->size = 0;
	while (temp->next)
	{
		map_oneway->size++;
		temp = temp->next;
	}
	temp1 = map;
	while (temp1)
	{
		temp1->size = 0;
		temp = temp1->go;
		while (temp->next)
		{
			temp = temp->next;
			temp1->size++;
		}
		temp1 = temp1->next;
		if (!temp1)
			break ;
	}
	temp1 = map;
	// print_list(temp1);
	// printf("\n");
	sort_list(&temp1);
	while (temp1)
	{
		temp1->gap = last_size - temp1->size;
		last_size = temp1->size;
		// printf("size way =   %d\n", temp1->size);
		// printf("gap size =   %d\n", temp1->gap);
		temp1 = temp1->next;
		if (!temp1)
			break ;
	}
	temp1 = map;
	// printf("%d\n", calc_path(temp1, fl->ants));
}
