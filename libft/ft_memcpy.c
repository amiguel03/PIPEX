/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 23:04:02 by sergio            #+#    #+#             */
/*   Updated: 2024/01/21 23:24:36 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t len)
{
	size_t				i;
	const unsigned char	*s;
	unsigned char		*d;

	i = 0;
	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	if (d == NULL && s == NULL)
		return (NULL);
	while (i < len)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}
