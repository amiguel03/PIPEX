# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amiguel- <amiguel-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/20 11:42:36 by amiguel-          #+#    #+#              #
#    Updated: 2024/06/18 10:05:04 by amiguel-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g3 #-fsanitize=address


RM = rm -rf

SRCS = 	src/pipex.c \
		src/utils.c \
		src/errors.c \
		src/parent_child.c

#SRCS_BONUS = 	src_bonus/pipex_bonus.c\
				src_bonus/utils_bonus.c\

OBJS=$(SRCS:%.c=%.o)

all : $(NAME)

$(NAME) : $(OBJS)
	make all -C libft
	gcc $(CFLAGS) $(SRCS) -o $(NAME) -Llibft/ -lft


fclean : clean
	$(RM) $(NAME) $(OBJS)
	make fclean -C libft

clean :
	$(RM) $(NAME) $(OBJS)
	make clean -C libft

re : fclean all

bonus : clean
	make all -C libft
	gcc $(CFLAGS) $(SRCS_BONUS) -o $(NAME) $(OBJS)


.PHONY: re fclean clean all bonus