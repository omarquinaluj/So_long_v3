# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: owmarqui <owmarqui@student.42madrid.c      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/04 12:45:18 by owmarqui          #+#    #+#              #
#    Updated: 2024/12/13 13:53:10 by owmarqui         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := so_long
CFLAGS := -Wextra -Wall -Werror

LIBMLX_PATH := ./MLX42/build
LIBMLX := $(LIBMLX_PATH)/libmlx42.a -ldl -lglfw -pthread -lm
LIBMLX_REPO := https://github.com/codam-coding-college/MLX42.git

LIBDEF_PATH := ./Libft_definitiva
LIBDEF := $(LIBDEF_PATH)/libft.a

SRCS := SRC/main.c SRC/load_funcion.c SRC/move_funcion.c SRC/render_funcion.c\
		SRC/image_funcion.c SRC/realloc.c SRC/is_valid_map.c SRC/check_ber.c\
		SRC/check_validate_map.c SRC/free_images.c

OBJS := ${SRCS:.c=.o}

# Objetivo para clonar y configurar MLX42
clone_mlx:
	@if [ ! -d ./MLX42 ]; then  \
		echo "Clonando MLX42..."; \
		git clone $(LIBMLX_REPO) ./MLX42; \
		mkdir -p $(LIBMLX_PATH); \
		cd $(LIBMLX_PATH) && cmake .. ;\
	else \
		echo "Ya está instalado MLX42"; \
	fi

all: $(NAME)
	@echo "Ready"

$(NAME): $(OBJS)
	@$(MAKE) -C $(LIBDEF_PATH) all -s
	@$(MAKE) -C $(LIBMLX_PATH) all -s
	cc $(CFLAGS) $(OBJS) $(LIBDEF) $(LIBMLX) -o $(NAME)

$(LIBDEF):
	$(MAKE) -C $(LIBDEF_PATH) all -s

$(LIBMLX):
	$(MAKE) -C $(LIBMLX_PATH) all -s

clean:
	$(MAKE) -C $(LIBMLX_PATH) clean
	$(MAKE) -C $(LIBDEF_PATH) clean
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBDEF_PATH) fclean
	@if [ -f $(LIBMLX) ]; then \
		rm -f $(LIBMLX); \
	fi

re: fclean all

.PHONY: all clean fclean re 
