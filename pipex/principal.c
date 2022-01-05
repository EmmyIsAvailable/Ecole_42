#include "pipex.h"

void	ft_exec(char *av, t_data *data)
{
	char	**env_path;
	char	**my_path;
	char	**cmd;

	cmd = ft_split(av, " ");
	if (!cmd)
		ft_error("split failed or error occured getting command");
	env_path = get_envp(data);
}

void	child_process(t_data *data)
{
	if ((dup2(data->infile, STDIN_FILENO)) == -1)
		ft_error("Error");
	if ((dup2(data->fd[1], STDOUT_FILENO)) == -1)
		ft_error("Error");
	close (data->fd[0]);
	close (data->infile);
}

void	parent_process(t_data *data)
{
	int	status;

	waitpid(-1, &status, 0);
	if ((dup2(data->outfile, STDOUT_FILENO)) == -1)
		ft_error("Error");
	if ((dup2(data->fd[0], STDIN_FILENO)) == -1)
		ft_error("Error");
	close (data->fd[1]);
	close (data->outfile);

}

void	ft_pipex(t_data *data)
{
	pid_t	pid;

	if (pipe(data->fd) == -1)
		exit(EXIT_FAILURE);
	pid = fork();
	if (pid == -1)
		exit(EXIT_FAILURE);
	if (pid == 0)
		child_process(data);
	else
		parent_process(data);
}
