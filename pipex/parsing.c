/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eruellan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 10:10:51 by eruellan          #+#    #+#             */
/*   Updated: 2022/01/12 12:31:10 by eruellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*search_envp(t_data *data)
{
	char	*path;
	int		i;

	i = -1;
	path = NULL;
	while (data->envp[++i])
	{
		path = ft_strnstr(data->envp[i], "PATH=", ft_strlen(data->envp[i]));
		if (path)
		{
			path = ft_substr(path, 5, ft_strlen(path));
			if (!path)
				ft_error("Error\n");
			return (path);
		}
	}
	return (NULL);
}

char	**get_envp(t_data *data)
{
	char	*env_path;
	char	**paths;

	env_path = search_envp(data);
	paths = ft_split(env_path, ':');
	free (env_path);
	if (!paths)
		ft_error("Error : split failed or getting envp failed\n");
	return (paths);
}

char	*get_binary(char *cmd, char **env_path)
{
	char	*tmp;
	char	*cmd_path;
	int		i;

	i = -1;
	tmp = NULL;
	cmd_path = NULL;
	while (env_path[++i])
	{
		tmp = ft_strjoin(env_path[i], "/");
		if (!tmp)
			ft_error("Error : tmp join failed\n");
		cmd_path = ft_strjoin(tmp, cmd);
		if (!cmd_path)
			ft_error("Error : cmd_path join failed\n");
		free(tmp);
		if (access(cmd_path, F_OK) == 0)
			return (cmd_path);
		free(cmd_path);
	}
	ft_error("Error : command not found\n");
	return (NULL);
}
