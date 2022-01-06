#ifndef PUSH_SWAP
# define PUSH_SWAP

#include <unistd.h>
#include <stdlib.h>
#include "./libft/libft.h"

typedef struct s_var
{
	int	ac;
	char	**av;
	char	**tab;
	int	len;
}	t_var;

void	check_doubles(t_var *arg);

#endif
