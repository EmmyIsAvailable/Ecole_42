NAME 	= libft.a

FLAGS 	= -Wall -Wextra -Werror

SRCS 	= atoi.c isprint.c strmapi.c isalpha.c isdigit.c isalnum.c isascii.c \
		strlen.c memset.c bzero.c memcpy.c memmove.c strlcpy.c strlcat.c \
		toupper.c tolower.c strchr.c strrchr.c strncmp.c memchr.c memcmp.c \
		strnstr.c calloc.c strdup.c substr.c strjoin.c strtrim.c split.c \
		itoa.c 

OBJS 	= ${addprefix ${SRCDIR}, ${SRCS:.c=.o}}

SRCDIR 	= ./srcs/

INCDIR 	= ./includes/

RM 		= rm -rf

all: 		${NAME}

.c.o:
				gcc ${FLAGS} -I ${INCDIR} -c $< -o ${:.c=.o}

${NAME}: 	${OBJS}
				ar rc ${NAME} ${OBJS}

clean:
				${RM} ${OBJS}

fclean:		clean
				${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re