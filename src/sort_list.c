/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 17:21:23 by idunaver          #+#    #+#             */
/*   Updated: 2019/09/30 17:24:00 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

size_t			len_list_map(t_allway *map)
{
	size_t	len;

	len = 0;
	while (map->next)
	{
		len++;
		map = map->next;
	}
	return (len);
}

static int		check_head(t_allway *a)
{
	if (!a->prev)
		return (1);
	return (0);
}

static t_allway	*swap_elems(t_allway *a, t_allway *b, t_allway **map)
{
	t_allway	*a_prev;
	t_allway	*b_next;

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
	return (b);
}

void			sort_list(t_allway **map)
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
}
