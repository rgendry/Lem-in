/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgendry <rgendry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 15:56:58 by mfahey            #+#    #+#             */
/*   Updated: 2019/10/24 16:49:48 by rgendry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	make_buff(t_lem *lem, char **line)
{
	char	*str;
	char	*buff;

	if (!lem->buff)
		lem->buff = ft_strdup(*line);
	else
	{
		str = ft_strjoin(lem->buff,
				buff = ft_strjoin("\n", *line));
		ft_strdel(&lem->buff);
		lem->buff = str;
		ft_strdel(&buff);
	}
}

void	one_way_out(t_lem *lem)
{
	int	i;

	i = 1;
	while (i <= lem->ants)
	{
		ft_printf("L%d-%s ", i, lem->end);
		i++;
	}
	ft_printf("\n");
}

// void	print_nodes(t_lem *lem)
// {
// 	while (lem->nodes)
// 	{
// 		ft_printf("%s ", lem->nodes->name);
// 		ft_printf("%d ", lem->nodes->x);
// 		ft_printf("%d\n", lem->nodes->y);
// 		lem->nodes = lem->nodes->next;
// 	}
// }

int		main(void)
{
	t_lem	*lem;
	t_path	*paths;

	lem = validation();
	//print_nodes(lem);
	if (!lem->type)
	{
		algorythm(lem, &paths);
		if (!paths)
			error();
		ft_printf("%s\n\n", lem->buff);
		go_ants(lem, paths);
		free_paths(&paths);
	}
	if (lem->type == 1)
	{
		ft_printf("%s\n\n", lem->buff);
		one_way_out(lem);
	}
	free_lem(lem);
	return (0);
}
