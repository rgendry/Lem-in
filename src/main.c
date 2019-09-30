/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 16:17:58 by rgendry           #+#    #+#             */
/*   Updated: 2019/09/30 17:33:58 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

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
