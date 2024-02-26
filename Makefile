NAME	:= so_long

#Compiler options#

CC		:= cc
CFLAGS	:= -Wextra -Wall -Werror -Wunreachable-code -Ofast

LIBMLX	:= ./lib/MLX42

#Libft#

LIBFT_DIR	:= ./lib/libft/
LIBFT		:= $(LIBFT_DIR)/libft.a

HEADERS	:= -I ./inc -I $(LIBMLX)/include
LIBS	:= $(LIBMLX)/build/libmlx42.a -L"/Users/$(USER)/.brew/opt/glfw/lib" \
			-ldl -lglfw -pthread -lm $(LIBFT)
SRCS	:= $(shell find ./src -iname "*.c")
OBJS	:= ${SRCS:.c=.o}

all: libmlx $(LIBFT) $(NAME)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)\n"

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

$(LIBFT) :
	make -C $(LIBFT_DIR)

clean:
	make -C $(LIBFT_DIR) clean
	@rm -rf $(OBJS)
	@rm -rf $(LIBMLX)/build

fclean: clean
	rm -rf $(LIBFT)
	@rm -rf $(NAME)

re: clean all

.PHONY: all, clean, fclean, re, libmlx
