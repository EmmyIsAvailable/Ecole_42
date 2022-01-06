#ifndef PIPEX_H
# define PIPEX_H

#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include "./libft/libft.h"

typedef struct s_data
{
	char	**envp;
	char	**av;
	int	ac;
	int	outfile;
	int	infile;
	int	fd[2];
	pid_t	pid;
}	t_data;

void	pipex(t_data *data);
void	ft_error(char *str);
char	**get_envp(t_data *data);
char	*get_binary(char *cmd, char **env_path);
void	ft_exec(char *av, t_data *data);
void	**ft_free_tab(char **data);

#endif
