/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_link.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgendry <rgendry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 20:25:09 by rgendry           #+#    #+#             */
/*   Updated: 2019/10/24 18:44:12 by rgendry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_link	*create_link(char **data)
{
	t_link *new;

	if (!(new = (t_link*)malloc(sizeof(t_link))))
		error();
	if (!ft_strcmp(data[0], data[1]))
		error();
	new->name1 = ft_strdup(data[0]);
	new->name2 = ft_strdup(data[1]);
	new->next = NULL;
	return (new);
}

void	push_link(t_link *link, t_lem *lem)
{
	t_link	*head;

	head = lem->links;
	if (head)
	{
		link->next = lem->links;
		lem->links = link;
	}
	else
		lem->links = link;
}

int		check_link(t_lem *lem, char **data)
{
	t_link *head;

	head = lem->links;
	if (lem->start && !ft_strcmp(lem->start->name, data[0]) &&
		lem->end && !ft_strcmp(lem->end->name, data[1]))
		lem->type = 1;
	if (lem->start && !ft_strcmp(lem->start->name, data[0]) &&
		lem->end && !ft_strcmp(lem->end->name, data[1]))
		lem->type = 1;
	while (head)
	{
		if (!ft_strcmp(head->name1, data[0]) &&
			!ft_strcmp(head->name2, data[1]))
			return (0);
		if (!ft_strcmp(head->name1, data[1]) &&
			!ft_strcmp(head->name2, data[0]))
			return (0);
		head = head->next;
	}
	return (1);
}

void	get_link(char *line, t_lem *lem)
{
	char	**data;
	t_link	*link;

	data = ft_strsplit(line, '-');
	if (arr_len(data) != 2)
	{
		free_arr(&data);
		error();
	}
	if (!check_link(lem, data))
		error();
	link = create_link(data);
	push_link(link, lem);
	free_arr(&data);
	ft_strdel(&line);
}

void	free_links(t_link **links)
{
	t_link	*link;
	t_link	*next;

	link = *links;
	while (link)
	{
		next = link->next;
		ft_strdel(&(link->name1));
		ft_strdel(&(link->name2));
		link->next = NULL;
		free(link);
		link = next;
	}
	*links = NULL;
}
