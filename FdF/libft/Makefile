NAME	= libft.a 

SRCS	= get_next_line.c get_next_line_utils.c ft_split.c ft_atoi.c ft_bzero.c

OBJS	= ${SRCS:.c=.o}

RM	= rm -f

CC	= gcc

FLAGS	= -Wall -Wextra -Werror

all:		${NAME}

.c.o:      
			${CC} ${FLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
				ar rc ${NAME} ${OBJS}
				ranlib ${NAME}

clean:          
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
