/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   principal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eruellan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 10:11:48 by eruellan          #+#    #+#             */
/*   Updated: 2022/01/10 15:08:34 by eruellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_exec(char *av, t_data *data)
{
	char	**env_path;
	char	*binary;
	char	**cmd;

	cmd = ft_split(av, ' ');
	if (!cmd)
		ft_error("split failed or error occured getting command");
	env_path = get_envp(data);
	binary = get_binary(cmd[0], env_path);
	if (!binary)
		ft_error("error occured getting binary file in exec");
	ft_free_tab(env_path);
	if (execve(binary, cmd, data->envp) == -1)
	{
		free (binary);
		ft_free_tab(env_path);
		ft_free_tab(cmd);
		ft_error("Error");
	}
}

void	child1_process(t_data *data, char *cmd)
{
	if ((dup2(data->infile, STDIN_FILENO)) == -1)
		ft_error("Error");
	if ((dup2(data->fd[1], STDOUT_FILENO)) == -1)
		ft_error("Error");
	close (data->fd[0]);
	close (data->infile);
	ft_exec(cmd, data);
}

void	child2_process(t_data *data, char *cmd)
{
	if ((dup2(data->outfile, STDOUT_FILENO)) == -1)
		ft_error("Error");
	if ((dup2(data->fd[0], STDIN_FILENO)) == -1)
		ft_error("Error");
	close (data->fd[1]);
	close (data->outfile);
	ft_exec(cmd, data);
}

void	parent_process(t_data *data)
{
	close(data->fd[0]);
	close(data->fd[1]);
	if (waitpid(data->child1, NULL, 0) == -1)
		ft_error("Error waitpid");
	if (waitpid(data->child2, NULL, 0) == -1)
		ft_error("Error waitpid");
}

void	pipex(t_data *data, char *cmd1, char *cmd2)
{
	if (pipe(data->fd) == -1)
		exit(EXIT_FAILURE);
	data->child1 = fork();
	if (data->child1 == -1)
		exit(EXIT_FAILURE);
	if (data->child1 == 0)
		child1_process(data, cmd1);
	data->child2 = fork();
	if (data->child2 == -1)
		exit(EXIT_FAILURE);
	if (data->child2 == 0)
		child2_process(data, cmd2);
	parent_process(data);
}
