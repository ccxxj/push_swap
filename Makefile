# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: Xiaojing <Xiaojing@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/06/17 10:16:31 by Xiaojing      #+#    #+#                  #
#    Updated: 2021/06/17 13:01:21 by Xiaojing      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
SRCS = heap_sort.c list.c push_swap.c radix_sort.c rules1.c rules2.c sort_small.c sort_small2.c sorting.c utils.c
HEADER_FILE = push_swap.h
OBJ_FILES = $(SRCS:.c=.o)
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ_FILES)
	$(CC) $(OBJ_FILES) -o $(NAME)

%.o: %.c $(HEADER_FILE)
	$(CC) -c $(CFLAGS) -o $@ $<

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
