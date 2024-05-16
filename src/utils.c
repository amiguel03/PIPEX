/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguel- <amiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 10:55:24 by amiguel-          #+#    #+#             */
/*   Updated: 2024/05/15 10:47:18 by amiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	ft_error(char *msg, int n_error)
{
	perror(msg);
	exit(n_error);
}

void	free_mat(char **mat)
{
	int	i;

	i = 0;
	if (!mat)
		return ;
	while (mat[i])
	{
		free(mat[i]);
		mat[i] = NULL;
		i++;
	}
}

void	ft_pipe(t_data *data)
{
	if (pipe(data->pipe_fd) == -1)
		perror("Error : pipe not created\n");
}

void	ft_free(t_data	*data)
{
	free(data->valid_path);
	free_mat (data->matrix_cmd);
	free(data->matrix_cmd);
	free_mat (data->matrix_path);
	free(data->matrix_path);
}

int	close_wait(t_data *data)
{
	int	status;

	close(data->pipe_fd[0]);
	close(data->pipe_fd[1]);
	waitpid (data->pid_child_one, NULL, 0);
	waitpid (data->pid_child_two, &status, 0);
	return (status);
}
