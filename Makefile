# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cdubuque <cdubuque@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/07 16:44:07 by cdubuque          #+#    #+#              #
#    Updated: 2019/10/31 04:02:42 by cdubuque         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LM = lem-in

INC = ./inc/lem_in.h

LIB = libft/libft.a

LMFILES = ants_attack.c attack_order.c bonuses.c change_ways.c end_level.c \
find_ways.c ft_map_change.c ft_map.c ft_rooms_level.c ft_start_end.c colors.c \
ft_the_shortest_way.c ft_validation.c ft_writing.c get_next_line.c lem_in.c \
shortest_ways.c test_ways.c tools.c way_day.c 
LMSRC = $(addprefix src/,$(LMFILES))

LMOBJ = $(addprefix obj/,$(LMFILES:.c=.o))

FLAGS = -Wall -Wextra -Werror

all : $(LM)

$(LM) : $(LMOBJ)
	@make -C libft/
	@gcc -o $(LM) $(LMOBJ) $(LIB)

obj/%.o: src/%.c $(INC)
	@mkdir -p obj/
	@gcc $(FLAGS) -Iinc -o $@ -c $<

clean :
	@make clean -C libft/
	@rm -rf obj/

fclean : clean
	@make fclean -C libft
	@rm -f $(LM)

re : fclean all
