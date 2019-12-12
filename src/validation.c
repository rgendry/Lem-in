/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfahey <mfahey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 16:58:29 by rgendry           #+#    #+#             */
/*   Updated: 2019/10/21 12:38:29 by mfahey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_lem	*make_lem(void)
{
	t_lem	*new;

	if (!(new = (t_lem*)malloc(sizeof(t_lem))))
		return (NULL);
	new->type = 0;
	new->ants = 0;
	new->size = 0;
	new->start = NULL;
	new->end = NULL;
	new->nodes = NULL;
	new->links = NULL;
	new->map = NULL;
	new->buff = NULL;
	return (new);
}

t_lem	*validation(void)
{
	t_lem	*lem;

	lem = make_lem();
	get_ants(lem);
	get_data(lem);
	index_map(lem);
	return (lem);
}
