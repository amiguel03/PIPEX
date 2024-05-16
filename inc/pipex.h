/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguel- <amiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 15:41:37 by amiguel-          #+#    #+#             */
/*   Updated: 2024/05/16 10:48:18 by amiguel-         ###   ########.fr       */
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

# define R 0
# define W 1


// ft_childs.c
// ft_child_one realiza la ejecución del primer hijo.
void	child_one(t_data *data, char *file, char *command, char **env);
// ft_child_two realiza la ejecución del segundo hijo.
void	child_two(t_data *data, char *file, char *command, char **env);
// ft_child_middle realiza la ejecución de los hijos intermedios.

// ft_child_last realiza la ejecución del último hijo.

// ft_foock realiza la funcion de crear todos los hijos necesarios


// ft_path.c
// ft_search_valid_path busca la ruta válida del comando.
void	valid_path(char *command, t_data *d);
// ft_split_path separa la variable de entorno PATH.
void	path_split(t_data *data, char **env);

// ft_utils.c
// ft_free_matrix libera la memoria de la matriz.
void	free_mat(char **mat);
// ft_close_n_wait cierra los pipes y espera a que los hijos terminen.
int	close_wait(t_data *data);
// ft_pipe crea un pipe.
void	ft_pipe(t_data *data);
// ft_free libera la memoria.
void	ft_free(t_data	*data);
// ft_error imprime un mensaje de error y termina el programa.
void	ft_error(char *msg, int n_error);

#endif