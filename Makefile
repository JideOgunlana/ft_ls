# Makefile

NAME = ft_ls
CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iincludes
SRCS = src/main.c src/options.c src/display.c src/file_handling.c src/sorting.c src/recursive.c
OBJS_DIR = ./obj/
OBJS = $(addprefix $(OBJS_DIR), $(notdir $(SRCS:.c=.o)))
LIBFT_DIR = libft/
LIBFT = $(LIBFT_DIR)libft.a

all: $(LIBFT) $(NAME)

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

$(OBJS_DIR)%.o: src/%.c | $(OBJS_DIR)
	$(CC) $(CFLAGS) -c -o $@ $<

$(LIBFT):
	$(MAKE) -f Makefile_libft

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)

clean:
	@rm -f $(OBJS)
	@rmdir $(OBJS_DIR) 2>/dev/null || true
	@$(MAKE) -f Makefile_libft clean

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -f Makefile_libft fclean

re: fclean all

.PHONY: all clean fclean re
