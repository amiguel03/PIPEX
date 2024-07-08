/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parent_child.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguel- <amiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 10:44:08 by amiguel-          #+#    #+#             */
/*   Updated: 2024/07/08 11:36:10 by amiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

int	file_in(char *argv, int x, int fd)
{
	int	file;

	file = 0;
	if (x == 1)
		file = open(argv, O_RDONLY);
	if (x == 2)
		file = open(argv, O_CREAT | O_TRUNC | O_WRONLY, 0644);
	if (file == -1)
	{
		close(fd);
		therror(FILE_ERROR);
	}
	return (file);
}

void	child(char *argv[], char **env, int *fd)
{
	int	infile;

	close(fd[0]);
	infile = file_in(argv[1], 1, fd[1]);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[1]);
	dup2(infile, STDIN_FILENO);
	close(infile);
	ft_execve(argv[2], env);
}

void	parent(char *argv[], char **env, int *fd)
{
	int	outfile;

	close(fd[1]);
	outfile = file_in(argv[4], 2, fd[0]);
	dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
	dup2(outfile, STDOUT_FILENO);
	close(outfile);
	ft_execve(argv[3], env);
}
