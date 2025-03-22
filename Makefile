MAKEFLAGS += --no-print-directory
NAME = minitalk
CC = cc
CFLAGS = -Wall -Wextra -Werror -g

SRCS_DIR = src
OBJS_DIR = objs

SRCS = server.c\

OBJS = $(addprefix $(OBJS_DIR)/, $(notdir $(SRCS:.c=.o)))

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS) $(LIBFT)
	@echo "Compiling $(NAME)..."
	@$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -o $(NAME)
	@echo "$(NAME) successfully created! 🎉"

$(LIBFT): 
	@make -C $(LIBFT_DIR) --no-print-directory
	@touch $(LIBFT) 

clean: 
	@echo "Cleaning object files..."
	@rm -rf $(OBJS_DIR)
	@make -C $(LIBFT_DIR) clean

fclean: clean
	@echo "Removing $(NAME)"
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
