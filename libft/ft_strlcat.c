/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 13:25:22 by sergio            #+#    #+#             */
/*   Updated: 2024/01/22 13:58:21 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	available_space;
	size_t	i;

	dst_len = 0;
	while (dst[dst_len] != '\0' && dst_len < dstsize)
		dst_len++;
	available_space = dstsize - dst_len;
	if (available_space > 1)
	{
		i = 0;
		while (src[i] != '\0' && i < available_space - 1)
		{
			dst[dst_len + i] = src[i];
			i++;
		}
		dst[dst_len + i] = '\0';
	}
	return (dst_len + ft_strlen(src));
}
