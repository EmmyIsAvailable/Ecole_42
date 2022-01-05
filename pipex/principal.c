#include "pipex.h"

void	ft_exec(char *av, t_data *data)
{
	char	**env_path;
	char	*binary;
	char	**cmd;

	cmd = ft_split(av, " ");
	if (!cmd)
		ft_error("split failed or error occured getting command");
	env_path = get_envp(data);
	binary = get_binary(cmd[0], env_path);
	if (!binary)
		ft_error("error occured getting binary file in exec");
	//free env_path
	if (execve(binary, cmd, data->envp) == -1)
	{
		free (binary);
		//free env_path
		//free cmd
		ft_error("Error");
	}
}

void	child_process(t_data *data)
{
	if ((dup2(data->infile, STDIN_FILENO)) == -1)
		ft_error("Error");
	if ((dup2(data->fd[1], STDOUT_FILENO)) == -1)
		ft_error("Error");
	close (data->fd[0]);
	close (data->infile);
	ft_exec(data->av[1], data);
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
	ft_exec(data->av[2], data);
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
