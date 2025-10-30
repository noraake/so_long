NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror -Iincludes -ILibft -I$(MLX_DIR) -Iget_next_line -Iprintf
MLX_FLAGS = -L/usr/include/minilibx-linux -lmlx -lXext -lX11
SRCS = srcs/main.c srcs/map_parser.c srcs/game.c srcs/flood_fill.c srcs/graphic.c srcs/validate_map.c srcs/free_game.c srcs/line_to_map.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c printf/ft_printf.c printf/hexadecimal.c printf/print_functions.c 
OBJS = $(SRCS:.c=.o)

LIBFT_DIR = Libft
LIBFT = $(LIBFT_DIR)/libft.a

FT_PRINTF_DIR = printf
FT_PRINTF = printf/libftprintf.a

MLX_DIR = /usr/include/minilibx-linux
MLX = $(MLX_DIR)/libmlx.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MLX) $(FT_PRINTF)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(FT_PRINTF) $(MLX_FLAGS) -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(FT_PRINTF):
	make -C $(FT_PRINTF_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(FT_PRINTF_DIR) clean
	rm -f $(OBJS)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(FT_PRINTF_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
