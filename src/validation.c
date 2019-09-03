/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgendry <rgendry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 16:29:43 by rgendry           #+#    #+#             */
/*   Updated: 2019/09/03 17:58:47 by rgendry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include <stdio.h>

int		printerr()
{
	write(1, "ERROR\n", 6);
	return (0);
}

int		fill_params(t_lem *p, char **map, int i)
{
	int j;
	int k;
	int	m;

	j = 1;
	k = 0;
	m = 0;
	p->links = (char **)malloc(sizeof(char*) * p->linksize);
	p->nodes = (char **)malloc(sizeof(char*) * p->nodesize);
	while (j < i)
	{
		if (!ft_strcmp(map[j], "##start"))
			p->start = ft_strndup(map[j + 1], ' ');
		if (!ft_strcmp(map[j], "##end"))
			p->end = ft_strndup(map[j + 1], ' ');
		if (ft_strchr(map[j], ' ') && k < p->nodesize)
		{
			p->nodes[k] = ft_strndup(map[j], ' ');
			k++;
		}
		if (ft_strchr(map[j], '-') && m < p->linksize)
		{
			p->links[m] = ft_strdup(map[j]);
			m++;
		}
		j++;
	}
	return (1);
}

int		check_room(char *room)
{
	int i;

	i = 0;
	while (room[i - 1] != ' ')
		i++;
	while (room[i] >= '0' && room[i] <= '9')
		i++;
	if (room[i] == ' ')
		i++;
	while (room[i] >= '0' && room[i] <= '9')
		i++;
	if (room[i] == '\0')
		return (1);
	return (0);
}

int		check(char **map, int i, t_lem *p)
{
	int	j;

	j = 1;
	if (map[0][0] > '0' && map[0][0] < '9')
	{
		p->ants = ft_atoi(map[0]);
		if (ft_strcmp(ft_itoa(p->ants), map[0]) || p->ants < 1)
			return (0);
	}
	while (j < i)
	{
		if (ft_strchr(map[j], ' '))
		{
			if (!check_room(map[j]))
				return (0);
			p->nodesize++;
		}
		if (ft_strchr(map[j], '-'))
			p->linksize++;
		j++;
	}
	return (fill_params(p, map, i));
}

int		makemap(char *file, int i, t_lem *p)
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
		if (line[0] != '#' || (line[0] == '#' && line[1] == '#'))
		{
			map[i] = ft_strdup(line);
			i++;
		}
	}
	return (check(map, i, p));
}

int		validation(char *file, t_lem *p)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	if ((fd = open(file, O_RDONLY)) == -1)
		return (0);
	while (get_next_line(fd, &line))
	{
		if (line[0] != '#' || (line[0] == '#' && line[1] == '#'))
			i++;
		if (line[0] == 'L')
			return (0);
	}
	close(fd);
	return (makemap(file, i, p));
}
