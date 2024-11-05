/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parent_childs_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguel- <amiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 10:39:06 by amiguel-          #+#    #+#             */
/*   Updated: 2024/11/04 13:31:31 by amiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/pipex_bonus.h"

int	file_in(char *argv, int x, int fd_tmp)
{
	int	fd;

	fd = 0;
	if (x == 1)
		fd = open(argv, O_RDONLY);
	if (x == 2)
		fd = open(argv, O_CREAT | O_TRUNC | O_WRONLY, 0644);
	if (fd == -1)
	{
		close(fd_tmp);
		therror(FILE_ERROR);
	}
	return (fd);
}

void	ft_child(t_pipex_bonus *bonus, char *argv[], char **env, int *fd)
{
	int	infile;

	bonus->pid[bonus->index] = fork();
	if (bonus->pid[bonus->index] == -1)
		therror(FORK_ERROR);
	else if (bonus->pid[bonus->index] == 0)
	{
		close(fd[0]);
		infile = file_in(argv[1], 1, fd[1]);
		dup2(infile, STDIN_FILENO);
		dup2(fd[1], STDOUT_FILENO);
		close(infile);
		close(fd[1]);
		ft_execve(argv[bonus->ix_cmd], env);
	}
	bonus->ix_cmd++;
	bonus->fd_temp = fd[0];
	close(fd[1]);
	bonus->index++;
}

void ft_child_mid(t_pipex_bonus *bonus, char *argv[], char **env, int *fd)
{
	bonus->pid[bonus->index] = fork();
	if (bonus->pid[bonus->index] == -1)
		therror(FORK_ERROR);
	else if (bonus->pid[bonus->index] == 0)
	{
		close(fd[0]);
		dup2(bonus->fd_temp, STDIN_FILENO);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);
		close(bonus->fd_temp);
		ft_execve(argv[bonus->ix_cmd], env);
	}
	bonus->ix_cmd++;
	close(bonus->fd_temp);
	bonus->fd_temp = fd[0];
	close(fd[1]);
	bonus->index++;
}


void	ft_child_last(t_pipex_bonus *bonus, char *argv[], char **env, int *fd)
{
	int	outfile;

	if (pipe(fd) == -1)
		therror("Error pipe");
	bonus->pid[bonus->index] = fork();
	if (bonus->pid[bonus->index] == -1)
		therror(FORK_ERROR);
	else if (bonus->pid[bonus->index] == 0)
	{
		outfile = file_in(argv[bonus->ix_cmd + 1], 2, bonus->fd_temp);
		dup2(bonus->fd_temp, STDIN_FILENO);
		dup2(outfile, STDOUT_FILENO);
		close(bonus->fd_temp);
		close(outfile);
		ft_execve(argv[bonus->ix_cmd], env);
		close(fd[0]);
		close(fd[1]);
	}
	close(bonus->fd_temp);
	close(fd[0]);
	close(fd[1]);
}

