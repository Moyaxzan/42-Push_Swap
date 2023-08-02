NAME = push_swap
SRCS = init.c main.c push.c revert.c rrevert.c swap.c cost.c sort.c \
       utils.c median.c target.c basic_sorts.c new_split.c
# SRCS_BONUS = 
OBJS = $(SRCS:.c=.o)
# OBJS_BONUS = $(SRCS_BONUS:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
HEADER_FILES = push_swap.h
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a
Make = make

all: $(NAME)

$(NAME): $(OBJS) $(HEADER_FILES) $(LIBFT)
	$(CC) -g -fsanitize=address $(CFLAGS) -o $(NAME) $(OBJS) -L $(LIBFT_DIR) -lft

$(OBJS): %.o: %.c $(HEADER_FILES)
	$(CC) $(CFLAGS) -g -I. -I $(LIBFT_DIR)/includes -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR) bonus

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(OBJS)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
