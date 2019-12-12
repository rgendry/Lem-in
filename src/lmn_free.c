/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lmn_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgendry <rgendry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 15:50:39 by mfahey            #+#    #+#             */
/*   Updated: 2019/10/24 18:45:22 by rgendry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	free_nodes(t_node **nodes)
{
	t_node	*node;
	t_node	*next;

	node = *nodes;
	while (node)
	{
		next = node->next;
		ft_strdel(&(node->name));
		node->next = NULL;
		free(node);
		node = next;
	}
	*nodes = NULL;
}

void	free_map(t_lem *lem, t_map **map)
{
	int	i;

	i = 0;
	while (i < lem->size)
	{
		(*map)[i].name = NULL;
		free_int(&((*map)[i].links));
		i++;
	}
	free(*map);
	*map = NULL;
}

void	free_lem(t_lem *lem)
{
	free(&(lem->start->name));
	free(lem->start);
	free(&(lem->end->name));
	free(lem->end);
	ft_strdel(&(lem->buff));
	free_nodes(&(lem->nodes));
	lem->nodes = NULL;
	free_links(&(lem->links));
	lem->links = NULL;
	free_map(lem, &(lem->map));
	free(lem);
	lem = NULL;
}

void	free_paths(t_path **paths)
{
	t_path	*path;
	t_path	*next;

	path = *paths;
	while (path)
	{
		next = path->next;
		free(path->used);
		path->used = NULL;
		free_int(&(path->queue));
		path->queue = NULL;
		path->next = NULL;
		free(path);
		path = next;
	}
	paths = NULL;
}
