NAME = push_swap
CHECKER = checker
SRCS_PUSH_SWAP = init.c main.c push.c revert.c rrevert.c swap.c cost.c sort.c \
                 utils.c median.c target.c basic_sorts.c new_split.c
SRCS_CHECKER = checker_main.c new_split.c init.c push.c revert.c \
               rrevert.c swap.c utils.c check.c
OBJS_PUSH_SWAP = $(SRCS_PUSH_SWAP:.c=.o)
OBJS_CHECKER = $(SRCS_CHECKER:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
HEADER = push_swap.h
HEADER_CHECKER = checker.h
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a
MAKE = make

all: $(NAME)

bonus: $(CHECKER)

$(NAME): $(OBJS_PUSH_SWAP) $(HEADER) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS_PUSH_SWAP) -L $(LIBFT_DIR) -lft

$(CHECKER): $(OBJS_CHECKER) $(HEADER_CHECKER) $(LIBFT)
	$(CC) $(CFLAGS) -o $(CHECKER) $(OBJS_CHECKER) -L $(LIBFT_DIR) -lft

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -I. -I $(LIBFT_DIR)/includes -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR) bonus

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(RM) $(OBJS_PUSH_SWAP) $(OBJS_CHECKER)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(RM) $(NAME) $(CHECKER)

re: fclean all

.PHONY: all bonus clean fclean re
