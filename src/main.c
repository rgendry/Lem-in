/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgendry <rgendry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 16:17:58 by rgendry           #+#    #+#             */
/*   Updated: 2019/09/03 17:29:57 by rgendry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_lem	p;

	p.nodesize = 0;
	p.linksize = 0;
	p.ants = 0;
	if (argc != 2)
		return (printerr());
	if (!validation(argv[1], &p))
		return (printerr(0));
	printf("%d\n", p.ants);
	printf("%d\n", p.nodesize);
	printf("%d\n", p.linksize);
	printf("%s\n", p.start);
	printf("%s\n", p.end);
	int i;
	i = 0;
	while(i < p.nodesize)
	{
		printf("%s\n", p.nodes[i]);
		i++;
	}
	i = 0;
	while (i < p.linksize)
	{
		printf("%s\n", p.links[i]);
		i++;
	}
	return (1);
}
