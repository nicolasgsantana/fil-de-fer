NAME = fdf
SRC_DIR = src
INC_DIR = inc
OBJ_DIR = obj

LIBFT_DIR= lib/libft
MLX42_DIR = lib/MLX42
LIBFT = $(LIBFT_DIR)/libft.a
MLX42 = $(MLX42_DIR)/build/libmlx42.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I$(INC_DIR) -I$(LIBFT_DIR)/include -I$(MLX42_DIR)/include/MLX42
LIBS = $(LIBFT) $(MLX42) -ldl -lglfw -lm -pthread

SRC = src/main.c src/parser.c src/utils.c src/ft_htoi.c src/draw.c src/validation.c src/error.c
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
HEADER = inc/fdf.h inc/error.h inc/validation.h inc/utils.h

all: $(NAME)

$(NAME): $(LIBFT) $(MLX42) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADER) | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(MLX42):
	cd $(MLX42_DIR) && \
	cmake -B build && \
	cmake --build build -j4

clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	rm -rf $(MLX42_DIR)/build
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
