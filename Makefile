NAME = push_swap
CHECKER = checker
SRCS = init.c main.c push.c revert.c rrevert.c swap.c cost.c sort.c \
       utils.c median.c target.c basic_sorts.c new_split.c
SRCS_CHECKER = checker_main.c new_split.c init.c push.c revert.c \
	       rrevert.c swap.c utils.c check.c
OBJS = $(SRCS:.c=.o)
OBJS_CHECKER = $(SRCS_CHECKER:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
HEADER = push_swap.h
HEADER_CHECKER = checker.h
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a
Make = make

all: $(NAME)

$(NAME): $(OBJS) $(HEADER) $(LIBFT)
	$(CC) -g -fsanitize=address $(CFLAGS) -o $(NAME) $(OBJS) -L $(LIBFT_DIR) -lft

$(OBJS): %.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -g -I. -I $(LIBFT_DIR)/includes -c $< -o $@

bonus: $(CHECKER)

$(CHECKER): $(OBJS_CHECKER) $(HEADER_CHECKER) $(LIBFT)
	$(CC) -g -fsanitize=address $(CFLAGS) -o $(CHECKER) $(OBJS_CHECKER) -L $(LIBFT_DIR) -lft

$(OBJS_CHECKER): %.o: %.c $(HEADER_CHECKER)
	$(CC) $(CFLAGS) -g -I. -I $(LIBFT_DIR)/includes -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR) bonus

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(OBJS) $(OBJS_CHECKER)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(RM) $(NAME) $(CHECKER)

re: fclean all

.PHONY: all clean fclean re
