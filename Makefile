# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dgiurgev <dgiurgev@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/25 16:54:44 by dgiurgev          #+#    #+#              #
#    Updated: 2023/12/16 21:27:53 by dgiurgev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -D BUFFER_SIZE=42

NAME = get_next_line.a

SOURCES = get_next_line.c get_next_line_utils.c

BONUS_SOURCES = get_next_line_bonus.c get_next_line_utils_bonus.c

OBJECTS = $(SOURCES:.c=.o)

BONUS_OBJECTS = $(BONUS_SOURCES:.c=.o)

all: $(NAME)

$(NAME):	$(OBJECTS)
			ar rcs $(NAME) $(OBJECTS)

# test: $(NAME)
# 	$(CC) $(CFLAGS) $(NAME) main.c -o GNL_test

bonus: $(BONUS_NAME)

$(BONUS_NAME):	$(BONUS_OBJECTS)
			ar rcs $(BONUS_NAME) $(BONUS_OBJECTS)

clean:
		rm -f $(OBJECTS) $(BONUS_OBJECTS)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
