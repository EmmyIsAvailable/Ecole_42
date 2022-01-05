#include "pipex.h"

char	*search_envp(t_data *data)
{
	char	*path;
	int	i;

	i = -1;
	path = NULL;
	while (data->envp[++i])
	{
		path = ft_strnstr(envp[i], "PATH=", ft_strlen(envp[i]));
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
	paths = ft_split(env_path, ":");
	free (env_path);
	if (!paths)
		ft_error("split failed or error occured getting envp");
	return (paths);
}
