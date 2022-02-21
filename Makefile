SRCS	=	push_swap.c \
			ft_stacks_1.c ft_stacks_2.c ft_sort.c ft_sort_utils.c \
			ft_rules_1.c ft_rules_2.c ft_rules_3.c ft_rules_utils.c \
			ft_utils_1.c ft_utils_2.c ft_utils_3.c ft_utils_4.c ft_utils_5.c \
			ft_split.c
		
OBJS	=	$(SRCS:.c=.o)

BONUS	=	checker.c \
			ft_stacks_1.c ft_stacks_2.c ft_sort.c ft_sort_utils.c \
			ft_rules_1.c ft_rules_2.c ft_rules_3.c ft_rules_utils.c \
			ft_utils_1.c ft_utils_2.c ft_utils_3.c ft_utils_4.c ft_utils_5.c \
			ft_split.c ft_gnl.c ft_gnl_utils.c

B_OBJS	=	$(BONUS:.c=.o)

CC		=	gcc
RM 		= 	rm -f
CFLAGS	=	-Wall -Wextra -Werror -I.
NAME	=	push_swap
B_NAME	=	checker

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

all: 		$(NAME) bonus

bonus:		$(B_OBJS)
			$(CC) $(CFLAGS) -o $(B_NAME) $(B_OBJS)

clean:
			$(RM) $(OBJS) $(B_OBJS)

fclean:		clean
			$(RM) $(NAME)
			$(RM) $(B_NAME)

re:			fclean $(NAME)

.PHONY:		all $(NAME) bonus clean fclean re
