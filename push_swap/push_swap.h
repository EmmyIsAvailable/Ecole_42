#ifndef PUSH_SWAP
# define PUSH_SWAP

#include <unistd.h>
#include <limits.h>
#include <stdlib.h>
#include "./libft/libft.h"

typedef struct s_stack
{
	int	val;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

typedef struct s_var
{
	int	ac;
	char	**av;
	char	**tab;
	int	len;
	t_stack	*a;
	t_stack	*b;
}	t_var;

/*main*/
void		ft_error(char *message, int error);

/*checks*/
int		check_doubles(t_var *arg);
int		check_numbers(t_var *arg);

/*utils*/
void		**ft_free_tab(char **data);
long long	ft_atoll(char *nb);
int		ft_is_in_scope(char c);

/*list*/
t_stack		*ft_fill_stack(t_var *arg);

#endif
