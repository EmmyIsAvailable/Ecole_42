#ifndef PIPEX_H
# define PIPEX_H

#include <unistd.h>
#include <fcntl.h>

typedef struct s_data
{
	char	**envp;
	char	**av;
	int	ac;
	int	outfile;
	int	infile;
	int	fd[2];
}	t_data;

#endif
