# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rgendry <rgendry@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/30 16:16:19 by rgendry           #+#    #+#              #
#    Updated: 2019/08/30 19:27:24 by rgendry          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

SRC_SEARCH = src/*.c

SRC = $(wildcard $(SRC_SEARCH))

OBJ = $(SRC:.c=.o)

HEADERS = -I include -I libft

LIBFLAGS = -L libft -lft

IMFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ) libft
	gcc $(OBJ) -o $@ $(LIBFLAGS)

%.o: %.c
	gcc -c $< -o $@ $(IMFLAGS) $(HEADERS) -g

.PHONY: libft
libft:
	make -C libft

.PHONY: clean
clean:
	make clean -C libft
	rm -Rf $(OBJ)

.PHONY: fclean
fclean: clean
	make fclean -C libft
	rm -Rf $(NAME)

.PHONY: re
re: fclean all

