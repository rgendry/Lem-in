/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgendry <rgendry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 21:30:43 by rgendry           #+#    #+#             */
/*   Updated: 2019/10/19 18:51:30 by rgendry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_int	*create_int(int num)
{
	t_int	*new;

	if (!(new = (t_int*)ft_memalloc(sizeof(t_int))))
		error();
	new->integer = num;
	new->next = NULL;
	return (new);
}

int		get_int(t_int **head)
{
	t_int	*new;
	int		result;

	result = (*head)->integer;
	new = (*head)->next;
	free(*head);
	*head = new;
	return (result);
}

int		push_int(t_int **head, t_int *data)
{
	t_int	*next;

	if (!data)
		return (1);
	next = *head;
	if (next)
	{
		data->next = *head;
		*head = data;
	}
	else
		*head = data;
	return (0);
}

int		add_int(t_int **head, t_int *data)
{
	t_int	*next;

	if (!data)
		return (1);
	next = *head;
	if (next)
	{
		while (next->next)
			next = next->next;
		next->next = data;
	}
	else
		*head = data;
	return (0);
}

void	free_int(t_int **integers)
{
	t_int	*integer;
	t_int	*next;

	integer = *integers;
	while (integer)
	{
		next = integer->next;
		integer->next = NULL;
		free(integer);
		integer = next;
	}
	*integers = NULL;
}
