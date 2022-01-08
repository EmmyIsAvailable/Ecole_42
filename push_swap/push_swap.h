#ifndef PUSH_SWAP
# define PUSH_SWAP

#include <unistd.h>
#include <limits.h>
#include <stdlib.h>
#include "./libft/libft.h"

# define SA 1
# define SB 2
# define SS 3
# define PA 4
# define PB 5
# define RA 6
# define RB 7
# define RR 8
# define RRA 9
# define RRB 10
# define RRR 11

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
int		check_sorted(t_var *arg);

/*utils*/
void		**ft_free_tab(char **data);
long long	ft_atoll(char *nb);
int		ft_is_in_scope(char c);

/*list*/
t_stack		*ft_fill_stack(t_var *arg);
int		ft_size_stack(t_var *arg);

#endif
