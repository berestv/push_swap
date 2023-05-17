NAME = push_swap.a

CC = cc -g
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

LIBFT = libft/libft.a

SRCS =  push_swap.c \
		calcs.c \
		utils.c \
		lists.c \
		ops.c \
		ops2.c \
		verif.c \
		sorteio.c \

OBJS = $(SRCS:%.c=%.o)

all: $(NAME)

$(LIBFT):
	@$(MAKE) -C ./libft

$(NAME): $(OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o push_swap

clean:
	@$(MAKE) clean -C ./libft
	@$(RM) $(OBJS)

fclean: clean
	@$(MAKE) fclean -C ./libft
	@$(RM) $(NAME) push_swap

re: fclean all