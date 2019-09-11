/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_ants.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgendry <rgendry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 13:54:41 by rgendry           #+#    #+#             */
/*   Updated: 2019/09/11 20:07:18 by rgendry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

// t_allway    *sort_list(t_allway *map)
// {
//     t_way       *temp;
//     t_allway    *head;

//     head = map;
//     while (map && map->next)
//     {
//         if (map->size > map->next->size)
//         {
//             temp = map->go;
//             map->go = map->next->go;
//             map->next->go = temp;
//             map = head;
//         }
//         else
//             map = map->next;
//     }
//     map = head;
//     return (map);
// }

// void    print_paths(t_allway *map, int ants, int paths)
// {
//     int i;
//     int j;

//     i = 1;
//     j = 0;
//     while (ants > 0)
//     {
//         while (j < paths && ants > 0)
//         {
//             printf("L%d-", i);
//             printf("%s ", map->go->sosed->key);
//             map->next;
//             j++;
//             ants--;
//         }
//         j = 0;
//         printf("\n");
//     }
// }

void    calc_path(t_allway *map, int ants)
{
    int index;
    int i;
    int paths;

    i = 0;
    paths = 0;
    index = 1;
    while (map && ants > 0)
    {
        if (map->next && map->next->size > ants)
            break ;
        if (map->gap == 0 && i == 0)
            i = 1;
        else if (map->gap == 0 && i == 1)
            index++;
        else if (map->gap != 0 && i == 1)
            i = 0;
        printf("%d   ", ants);
        ants = ants - (map->gap * index) - paths;
        map = map->prev;
        paths++;
    }
    printf("\n%d   ", paths);
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
        printf(" razmer %d\n",temp1->size);
        if (temp1->next == NULL)
            temp2 = temp1;
        temp1 = temp1->next;
    }
    temp1 = map;
    //sort_list(temp1);
    while (temp1)
    {
        temp1->gap = last_size - temp1->size;
        last_size = temp1->size;
        printf("size way =   %d\n", temp1->size);
        printf("gap size =   %d\n", temp1->gap);
        if (temp1->next == NULL)
            temp2 = temp1;
        temp1 = temp1->next;
    }
    temp1 = map;
    while (temp1->next)
        temp1 = temp1->next;
    calc_path(temp1, fl->ants);
    // ants2 = fl->ants;
    // while(temp2)
    // {
    //     ants = temp2->size;
    //     temp2 = temp2->prev;
    //     if(temp2 != NULL)
    //         ants1 = temp2->size;
    //    ants2 = ants2 - (ants1 - ants);
    //    if(ants2<0)
    //     break;
    // }
    // printf("razmer s kakogo pyti puskat %d\n",temp2->size);
    // // while(fl->ants)
    // // {
    //     temp = temp2->go;
    //     temp = temp->next;
    //     while(temp)
    //     {
    //         printf("L%d - %s   ",c,temp->sosed->key);
    //         c++;
    //         temp = temp->next;
    //     }
    // // }
    // //  while(map_oneway)
    // // {
    // //     while(map_oneway->go)
    // //     {
    // //         printf("%s   ", map_oneway->go->sosed->key);
    // //         map_oneway->go = map_oneway->go->next;
    // //     }
    // //     printf("\n\n\n");
    // //     map_oneway = map_oneway->next;
    // // }
    //  while (map)
    // {
    //     while (map->go)
    //     {
    //         printf("%s   ", map->go->sosed->key);
    //         map->go = map->go->next;
    //     }
    //     printf("\n\n\n");
    //     map = map->next;
    // }
}
