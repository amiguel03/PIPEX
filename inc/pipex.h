/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguel- <amiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 15:41:37 by amiguel-          #+#    #+#             */
/*   Updated: 2024/06/18 10:03:00 by amiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include "../libft/libft.h"
# include "structs.h"
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <fcntl.h>

void	therror(const char *error);
int		check_env(char **env);
char	*look_path(char *cmd, char **env);
void	ft_execve(char *argv, char **env);
int		file_in(char *argv, int x);
void	child(char *argv[], char **env, int *fd);
void	parent(char *argv[], char **env, int *fd);

#endif