/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   poiskway.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgendry <rgendry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 16:33:06 by rgendry           #+#    #+#             */
/*   Updated: 2019/09/06 19:33:45 by rgendry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include <stdio.h>

int check_ocher(t_way *dest, t_way *src)
{
    while(src)
    {
        if(!strcmp(dest->sosed->key,src->sosed->key))
             return(0);
        src = src->next;
    }
    return(1);
}

void do_ochered(t_v **hashtab, char *start, t_way **ochered, int line, t_flag *fl)
{
    t_connection *temp;
    t_v *node;
    t_way *ochered1;
    t_way *ochered2;

    node = hashtab_lookup(hashtab, start, fl->hash_nbr);
    printf("vizitttttt %d\n",node->knot->vizit);
    printf("vizit s kem %s\n",node->knot->bonds->key);
    printf("vizit ot kogo %s\n",node->key);
    if(node->knot)
    {
        temp = node->knot;
         printf("in if    %s\n",temp->bonds->key);
          printf("in if    %d\n",temp->vizit);
        ochered2 = (t_way*)malloc(sizeof(t_way));
        while(temp)
        {
            printf("s kem svyaz    %s\n",temp->bonds->key);
            if(temp->vizit == 0)
            {
                ochered2 = (t_way*)malloc(sizeof(t_way));
                ochered1 = *ochered;
                while(ochered1->next != NULL)
                    ochered1 = ochered1->next;
                ochered2->sosed = temp->bonds;
                if(check_ocher(ochered2, *ochered))
                {
                    printf("kogo dobavlyau v ochered posle proverki  %s\n",temp->bonds->key);
                    ochered2->next = NULL;
                    ochered2->prev = node;
                    ochered2->revnext = ochered1;
                    ochered2->poryadok = line;
                    ochered1->next = ochered2;
                }
                else
                    free(ochered2);
            }
            temp = temp->next;
        }
    }
}


int proverka_end(t_way *ochered, char *str)
{
    while(ochered)
    {
        if(!strcmp(ochered->sosed->key,str))
             return(0);
        ochered = ochered->next;
    }
    return(1);
}


t_way  *ft_way(t_v **hashtab, char *start, char *end,t_flag *fl)
{
    t_v *node;
    t_way *ochered;
    t_way *temp;
    t_way *way;

    node = hashtab_lookup(hashtab, start, fl->hash_nbr);
    ochered = (t_way*)malloc(sizeof(t_way));
    ochered->sosed = node;
    ochered->status = 0;
    ochered->poryadok = 0;
    ochered->revnext = NULL;
    ochered->prev = NULL;
    ochered->number = 0;
    temp = ochered;
    while(temp)
    {
        if(temp->status == 0)
        {
            do_ochered(hashtab, temp->sosed->key, &ochered, temp->poryadok + 1, fl);
            temp->status = 1;
        }
        if(!proverka_end(ochered, end))
        {
            fl->c = 0;
            break;
        }
        temp = temp->next;
        fl->c = 1;
    }
    if(fl->c == 1)
    {
        ft_putstr("no way\n");
        // exit(0);
    }

    way = create_smallway(ochered);
     while(ochered)
    {
        printf("                            %s    ",ochered->sosed->key); // печать короткого пути
        printf("                            %d\n",ochered->poryadok);
        ochered = ochered->next;
    }
   // close_way(way);
    return(way);
    // while(ochered)
    // {
    //     printf("%s    ",ochered->sosed->key); // печать короткого пути
    //     printf("%d\n",ochered->poryadok);
    //     ochered = ochered->next;
    // }
    // while(way)
    // {
    //     printf("smallway = %s  ",way->sosed->key);
    //     printf("vizit= %d \n",way->sosed->vizit); // печать короткого пути
    //     way = way->next;
    // }
}

void  ft_multyway(t_v **hashtab, char *start, char *end,t_flag *fl)
{
    t_way *temp;

    temp = ft_way(hashtab, start, end, fl);
    close_way(temp);
    while(temp)
    {
        printf("smallway = %d  ",temp->sosed->knot->vizit);
       printf("smallway = %s \n",temp->sosed->key); // печать короткого пути
        temp = temp->next;
    }
    // printf("\n\n\n\n\n\n");
    temp = ft_way(hashtab,start, end, fl);
    close_way(temp);
     while(temp)
    {
        printf("smallway = %d  ",temp->sosed->knot->vizit);
       printf("smallway = %s \n",temp->sosed->key); // печать короткого пути
        temp = temp->next;
    }
temp = ft_way(hashtab,start, end, fl);
     while(temp)
    {
        printf("smallway = %d  ",temp->sosed->knot->vizit);
       printf("smallway = %s \n",temp->sosed->key); // печать короткого пути
        temp = temp->next;
    }
    // while(temp)
    // {
    //     printf("smallway = %s  ",temp->sosed->key);
    //     printf("vizit= %d \n",temp->sosed->vizit); // печать короткого пути
    // temp = temp->next;
    // }
    // while(temp)
    // {
    //     printf("smallway = %s  ",temp->sosed->key);
    //     printf("vizit= %d \n",temp->sosed->vizit); // печать короткого пути
    //     temp = temp->next;
    // }
}
