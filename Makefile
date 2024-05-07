# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amiguel- <amiguel-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/20 11:42:36 by amiguel-          #+#    #+#              #
#    Updated: 2024/05/07 10:29:07 by amiguel-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

CC = gcc

CFLAGS = -Werror -Wall -Wextra -fsanitize=address

RM = rm -rf

SRCS = 	src/pipex.c\
		src/utils.c\
		libft/libft.a\

SRCS_BONUS = 	src_bonus/pipex_bonus.c\
				src_bonus/utils_bonus.c\
				libft/libft.a\

$(NAME) :
	make all -C libft
	gcc $(CFLAGS) $(SRCS) -o $(NAME)


all : $(NAME)

fclean : clean
	$(RM) $(NAME)
	make fclean -C libft

clean :
	$(RM) $(NAME)
	make clean -C libft

re : fclean all

bonus : clean
	make all -C libft
	gcc $(CFLAGS) $(SRCS_BONUS) -o $(NAME)