/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 21:59:10 by sergio            #+#    #+#             */
/*   Updated: 2024/01/22 13:58:54 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int value, size_t len)
{
	size_t			i;
	unsigned char	*s;

	i = 0;
	s = str;
	while (i < len)
	{
		s[i] = (unsigned char)value;
		i++;
	}
	return (str);
}
