# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dgiurgev <dgiurgev@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/25 16:54:44 by dgiurgev          #+#    #+#              #
#    Updated: 2023/11/29 15:09:55 by dgiurgev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
FLAGS = -Wall -Wextra -Werror -D BUFFER_SIZE=42

NAME = get_next_line.a

SOURCES = get_next_line.c get_next_line_utils.c



OBJECTS = $(SOURCES:.c=.o)


all: $(NAME)

$(NAME):	 $(OBJECTS)
			ar rcs $(NAME) $(OBJECTS)

test: $(NAME)
	$(CC) $(FLAGS) $(NAME) main.c -o GNL_test

clean:
		rm -f $(OBJECTS)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re