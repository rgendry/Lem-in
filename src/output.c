/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgendry <rgendry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 13:24:09 by rgendry           #+#    #+#             */
/*   Updated: 2019/09/11 13:31:37 by rgendry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	print_output(t_lem *p, t_lst *path)
{
	int	ant;
	int i;

	ant = 0;
	i = 0;
	while (ant < p->ants)
	{
		while (i < ant)
		{
			printf("L%d-", ant);
			printf("%s ", path->content);
			i++;
		}
		i = 0;
		ant++;
	}
}
