/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_ant.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgendry <rgendry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 15:40:38 by rgendry           #+#    #+#             */
/*   Updated: 2019/10/21 20:36:23 by rgendry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_ant	*create_ant(int name, t_path *path)
{
	t_ant	*new;

	if (!(new = (t_ant *)malloc(sizeof(t_ant))))
		error();
	new->name = name;
	new->node = 0;
	new->way = path;
	new->next = NULL;
	return (new);
}

void	push_ant(t_ant **head, t_ant *new)
{
	t_ant	*next;

	next = *head;
	if (next)
	{
		new->next = *head;
		*head = new;
	}
	else
		*head = new;
}

void	add_ant(t_ant **head, t_ant *data)
{
	t_ant	*next;

	next = *head;
	if (next)
	{
		while (next->next)
			next = next->next;
		next->next = data;
	}
	else
		*head = data;
}

void	free_ants(t_ant **ants)
{
	t_ant	*head;
	t_ant	*next;

	head = *ants;
	while (head)
	{
		next = head->next;
		head->next = NULL;
		head->way = NULL;
		free(head);
		head = next;
	}
	*ants = NULL;
}
