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

BONUS = bonus/checker.c \
		bonus/b_verif.c \
		bonus/b_utils.c \
		bonus/b_utils2.c \
		bonus/b_ops.c \
		bonus/b_ops2.c \

OBJS = $(SRCS:%.c=%.o)

OBJS_BONUS = $(BONUS:%.c=%.o)

all: $(NAME)

$(LIBFT):
	@$(MAKE) -C ./libft

$(NAME): $(OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o push_swap

bonus: $(OBJS_BONUS) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJS_BONUS) $(LIBFT) -o checker

clean:
	@$(MAKE) clean -C ./libft
	@$(RM) $(OBJS)
	@$(RM) $(OBJS_BONUS)

fclean: clean
	@$(MAKE) fclean -C ./libft
	@$(RM) $(NAME) push_swap
	@$(RM) $(NAME) checker

re: fclean all