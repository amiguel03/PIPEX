/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 14:51:14 by sergio            #+#    #+#             */
/*   Updated: 2024/01/22 14:56:10 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int value, size_t len)
{
	const unsigned char	*s;
	size_t				i;

	s = str;
	i = 0;
	while (i < len)
	{
		if (*s == (unsigned char) value)
			return ((void *)s);
		s++;
		i++;
	}
	return (0);
}
