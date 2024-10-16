NAME = push_swap
LIBFT_DIR = libft

SRC_FILES = push_swap.c process_input.c stack.c push.c reverse_rotate.c rotate.c sort_small.c sort_medium.c swap.c util.c

OBJ_FILES = $(SRC_FILES:.c=.o)

CC = cc
INCLUDE = -I. -I$(LIBFT_DIR)
CFLAGS = -Wall -Wextra -Werror $(INCLUDE) -g
LDFLAGS = -L$(LIBFT_DIR) -lft

all: $(NAME)

$(NAME): $(OBJ_FILES) $(LIBFT_DIR)/libft.a
	$(CC) $(OBJ_FILES) -o $(NAME) $(LDFLAGS)

$(LIBFT_DIR)/libft.a: 
	$(MAKE) -C $(LIBFT_DIR)
	
%.o: %.c 
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm -f $(OBJ_FILES) 
	$(MAKE) -C ./libft clean

fclean: clean
	rm -f $(NAME) 
	$(MAKE) -C ./libft fclean

re: fclean all

.PHONY: all clean fclean re
