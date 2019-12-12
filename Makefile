# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rgendry <rgendry@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/08 14:50:16 by rgendry           #+#    #+#              #
#    Updated: 2019/10/19 19:42:32 by rgendry          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all libft clean fclean re

OBJDIR = obj
SRCDIR = src
LIBDIR = libft
HEADER = -I ./include
HEADER_LIBFT = -I ./libft/include -I ./libft/src/ft_printf/include
FLAGS = -Wall -Wextra -Werror -g3 -g -O0

LEM-IN = lem-in
SRC_LEM-IN_NAME = main.c \
				  error.c \
				  secondary.c \
				  validation.c \
				  get_data.c \
				  create_link.c \
				  get_node.c \
				  create_int.c \
				  index_map.c \
				  algorythm.c \
				  status.c \
				  find_path.c \
				  go_ants.c \
				  create_group.c \
				  create_path.c \
				  create_ant.c \
				  lmn_free.c \

OBJ_LEM-IN_NAME = $(SRC_LEM-IN_NAME:.c=.o);
SRC_LEM-IN = $(addprefix $(OBJDIR)/, $(SRC_LEM-IN_NAME))
OBJ_LEM-IN = $(addprefix $(OBJDIR)/, $(OBJ_LEM-IN_NAME))

all: libft $(LEM-IN)

$(LEM-IN): $(OBJ_LEM-IN)
	@gcc $(FLAGS) $^ -o $@ $(HEADER_LIBFT) $(HEADER) -L libft -lft

$(OBJDIR)/%.o: $(SRCDIR)/%.c include/lem_in.h
	@mkdir -p $(OBJDIR)
	@gcc $(FLAGS) $(HEADER_LIBFT) $(HEADER) -o $@ -c $<

libft:
	@make -C $(LIBDIR)

clean:
	@make clean -C $(LIBDIR)
	@rm -Rf $(OBJDIR)

fclean: clean
	@make fclean -C $(LIBDIR)
	@rm -Rf $(LEM-IN)

re: fclean all

norm:
	norminette $(SRCDIR)
	norminette ./include
