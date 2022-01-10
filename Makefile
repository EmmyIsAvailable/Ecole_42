NAME	= pipex

SRCS	= main.c ./libft/ft_putstr_fd.c ./libft/ft_strlen.c principal.c parsing.c ./libft/ft_split.c \
	  ./libft/ft_strnstr.c ./libft/ft_strjoin.c ./libft/ft_substr.c

OBJS	= ${SRCS:.c=.o}

RM	= rm -f

CC	= gcc

FLAGS	= -Wall -Wextra -Werror

all:		${NAME}

.c.o:      
			${CC} ${FLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			${CC} ${OBJS} -o ${NAME}

clean:          
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:		fclean all

.PHONY:		all clean fclean re
