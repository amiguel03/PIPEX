/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguel- <amiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 10:39:44 by amiguel-          #+#    #+#             */
/*   Updated: 2024/11/05 11:44:36 by amiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/pipex_bonus.h"

int	check_env(char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
			return (i);
		i++;
	}
	therror(ENV_ERROR);
	exit(EXIT_FAILURE);
}

char	*look_path(char *cmd, char **envp)
{
	int		i;
	int		env;
	char	**paths;
	char	*path;
	char	*aux;

	if (ft_strchr(cmd, '/'))
		return (cmd);
	env = check_env(envp);
	paths = ft_split(envp[env] + 5, ':');
	i = 0;
	while (paths[i])
	{
		aux = ft_strjoin(paths[i], "/");
		path = ft_strjoin(aux, cmd);
		free(aux);
		if (access(path, F_OK) == 0)
			return (path);
		i++;
	}
	return (NULL);
}

void	ft_execve(char *argv, char **env)
{
	char	**cmd;

	cmd = ft_split(argv, ' ');
	if (cmd == NULL)
	{
		therror(ENV_ERROR);
		return ;
	}
	if (execve(look_path(cmd[0], env), cmd, env) == -1)
		therror(CMD_ERROR);
}
