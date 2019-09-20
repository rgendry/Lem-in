/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_ants.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgendry <rgendry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 13:54:41 by rgendry           #+#    #+#             */
/*   Updated: 2019/09/19 19:06:55 by rgendry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int     calc_path(t_allway *map, int ants)
{
    int     paths;
    int     i;
    int     j;
    int     t;

    while (map->next)
        map = map->next;
    paths = 1;
    i = map->size + ants;
    j = 0;
    if (ants < map->gap)
        return (paths);
    while (map && map->prev)
    {
        t = (ants - map->gap) / paths;
        map = map->prev;
        j = map->size + t;
        if (j > i)
            return (paths--);
        i = j;
        paths++;
    }
    return (paths--);
}

void    sort_list(t_allway *map)
{
}

void    go_ants(t_allway *map_oneway, t_allway *map, t_flag *fl)
{
    int         last_size;
    t_way       *temp;
    t_allway    *temp1;
    t_allway    *temp2;

    last_size = 2147483647;
    temp = map_oneway->go;
    map_oneway->size = 0;
    while (temp->next)
    {
        map_oneway->size++;
        temp = temp->next;
    }
    temp1 = map;
    while (temp1)
    {
        temp1->size = 0;
        temp = temp1->go;
        while (temp->next)
        {
            temp = temp->next;
            temp1->size++;
        }
        temp1 = temp1->next;
        if (!temp1)
            break ;
    }
    temp1 = map;
    // sort_list(temp1);
    while (temp1)
    {
        temp1->gap = last_size - temp1->size;
        last_size = temp1->size;
        printf("size way =   %d\n", temp1->size);
        printf("gap size =   %d\n", temp1->gap);
        temp1 = temp1->next;
        if (!temp1)
            break ;
    }
    temp1 = map;
    printf("%d\n", calc_path(temp1, fl->ants));
}
