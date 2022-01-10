/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   principal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eruellan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 10:11:48 by eruellan          #+#    #+#             */
/*   Updated: 2022/01/10 10:11:50 by eruellan         ###   ########.fr       */
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

void	child_process(t_data *data)
{
	if ((dup2(data->infile, STDIN_FILENO)) == -1)
		ft_error("Error");
	if ((dup2(data->fd[1], STDOUT_FILENO)) == -1)
		ft_error("Error");
	close (data->fd[0]);
	close (data->infile);
	ft_exec(data->av[2], data);
}

void	parent_process(t_data *data)
{
	if ((dup2(data->outfile, STDOUT_FILENO)) == -1)
		ft_error("Error");
	if ((dup2(data->fd[0], STDIN_FILENO)) == -1)
		ft_error("Error");
	close (data->fd[1]);
	if (waitpid(data->pid, NULL, 0) == -1)
		ft_error("Error waitpid");
	close (data->outfile);
	ft_exec(data->av[3], data);
}

void	pipex(t_data *data)
{
	if (pipe(data->fd) == -1)
		exit(EXIT_FAILURE);
	data->pid = fork();
	if (data->pid == -1)
		exit(EXIT_FAILURE);
	if (data->pid == 0)
		child_process(data);
	else
		parent_process(data);
}
