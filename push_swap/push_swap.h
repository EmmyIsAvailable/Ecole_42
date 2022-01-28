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
	char	**tab;
	int	len;
	int	p;
	int	ac;
	char	**av;
	t_stack	*a;
	t_stack	*b;
}	t_var;

/*main*/
void		ft_error(char *message, int error, t_var *arg);
t_var		ft_init(t_var *var, int ac, char **av);
char		**fill_stack(t_var *arg, int ac, char **av);
void		push_swap(t_var *arg);

/*checks*/
int		check_doubles(t_var *arg);
int		check_numbers(t_var *arg);
int		check_sorted_a(t_var *arg);
int		check_overflow(char *nb);
int		check_sorted_b(t_var *arg);

/*utils*/
void		**ft_free_tab(char **data);
long long	ft_atoll(char *nb);
int		ft_is_in_scope(char c);
void		free_init(t_var *arg);

/*list*/
t_stack		*ft_fill_stack(t_var *arg);
int		ft_size_stack(t_stack *a);
t_stack		*ft_lst_add_back(t_stack *front, t_stack *new);
void		ft_lstdel(t_stack *a);

/*action*/
void		ft_choice(t_var *arg, int a);
void		ft_choice2(t_var *arg, int a);
void		ft_choice3(t_var *arg, int a);

/*operations*/
t_stack		*ft_push(t_stack *a, t_stack *b);
t_stack		*ft_swap(t_stack *a);
t_stack		*ft_reverse(t_stack *a);
t_stack		*ft_rotate(t_stack *a);
int		is_in_tab(t_var *arg);

/*sort_a*/
void		ft_sort_3_a(t_var *arg);
void		ft_sort_2_a(t_var *arg);
t_stack		*ft_sort_a(t_var *arg, int len);
void		ft_reverse_a(t_var *arg, int *r);

/*median*/
int		ft_find_median(t_stack *a, int stack, int len);
int		*ft_sort_tab(int *tab, int len);
int		ft_median_sorted_a(t_var *arg, int *r, int *p, int len);
int		while_under_median(t_var *arg, int n, int median);
int		while_above_median(t_var *arg, int n, int median);

/*sort_b*/
void		ft_sort_3_b(t_var *arg);
void		ft_sort_2_b(t_var *arg);
t_stack		*ft_sort_b(t_var *arg, int len);
int		ft_median_sorted_b(t_var *arg, int *r, int *p, int len);
void		ft_reverse_b(t_var *arg, int *r);

/*sort_short*/
void		ft_sort_short_a(t_var *arg, t_stack *a);
void		ft_sort_short_b(t_var *arg, t_stack *b);

#endif
