/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_smallway.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgendry <rgendry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 16:32:55 by rgendry           #+#    #+#             */
/*   Updated: 2019/09/06 16:55:49 by rgendry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include <stdio.h>

t_way  *create_smallway(t_way *ochered)
{
    t_way *way;
    t_way *temp;
    t_way *tempway;

    way = (t_way*)malloc(sizeof(t_way));
    while(ochered->next)
        ochered = ochered->next;
    way->sosed = ochered->sosed;
    way->next = NULL;

    while(ochered->revnext)
    {
        tempway = (t_way*)malloc(sizeof(t_way));
        temp = ochered;
        printf(" way %s    \n",temp->prev->key);
        while(ochered->sosed != temp->prev && ochered->revnext != NULL)
            ochered = ochered->revnext;
        tempway->sosed = ochered->sosed;
        tempway->next = way;
        way = tempway;
        if(ochered->revnext == NULL)
            break;
        //tempway->sosed->vizit = 1;
        // else
        //     ochered = ochered->revnext;
    }
    return(way);
}

void    close_way(t_way *way)
{
    t_way *temp;
    t_connection *temp1;

    temp = way;
    while(temp->next)
    {
        temp1 = temp->sosed->knot;
        while(temp1->bonds != temp->next->sosed && temp->next != NULL)
            temp1 = temp1->next;
        printf("close ot kogo %s \n",temp->sosed->key);
        printf("close kogo %s \n",temp1->bonds->key);
        temp1->vizit = 1;
        temp = temp->next;
    }
}
