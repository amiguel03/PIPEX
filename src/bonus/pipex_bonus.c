/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguel- <amiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 10:37:56 by amiguel-          #+#    #+#             */
/*   Updated: 2024/11/05 11:44:23 by amiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/pipex_bonus.h"

void	ft_init(t_pipex_bonus *bonus, int argc)
{
	bonus->num_com = argc - 3;
	bonus->mid_com = bonus->num_com - 2;
	bonus->index = 0;
	bonus->ix_cmd = 2;
	bonus->fd_temp = 0;
	bonus->pid = ft_calloc(sizeof(pid_t), bonus->num_com);
}

void	ft_childex(t_pipex_bonus *bonus, int *fd, char **argv, char **env)
{
	ft_child(bonus, argv, env, fd);
	while (bonus->mid_com > 0)
	{
		if (pipe(fd) == -1)
			therror("Error pipe");
		ft_child_mid(bonus, argv, env, fd);
		bonus->mid_com--;
	}
	ft_child_last(bonus, argv, env, fd);
	close(fd[1]);
}

int	main(int argc, char **argv, char **env)
{
	int				fd[2];
	int				status;
	int				i;
	t_pipex_bonus	bonus;

	i = 0;
	if (argc < 6)
		therror(ERROR_ARGS);
	ft_init(&bonus, argc);
	if (pipe(fd) == -1)
		therror("Error pipe");
	ft_childex(&bonus, fd, argv, env);
	while (i + 1 < bonus.index)
		waitpid(bonus.pid[i++], NULL, 0);
	waitpid(bonus.pid[i], &status, 0);
	free(bonus.pid);
	return (WEXITSTATUS(status));
}
