/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   secondary.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgendry <rgendry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 19:12:13 by rgendry           #+#    #+#             */
/*   Updated: 2019/10/19 19:41:33 by rgendry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		arr_len(char **arr)
{
	int		i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

int		check_char(char *line, char c)
{
	int	i;

	i = 0;
	if (!line)
		return (0);
	while (line[i])
	{
		if (line[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int		check_int(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

void	free_arr(char ***arr)
{
	int	i;

	i = 0;
	while ((*arr)[i])
	{
		free((*arr)[i]);
		(*arr)[i] = NULL;
		i++;
	}
	free(*arr);
	*arr = NULL;
}
