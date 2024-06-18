/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguel- <amiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 10:32:30 by amiguel-          #+#    #+#             */
/*   Updated: 2024/06/18 10:00:36 by amiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

int	main(int argc, char **argv, char **env)
{
	int		fd[2];
	pid_t	pid[2];
	int		status;

	if (argc != 5)
		therror(ERROR_ARGS);
	if (pipe(fd) == -1)
		therror("Error pipe");
	pid[0] = fork();
	if (pid[0] == -1)
		therror(FORK_ERROR);
	else if (pid[0] == 0)
		child(argv, env, fd);
	pid[1] = fork();
	if (pid[1] < 0)
		therror(FORK_ERROR);
	else if (pid[1] == 0)
		parent(argv, env, fd);
	close(fd[0]);
	close(fd[1]);
	waitpid(pid[0], NULL, 0);
	waitpid(pid[1], &status, 0);
	return (WEXITSTATUS(status));
}
