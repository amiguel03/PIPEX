/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguel- <amiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 10:50:13 by amiguel-          #+#    #+#             */
/*   Updated: 2024/11/04 12:50:35 by amiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "structs.h"
# include "pipex.h"

typedef struct s_pipex_bonus
{
	int num_com;
	int mid_com;
	int index;
	int ix_cmd;
	pid_t	*pid;
	int	fd_temp;
}				t_pipex_bonus;

void	ft_child(t_pipex_bonus *bonus, char *argv[], char **env, int *fd);
void 	ft_child_mid(t_pipex_bonus *bonus, char *argv[], char **env, int *fd);
void	ft_child_last(t_pipex_bonus *bonus, char *argv[], char **env, int *fd);

#endif