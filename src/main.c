/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgendry <rgendry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 16:17:58 by rgendry           #+#    #+#             */
/*   Updated: 2019/09/19 19:06:59 by rgendry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include <stdio.h>

int	main(void)
{
	t_lem	p;

	p.nodesize = 0;
	p.linksize = 0;
	p.ants = 0;
	p.start = NULL;
	p.end = NULL;
	if (!validation(&p))
		return (0);
	dograf(&p);
	return (1);
}
