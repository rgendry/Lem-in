/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_node.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgendry <rgendry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 20:25:17 by rgendry           #+#    #+#             */
/*   Updated: 2019/10/24 17:29:14 by rgendry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		check_node(char *name, char *x, char *y, t_lem *lem)
{
	t_node *head;

	head = lem->nodes;
	while (lem->nodes)
	{
		if (name[0] == 'L')
			return (0);
		if (!ft_strcmp(name, lem->nodes->name))
			return (0);
		if (lem->nodes->x == ft_atoi(x) && lem->nodes->y == ft_atoi(y))
			return (0);
		lem->nodes = lem->nodes->next;
	}
	lem->nodes = head;
	return (1);
}

t_node	*create_node(char *name, char *x, char *y)
{
	t_node	*new;

	if (!(new = (t_node*)malloc(sizeof(t_node))))
		error();
	new->name = ft_strdup(name);
	new->x = ft_atoi(x);
	new->y = ft_atoi(y);
	new->next = NULL;
	return (new);
}

void	push_node(t_node *node, t_lem *lem)
{
	t_node	*head;

	head = lem->nodes;
	if (head)
	{
		node->next = lem->nodes;
		lem->nodes = node;
	}
	else
		lem->nodes = node;
}

void	add_node(t_node *node, t_lem *lem)
{
	t_node	*next;

	next = lem->nodes;
	if (next)
	{
		while (next->next)
			next = next->next;
		next->next = node;
	}
	else
		lem->nodes = node;
}

void	get_node(char *line, t_lem *lem)
{
	char	**data;
	t_node	*node;

	data = ft_strsplit(line, ' ');
	if (arr_len(data) != 3 || !(check_int(data[1])) || !(check_int(data[2])))
	{
		free_arr(&data);
		error();
	}
	if (check_node(data[0], data[1], data[2], lem))
	{
		node = create_node(data[0], data[1], data[2]);
		push_node(node, lem);
		lem->size++;
	}
	else
	{
		free_arr(&data);
		ft_strdel(&line);
		error();
	}
	free_arr(&data);
	ft_strdel(&line);
}
