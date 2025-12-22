CLIENT =	client
SERVER =	server
SRC1 = 		client.c
SRC2 =		server.c

MAKE = make -C
LIBFT_DIR = libft
LIBFT =		$(LIBFT_DIR)/libft.a
PRINTF_DIR = printf
PRINTF =	$(PRINTF_DIR)/printf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror #-g
OBJ1 = $(SRC1:.c=.o)
OBJ2 = $(SRC2:.c=.o)

all: $(CLIENT) $(SERVER)

$(LIBFT):
	@$(MAKE) $(LIBFT_DIR)

$(PRINTF):
	@$(MAKE) $(PRINTF_DIR)

$(CLIENT): $(LIBFT) $(PRINTF) $(OBJ1)
	@$(CC) $(CFLAGS) $(OBJ1) -o $(CLIENT) $(LIBFT) $(PRINTF) 

$(SERVER): $(LIBFT) $(PRINTF) $(OBJ2)
	@$(CC) $(CFLAGS) $(OBJ2) -o $(SERVER) $(LIBFT) $(PRINTF)

clean:
	rm -f $(OBJ1) $(OBJ2)
	make -C $(LIBFT_DIR) clean
	make -C $(PRINTF_DIR) clean

fclean: clean
	rm -f $(CLIENT) $(SERVER)
	make -C $(LIBFT_DIR) fclean
	make -C $(PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re