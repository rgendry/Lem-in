/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_group.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgendry <rgendry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 19:12:59 by rgendry           #+#    #+#             */
/*   Updated: 2019/10/19 18:48:00 by rgendry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_group	*create_group(t_path *way)
{
	t_group	*new;

	if (!(new = (t_group *)malloc(sizeof(t_group))))
		error();
	new->ants = 1;
	new->path = way;
	new->next = NULL;
	return (new);
}

void	add_group(t_group **head, t_group *new)
{
	t_group	*next;

	next = *head;
	if (next)
	{
		new->next = *head;
		*head = new;
	}
	else
		*head = new;
}

int		check_groups(t_group *groups, t_path *min_path)
{
	t_group	*group;

	group = groups;
	while (group)
	{
		if (group->path == min_path)
		{
			group->ants++;
			return (1);
		}
		group = group->next;
	}
	return (0);
}

void	free_groups(t_group **group)
{
	t_group	*head;
	t_group	*next;

	head = *group;
	while (head)
	{
		next = head->next;
		head->next = NULL;
		head->path = NULL;
		free(head);
		head = next;
	}
	*group = NULL;
}
