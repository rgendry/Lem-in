/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgendry <rgendry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 15:06:43 by rgendry           #+#    #+#             */
/*   Updated: 2019/10/24 18:43:32 by rgendry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft.h"
# include <stdio.h>
# include <limits.h>
# include <fcntl.h>

typedef struct		s_lem
{
	int				type;
	int				ants;
	int				size;
	struct s_node	*start;
	struct s_node	*end;
	struct s_node	*nodes;
	struct s_link	*links;
	struct s_map	*map;
	char			*buff;
}					t_lem;

typedef struct		s_node
{
	char			*name;
	int				x;
	int				y;
	struct s_node	*next;
}					t_node;

typedef struct		s_link
{
	char			*name1;
	char			*name2;
	struct s_link	*next;
}					t_link;

typedef struct		s_int
{
	int				integer;
	struct s_int	*next;
}					t_int;

typedef struct		s_map
{
	int				status;
	char			*name;
	struct s_int	*links;
}					t_map;

typedef struct		s_path
{
	int				size;
	int				*used;
	struct s_int	*queue;
	struct s_path	*next;
}					t_path;

typedef struct		s_group
{
	int				ants;
	struct s_path	*path;
	struct s_group	*next;
}					t_group;

typedef struct		s_ant
{
	int				node;
	int				name;
	struct s_path	*way;
	struct s_ant	*next;
}					t_ant;

t_lem				*validation();
void				index_map(t_lem *lem);
void				index_status(t_lem *lem);
void				find_path(t_lem *lem, t_path *way);
void				algorythm(t_lem *lem, t_path **paths);
void				go_ants(t_lem *lem, t_path *paths);
void				get_ants(t_lem *lem);
void				get_data(t_lem *lem);
void				free_links(t_link **links);
void				get_link(char *line, t_lem *lem);
void				make_buff(t_lem *lem, char **line);
int					check_char(char *line, char c);
int					check_int(char *str);
void				free_arr(char ***arr);
int					arr_len(char **arr);
void				error(void);
void				set_new_map(t_lem *lem);
t_int				*create_int(int num);
int					get_int(t_int **head);
int					push_int(t_int **head, t_int *data);
int					add_int(t_int **head, t_int *data);
void				free_int(t_int **integers);
t_node				*create_node(char *name, char *x, char *y);
int					check_node(char *name, char *x, char *y, t_lem *lem);
void				get_node(char *line, t_lem *lem);
void				push_node(t_node *node, t_lem *lem);
void				add_node(t_node *node, t_lem *lem);
t_path				*create_path(int *used, t_int *queue);
int					path_size(int *used, int end);
int					check_path(t_lem *lem, int *used);
void				del_path(t_path **way);
void				add_path(t_path **head, t_path *data);
void				free_paths(t_path **paths);
t_group				*create_group(t_path *way);
void				add_group(t_group **head, t_group *new);
int					check_groups(t_group *group, t_path *min_path);
void				free_groups(t_group **group);
t_ant				*create_ant(int name, t_path *path);
void				push_ant(t_ant **head, t_ant *new);
void				add_ant(t_ant **head, t_ant *data);
void				free_ants(t_ant **ants);
void				free_lem(t_lem *lem);

#endif
