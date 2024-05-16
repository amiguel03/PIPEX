/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguel- <amiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 10:52:51 by amiguel-          #+#    #+#             */
/*   Updated: 2024/05/16 10:49:22 by amiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	child_one(t_data *data, char *file, char *command, char **env)
{
	if (pipe(data->pipe_fd) == -1)
		perror("Error : pipe not created\n");
	data->pid_child_one = fork();
	if (data->pid_child_one == 0)
	{
		close(data->pipe_fd[R]);
		valid_path(command, data);
		data->infile_fd = open(file, O_RDONLY);
		if (data->infile_fd == -1)
		{
			close(data->pipe_fd[R]);
			ft_error ("Error", 1);
		}
		dup2(data->infile_fd, STDIN_FILENO);
		dup2(data->pipe_fd[W], STDOUT_FILENO);
		close(data->infile_fd);
		close(data->pipe_fd[W]);
		execve(data->valid_path, data->matrix_cmd, env);
		ft_free(data);
		exit(127);
	}
	else if (data->pid_child_one < 0)
		ft_error("Error: fork not created\n", 1);
}

void	child_two(t_data *data, char *file, char *command, char **env)
{
	data->pid_child_two = fork();
	if (data->pid_child_two == 0)
	{
		valid_path(command, data);
		data->outfile_fd = open (file, O_RDWR | O_CREAT | O_TRUNC, 0644);
		if (data->outfile_fd == -1)
			perror("Error");
		dup2(data->pipe_fd[R], STDIN_FILENO);
		dup2(data->outfile_fd, STDOUT_FILENO);
		close(data->outfile_fd);
		close(data->pipe_fd[W]);
		execve(data->valid_path, data->matrix_cmd, env);
		ft_free(data);
		exit(127);
	}
	else if (data->pid_child_two < 0)
		ft_error("Error: fork not created", 1);
}
