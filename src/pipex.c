/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguel- <amiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 10:32:30 by amiguel-          #+#    #+#             */
/*   Updated: 2024/05/16 10:40:11 by amiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

int	main(int argc, char **argv, char  **env)
{
	t_data	data;
	
	if (argc != 5)
		ft_error("Error: invalid number of arguments", 1);
	ft_memset(&data, 0, sizeof(data));
	path_split(&data, env);
	child_one(&data, argv[1], argv[2], env);
	child_two(&data, argv[4], argv[3], env);
	data.status = close_wait(&data);
	ft_free(&data);
	return (WEXITSTATUS(data.status));
}
