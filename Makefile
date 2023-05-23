NAME = push_swap.a

CC = cc -g
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -rf

LIBFT = libft/libft.a

SRCS =  push_swap.c \
		calcs.c \
		lists.c \
		ops.c \
		ops2.c \
		verif.c \
		sorteio.c \
		utils.c \
		utils2.c \
		utils3.c \

BONUS = checker/checker.c

OBJS = $(SRCS:%.c=%.o)

OBJS_BONUS = $(BONUS:%.c=%.o)

$(LIBFT):
	@$(MAKE) -C ./libft

$(NAME): $(OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o push_swap

all: $(NAME)

bonus:
	@$(CC) $(CFLAGS) $(BONUS) -o checker

clean:
	@$(MAKE) clean -C ./libft
	@$(RM) $(OBJS)

fclean: clean
	@$(MAKE) fclean -C ./libft
	@$(RM) $(NAME) push_swap

re: fclean all