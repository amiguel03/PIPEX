/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguel- <amiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 10:30:49 by amiguel-          #+#    #+#             */
/*   Updated: 2024/05/15 10:31:34 by amiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_data
{
	char	*matrix_joined_path;
	char	**matrix_path;
	char	**matrix_cmd;

	char	*valid_path;
	char	*temp_path;

	int		outfile_fd;
	int		pipe_fd[2];
	int		infile_fd;
	int		tmp_fd;

	int		pid_child_one;
	int		pid_child_two;
	int		pid_child_last;
	int		*pid_childs;
	int		pid_reader;

	int		status;
	int		num_cmd_middle;
	int		index_pid;
	int		index_cmd_middle;
	int		here_doc;

}				t_data;

#endif