NAME	= philo

SRCS    = action.c eating.c join_destroy.c my_strcmp.c precise_sleep.c\
doctor.c ft_atoi.c main.c philosopher.c print_func.c

CFLAGS	=  -Wall -Wextra -Werror -pthread

OBJS	= $(SRCS:.c=.o)
all     : $(NAME)
$(NAME)	: $(OBJS)
	cc $(CFLAGS) $(OBJS) -o $(NAME)

clean	: 
	$(RM) $(OBJS)

fclean	: clean
	$(RM) $(NAME)

re	: fclean all

.PHONY: all clean fclean re