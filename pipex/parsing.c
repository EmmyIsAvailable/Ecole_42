#include "pipex.h"

char	*search_envp(t_data *data)
{
	char	*path;
	int	i;

	i = -1;
	path = NULL;
	while (data->envp[++i])
	{
		path = ft_strnstr(data->envp[i], "PATH=", ft_strlen(data->envp[i]));
		if (path)
		{
			path = ft_substr(path, 5, ft_strlen(path));
			if (!path)
				ft_error("Error");
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
		ft_error("split failed or error occured getting envp");
	return (paths);
}

char	*get_binary(char *cmd, char **env_path)
{
	char	*tmp;
	char	*cmd_path;
	int	i;

	i = -1;
	tmp = NULL;
	cmd_path = NULL;
	while (env_path[++i])
	{
		tmp = ft_strjoin(env_path[i], "/");
		if (!tmp)
			ft_error("tmp join failed");
		cmd_path = ft_strjoin(tmp, cmd);
		if (!cmd_path)
			ft_error("cmd_path join failed");
		free(tmp);
		if (access(cmd_path, F_OK) == 0)
			return (cmd_path);
		free(cmd_path);
	}
	ft_error("error occured getting binary file in parsing");
	return (NULL);
}
