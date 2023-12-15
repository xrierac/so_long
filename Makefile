NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror
MLXFLAGS = -L /usr/local/lib -lmlx -I /usr/local/include -framework OpenGL -framework AppKit

LIBFT = ./libft
SRCS = ./src
OBJS = 

all: $(NAME)

clean:
	make -C $(LIBFT) clean
	rm -f $(OBJS)

fclean: clean
	rm -f $(LIBFT)
	rm -f $(NAME)

re: fclean all

.PHONY : all clean fclean re libft
