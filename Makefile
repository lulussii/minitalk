MAKEFLAGS += --no-print-directory
CLIENT_NAME = client
SERVER_NAME = server
CC = cc
CFLAGS = -Wall -Wextra -Werror -g

SRCS_DIR = src
OBJS_DIR = objs

CLIENT_SRCS = $(SRCS_DIR)/client.c
SERVER_SRCS = $(SRCS_DIR)/server.c

CLIENT_OBJS = $(addprefix $(OBJS_DIR)/, $(notdir $(CLIENT_SRCS:.c=.o)))
SERVER_OBJS = $(addprefix $(OBJS_DIR)/, $(notdir $(SERVER_SRCS:.c=.o)))

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(CLIENT_NAME) $(SERVER_NAME)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(CLIENT_NAME): $(CLIENT_OBJS) $(LIBFT)
	@echo "Compiling $(CLIENT_NAME)..."
	@$(CC) $(CFLAGS) $(CLIENT_OBJS) -L$(LIBFT_DIR) -lft -o $(CLIENT_NAME)
	@echo "$(CLIENT_NAME) successfully created! 🎉"

$(SERVER_NAME): $(SERVER_OBJS) $(LIBFT)
	@echo "Compiling $(SERVER_NAME)..."
	@$(CC) $(CFLAGS) $(SERVER_OBJS) -L$(LIBFT_DIR) -lft -o $(SERVER_NAME)
	@echo "$(SERVER_NAME) successfully created! 🎉"

$(LIBFT): 
	@make -C $(LIBFT_DIR) --no-print-directory
	@touch $(LIBFT) 

clean: 
	@echo "Cleaning object files..."
	@rm -rf $(OBJS_DIR)
	@make -C $(LIBFT_DIR) clean

fclean: clean
	@echo "Removing $(CLIENT_NAME) and $(SERVER_NAME)" 
	@rm -f $(CLIENT_NAME) $(SERVER_NAME)
	@make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
