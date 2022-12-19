# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbolkova <tbolkova@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/27 20:13:25 by stena-he          #+#    #+#              #
#    Updated: 2022/12/19 14:34:09 by tbolkova         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compilation
NAME = 	push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

# Libraries
LIBFT = Library/Ft_printf/Libft/libft.a
PRINTF = Library/Ft_printf/libftprintf.a

# Paths
SRC_PATH = src/
OBJ_PATH = obj/
LIBFT_PATH = Library/Ft_printf/Libft
PRINTF_PATH = Library/Ft_printf

# Source and object files
SRC =	main.c \
		parse_args.c \
		ft_atoi_mod.c \
		ft_sort.c \
		ft_sort_cont.c \
		exec_actions.c \
		final_sort.c \
		ft_sort_utils.c \
		linked_lists.c \
		utils.c \
		push.c \
		swap.c \
		rotate.c \
		reverse_rotate.c

# Add prefixes
SRCS	= $(addprefix $(SRC_PATH), $(SRC))
OBJ		= $(SRCS:.c=.o)

# Rules
all: $(OBJ_PATH) $(NAME)

$(OBJ_PATH):
	mkdir $(OBJ_PATH)

$(NAME): $(OBJ)
	$(MAKE) -C $(PRINTF_PATH)
	$(CC) $(CFLAGS) $(OBJ) $(MLX) $(LIBFT) $(PRINTF) -o $(NAME)
	mv $(OBJ) $(OBJ_PATH)

clean:
	rm -rf $(OBJ_PATH)
	$(MAKE) clean -C $(LIBFT_PATH)
	$(MAKE) clean -C $(PRINTF_PATH)

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C $(LIBFT_PATH)
	$(MAKE) fclean -C $(PRINTF_PATH)
	
re: fclean all

.PHONY: all clean fclean re