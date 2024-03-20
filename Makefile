# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amiguel- <amiguel-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/20 11:42:36 by amiguel-          #+#    #+#              #
#    Updated: 2024/03/20 15:40:24 by amiguel-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex.a

CC = gcc
CFLAGS = -g3 -Wall -Wextra -Werror

SRCS = 

OBJS = $(SRCS:.c=.o)
OBJDIR = $(NAME)_objects

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

BLACK = \033[0;30m
RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
BLUE = \033[0;34m
PURPLE = \033[0;35m
CYAN = \033[0;36m
WHITE = \033[0;37m
ORANGE = \033[0;91m
PINK = \033[0;95m

all:libft $(NAME)
	@echo "$(BOLD_GREEN)(⌐■_■) ¡¡¡$(NAME) compilado con exito!!! (⌐■_■)$(RESET)"

$(NAME): $(addprefix $(OBJDIR)/, $(OBJS))
	@echo "$(GREEN)¡Objetos creados!$(RESET)"
	@echo "$(CYAN)Compilando $(NAME)...$(RESET)"
	$(CC) $(CFLAGS) -o $@ $^ $(LIBFT)

$(OBJDIR)/%.o : %.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR):
	@echo "$(CYAN)Creando directorio de objetos...$(RESET)"
	mkdir $(OBJDIR)
	@echo "$(GREEN)¡Directorio de objetos creado!$(RESET)"
	@echo "$(CYAN)Creando objetos...$(RESET)"

libft:
	@make -C $(LIBFT_DIR)

libft_clean:
	@make -C $(LIBFT_DIR) clean

libft_fclean:
	@make -C $(LIBFT_DIR) fclean

clean: libft_clean
	@echo "$(RED)Eliminando archivos objeto...$(RESET)"
	rm -rf $(addprefix $(OBJDIR)/, $(OBJS))
	@echo "$(RED)¡Todos los archivos objeto han sido eliminados!$(RESET)"
	@echo "$(RED)Eliminando directorio de objetos...$(RESET)"
	rm -rf $(OBJDIR)
	@echo "$(RED)¡Directorio de objetos eliminado!$(RESET)"

fclean: clean libft_fclean
	@echo "$(RED)Eliminando ejecutable...$(RESET)"
	rm -rf $(NAME)
	@echo "$(RED)¡El ejecutable ha sido eliminado!$(RESET)"

re: fclean all

all:libft $(NAME)
	@echo "$(BOLD_GREEN)(⌐■_■) ¡¡¡$(NAME) compilado con exito!!! (⌐■_■)$(RESET)"

$(NAME): $(addprefix $(OBJDIR)/, $(OBJS))
	@echo "$(GREEN)¡Objetos creados!$(RESET)"
	@echo "$(CYAN)Compilando $(NAME)...$(RESET)"
	$(CC) $(CFLAGS) -o $@ $^ $(LIBFT)

$(OBJDIR)/%.o : %.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR):
	@echo "$(CYAN)Creando directorio de objetos...$(RESET)"
	mkdir $(OBJDIR)
	@echo "$(GREEN)¡Directorio de objetos creado!$(RESET)"
	@echo "$(CYAN)Creando objetos...$(RESET)"

libft:
	@make -C $(LIBFT_DIR)

libft_clean:
	@make -C $(LIBFT_DIR) clean

libft_fclean:
	@make -C $(LIBFT_DIR) fclean

clean: libft_clean
	@echo "$(RED)Eliminando archivos objeto...$(RESET)"
	rm -rf $(addprefix $(OBJDIR)/, $(OBJS))
	@echo "$(RED)¡Todos los archivos objeto han sido eliminados!$(RESET)"
	@echo "$(RED)Eliminando directorio de objetos...$(RESET)"
	rm -rf $(OBJDIR)
	@echo "$(RED)¡Directorio de objetos eliminado!$(RESET)"

fclean: clean libft_fclean
	@echo "$(RED)Eliminando ejecutable...$(RESET)"
	rm -rf $(NAME)
	@echo "$(RED)¡El ejecutable ha sido eliminado!$(RESET)"

re: fclean all