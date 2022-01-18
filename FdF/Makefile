NAME	= fdf 

SRCS	= main.c ft_window.c ft_map.c parameters.c draw_win.c hook_details.c bresenham.c

OBJS	= ${SRCS:.c=.o}

RM	= rm -f

CC	= gcc

FLAGS	= -Wall -Wextra -Werror -Imlx

LIBFT		= ./libft/libft.a

all:		${NAME}

.c.o:      
			@${CC} ${FLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS} ${LIBFT}
			@echo "$(shell tput bold)$(shell tput setaf 5)Compiling...$(shell tput sgr0)"
			@${CC} ${OBJS} -lmlx -framework openGL -framework AppKit -o ${NAME} ${LIBFT}
			@echo "$(shell tput bold)$(shell tput setaf 5)DONE$(shell tput sgr0)"

${LIBFT}:	
			@echo "$(shell tput bold)$(shell tput setaf 5)Building libft...$(shell tput sgr0)"
			@make -sC libft
			@echo "$(shell tput bold)$(shell tput setaf 5)DONE$(shell tput sgr0)"

clean:          
			@${RM} ${OBJS}
			@echo "$(shell tput bold)$(shell tput setaf 5)Deleting object files...$(shell tput sgr0)"
			@echo "$(shell tput bold)$(shell tput setaf 5)DONE$(shell tput sgr0)"

fclean:		clean
			@${RM} ${NAME}
			@echo "$(shell tput bold)$(shell tput setaf 5)Deleting binaries...$(shell tput sgr0)"
			@make fclean -sC ./libft 
			@echo "$(shell tput bold)$(shell tput setaf 5)Cleaning libft...$(shell tput sgr0)"
			@echo "$(shell tput bold)$(shell tput setaf 5)DONE$(shell tput sgr0)"

memory:		${OBJS}
			${CC} ${OBJS} -fsanitize=address -g3 -lmlx -framework openGL -framework AppKit -o ${NAME}

re:			@fclean all

.PHONY:		all clean fclean re
