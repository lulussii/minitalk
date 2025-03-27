MAKEFLAGS += --no-print-directory
CLIENT_NAME = client
SERVER_NAME = server
CC = cc
CFLAGS = -Wall -Wextra -Werror -g

HEADER_DIR = include
HEADER = $(HEADER_DIR)/minitalk.h

SRCS_DIR = src
OBJS_DIR = objs

CLIENT_SRCS = $(SRCS_DIR)/client.c
SERVER_SRCS = $(SRCS_DIR)/server.c

CLIENT_OBJS = $(addprefix $(OBJS_DIR)/, $(notdir $(CLIENT_SRCS:.c=.o)))
SERVER_OBJS = $(addprefix $(OBJS_DIR)/, $(notdir $(SERVER_SRCS:.c=.o)))

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a
LIBFT_SRCS = $(wildcard $(LIBFT_DIR)/*.c)
LIBFT_MAKEFILE = $(LIBFT_DIR)/Makefile

all: $(CLIENT_NAME) $(SERVER_NAME) $(LIBFT)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(CLIENT_NAME): $(CLIENT_OBJS) $(LIBFT) $(HEADER)
	@echo "Compiling $(CLIENT_NAME)..."
	@$(CC) $(CFLAGS) $(CLIENT_OBJS) -L$(LIBFT_DIR) -lft -o $(CLIENT_NAME)
	@echo "$(CLIENT_NAME) successfully created! 🎉"

$(SERVER_NAME): $(SERVER_OBJS) $(LIBFT) $(HEADER)
	@echo "Compiling $(SERVER_NAME)..."
	@$(CC) $(CFLAGS) $(SERVER_OBJS) -L$(LIBFT_DIR) -lft -o $(SERVER_NAME)
	@echo "$(SERVER_NAME) successfully created! 🎉"

$(LIBFT): $(LIBFT_SRCS) $(LIBFT_MAKEFILE)
	@echo "🛠️  Compiling libft..."
	@make -C $(LIBFT_DIR)

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
