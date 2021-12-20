NAME	= fdf 

SRCS	= main.c ft_window.c ./libft/get_next_line.c ./libft/get_next_line_utils.c ./libft/ft_split.c \
			./libft/ft_atoi.c ft_map.c ./libft/ft_bzero.c

OBJS	= ${SRCS:.c=.o}

RM	= rm -f

CC	= gcc

FLAGS	= -Wall -Wextra -Werror -Imlx

all:		${NAME}

.c.o:      
			${CC} ${FLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			${CC} ${OBJS} -lmlx -framework openGL -framework AppKit -o ${NAME}

clean:          
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

memory:		${OBJS}
			${CC} ${OBJS} -fsanitize=address -g3 -lmlx -framework openGL -framework AppKit -o ${NAME}

re:		fclean all

.PHONY:		all clean fclean re
