/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 22:35:02 by sergio            #+#    #+#             */
/*   Updated: 2024/01/21 22:49:52 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_bzero(void *str, size_t len)
{
	size_t			i;
	unsigned char	*s;

	i = 0;
	s = str;
	while (i < len)
	{
		s[i] = '\0';
		i++;
	}
	return (str);
}