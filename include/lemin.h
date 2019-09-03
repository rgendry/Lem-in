/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgendry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 16:17:06 by rgendry           #+#    #+#             */
/*   Updated: 2019/08/30 16:17:09 by rgendry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H
# include "libft.h"

typedef struct	s_lem
{
	int			ants;
	int			nodesize;
	int			linksize;
	char		*start;
	char		*end;
	char		**nodes;
	char		**links;
}				t_lem;

int				validation(char *file, t_lem *p);
int				printerr();

#endif
