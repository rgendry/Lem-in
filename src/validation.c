/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgendry <rgendry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 16:29:43 by rgendry           #+#    #+#             */
/*   Updated: 2019/09/02 15:34:04 by rgendry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include <stdio.h>

int		check(char **map, int i)
{
	t_lem	*p;
	int		j;
	int		k;

	j = 0;
	k = 0;
	p->size = 0;
	while (j < i)
	{
		if (map[j][0] == '#' && (map[j][1] != '#' || !ft_strcmp(map[j], "##start") || !ft_strcmp(map[j], "##end")))
			j++;
		if (map[j][0] > '0' && map[j][0] < '9')
		{
			p->ants = ft_atoi(map[j]);
			j++;
		}
		else
		{
			while (map[j][k] != ' ' || map[j][k] != '\n')
				k++;
			if (*map[j] != '\n')
				p->size++;
		}
	}
}

int		makemap(char *file, int i)
{
	int		fd;
	char	*line;
	char	**map;

	if (!(map = (char **)malloc(sizeof(char*) * i)))
		return (0);
	i = 0;
	if ((fd = open(file, O_RDONLY)) == -1)
		return (0);
	while (get_next_line(fd, &line))
	{
		map[i] = ft_strdup(line);
		i++;
	}
	return (check(map, i));
}

int		validation(char *file)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	if ((fd = open(file, O_RDONLY)) == -1)
		return (0);
	while (get_next_line(fd, &line))
		i++;
	close(fd);
	return (makemap(file, i));
}
