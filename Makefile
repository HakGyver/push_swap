# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jteste <jteste@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/20 11:42:35 by jteste            #+#    #+#              #
#    Updated: 2024/02/12 15:20:50 by jteste           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= push_swap
CFLAGS		:= -Wextra -Wall -Werror
FTPRINTF	:= ./printf

LIBS	:= $(FTPRINTF)/libftprintf.a
SRCS	:= 	main.c \
			parsing.c \
			free_split.c \

OBJS	:= $(SRCS:.c=.o)
CC 		= gcc $(CFLAGS)

all: ftprintf $(NAME)

ftprintf:
	@$(MAKE) -C $(FTPRINTF)

$(NAME): $(SRCS) $(OBJS) 
	@$(CC) $(OBJS) $(LIBS) -o $(NAME)

clean:
	@rm -f $(OBJS)
	@$(MAKE) -C $(FTPRINTF) clean

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(FTPRINTF) fclean

re: clean all
fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(FTPRINTF) fclean
	


re: clean all

.PHONY: all, clean, fclean, re
