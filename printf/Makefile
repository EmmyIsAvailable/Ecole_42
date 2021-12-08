NAME	= libftprintf.a

SRCS	= ft_printf.c print_char.c print_hex.c ./libft/ft_strlen.c ./libft/ft_putstr_fd.c \
		./libft/ft_putchar_fd.c

OBJS	= ${SRCS:.c=.o}

RM	= rm -f

FLAGS	= -Wall -Wextra -Werror

all:		${NAME}

.c.o:      
			gcc ${FLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			ar rc ${NAME} ${OBJS}

clean:          
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:		fclean all

.PHONY:		all clean fclean re
