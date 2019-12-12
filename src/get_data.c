/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgendry <rgendry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 17:21:20 by rgendry           #+#    #+#             */
/*   Updated: 2019/10/24 18:43:15 by rgendry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	set_start(t_lem *lem)
{
	char	*line;
	char	**data;

	line = NULL;
	if (lem->start)
		error();
	get_next_line(0, &line);
	make_buff(lem, &line);
	data = ft_strsplit(line, ' ');
	if (arr_len(data) != 3 || !(check_int(data[1])) || !(check_int(data[2])))
	{
		free_arr(&data);
		ft_strdel(&line);
		error();
	}
	if (check_node(data[0], data[1], data[2], lem))
		lem->start = create_node(data[0], data[1], data[2]);
	lem->size++;
	free_arr(&data);
	ft_strdel(&line);
}

void	set_end(t_lem *lem)
{
	char	*line;
	char	**data;

	line = NULL;
	if (lem->end)
		error();
	get_next_line(0, &line);
	make_buff(lem, &line);
	data = ft_strsplit(line, ' ');
	if (arr_len(data) != 3 || !(check_int(data[1])) || !(check_int(data[2])))
	{
		free_arr(&data);
		ft_strdel(&line);
		error();
	}
	if (check_node(data[0], data[1], data[2], lem))
		lem->end = create_node(data[0], data[1], data[2]);
	lem->size++;
	free_arr(&data);
	ft_strdel(&line);
}

int		check_comment(char **line, t_lem *lem)
{
	if (!*line)
		error();
	make_buff(lem, line);
	if (!(ft_strcmp(*line, "##start")))
	{
		ft_strdel(line);
		set_start(lem);
		return (1);
	}
	else if (!(ft_strcmp(*line, "##end")))
	{
		ft_strdel(line);
		set_end(lem);
		return (1);
	}
	else if ((*line)[0] == '#')
	{
		ft_strdel(line);
		return (1);
	}
	return (0);
}

void	get_ants(t_lem *lem)
{
	int		i;
	char	*line;

	i = 0;
	line = NULL;
	get_next_line(0, &line);
	while (check_comment(&line, lem) == 1)
		get_next_line(0, &line);
	if (!line)
		error();
	while (line[i])
	{
		if (!(line[i] >= '0' && line[i] <= '9'))
			error();
		i++;
	}
	lem->ants = ft_atoi(line);
	ft_strdel(&line);
	if (lem->ants < 1)
		error();
}

void	get_data(t_lem *lem)
{
	char	*line;

	line = NULL;
	while (get_next_line(0, &line))
	{
		if (!check_comment(&line, lem))
		{
			if (check_char(line, ' '))
				get_node(line, lem);
			else if (check_char(line, '-'))
				get_link(line, lem);
			else
				error();
		}
	}
	if (!(lem->start) || !(lem->end) || !lem->links || !lem->nodes)
		error();
	// if (!check_node(lem->start[0], lem->start[1], lem->start[2], lem) ||
	// 	!check_node(lem->end[0], lem->end[1], lem->end[2], lem))
	// 	error();
	add_node(lem->start, lem);
	push_node(lem->end, lem);
}
