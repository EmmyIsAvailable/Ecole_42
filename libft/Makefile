NAME 		= libft.a

FLAGS 		= -Wall -Wextra -Werror

SRCS 		= atoi.c bzero.c calloc.c isalnum.c isalpha.c isascii.c isdigit.c //
			isprint.c itoa.c memchr.c memcmp.c memcpy.c memmove.c memset.c //
			putchar_fd.c putendl_fd.c putnbr_fd.c putstr_fd.c split.c strchr.c //
			strdup.c striteri.c strjoin.c strlcat.c strlcpy.c strlen.c strmapi.c //
			strncmp.c strnstr.c strrchr.c strtrim.c substr.c tolower.c toupper.c

BONUS		= lstnew.c lstadd_front.c lstsize.c lstlast.c lstadd_back.c lstdelone.c //
			

OBJS 		= ${SRCS:.c=.o}

BONUS_OBJS	= ${BONUS:.c=.o}

INCDIR 		= ./includes/

RM 			= rm -rf

all: 		${NAME}

.c.o:
				gcc ${FLAGS} -I ${INCDIR} -c $< -o ${:.c=.o}

${NAME}: 	${OBJS}
				ar rc ${NAME} ${OBJS}

bonus:		${OBJS} ${BONUS_OBJS}
				ar rc ${NAME} ${OBJS} ${BONUS_OBJS}

clean:
				${RM} ${OBJS} ${BONUS_OBJS}

fclean:		clean
				${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re