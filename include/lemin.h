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
# include <string.h>
# define BUF_MAX 10260
#define HASHTAB_MUL 31
# include <fcntl.h>
# include <sys/types.h>

typedef struct	s_info
{
	int			size;
	int			start;
	int			end;
	t_lst		*head;
	t_lst		*lst;
}				t_info;

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

typedef struct	s_flag
{
	int			p;
	int			c;
	int			k;
	int			i;
	int			j;
	int			line;
	int			status;
	int			hash_nbr;
	char		temp[10];
	char		temp1[10];
	char		*ptr;
	char		*ptr1;
}				t_flag;

typedef struct	s_connection
{
	struct s_v	*bonds; // нода с которой связь
	struct s_connection	*next;
	int			vizit;
}				t_connection;

typedef struct	s_v
{
	char		*key;
	int			value;
	int			vizit;
	struct s_connection	*knot; // указатель на ноду с которой связь
	struct s_v	*next;
}				t_v;

typedef struct	s_way
{
	struct s_v		*sosed;
	struct s_way	*next;
	struct s_way	*revnext;
	struct s_v		*prev;
	int				poryadok;
	int				status;
	int				number;
}					t_way;

int				validation(t_lem *p);
int				hashtab_hash(char *key, int n);
void			hashtab_init(t_v **hashtab, int n);
void			hashtab_add(t_v **hashtab, char *key, int value, int n);
t_v				*hashtab_lookup(t_v **hashtab, char *key, int n);
void			doconnect(t_v **hashtab, t_flag *fl, t_lem *p);//char **str1, int n1);
t_way			*ft_way(t_v **hashtab, char *start, char *end, t_flag *fl);
void			ft_bzero(void *str, size_t len);
void			dograf(t_lem *p);//char **str, int n, char **str1, int n1);
t_way			*create_smallway(t_way *ochered);
void			close_way(t_way *way);
void			ft_multyway(t_v **hashtab, char *start, char *end, t_flag *fl);

#endif
