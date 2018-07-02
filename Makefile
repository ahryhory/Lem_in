# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/22 12:17:34 by ahryhory          #+#    #+#              #
#    Updated: 2018/03/24 17:29:01 by ahryhory         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

FLAGS = -Wall -Werror -Wextra

OBJ = $(SRC:.c=.o)

PATHLIBFT = src/libft

HEAD = src/lem_in

LIB = src/libft/libft.a

SRC =

SRC += src/lem_in/add_to_data.c
SRC += src/lem_in/add_to_links.c
SRC += src/lem_in/add_to_rooms.c
SRC += src/lem_in/check_links.c
SRC += src/lem_in/check_nbr_ants.c
SRC += src/lem_in/check_rooms.c
SRC += src/lem_in/find_way.c
SRC += src/lem_in/free_all_farm.c
SRC += src/lem_in/free_matr.c
SRC += src/lem_in/ft_clr.c
SRC += src/lem_in/ft_exit.c
SRC += src/lem_in/get_end_indx.c
SRC += src/lem_in/get_start_indx.c
SRC += src/lem_in/lem_in.c
SRC += src/lem_in/move_to_depth.c
SRC += src/lem_in/next_step.c
SRC += src/lem_in/parse_data.c
SRC += src/lem_in/print_data.c
SRC += src/lem_in/print_way.c
SRC += src/lem_in/check_coords.c
SRC += src/lem_in/not_link.c

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(PATHLIBFT)
	@gcc -o $(NAME) $(OBJ) $(LIB)

%.o: %.c
	@gcc $(FLAGS) -c -I $(HEAD) $<
	@mv *o src/lem_in

clean:
	@make clean -C $(PATHLIBFT)
	@rm -rf $(OBJ)

fclean: clean
	@make fclean -C $(PATHLIBFT)
	@rm -rf $(NAME)

re: fclean all
