/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 14:26:03 by sergio            #+#    #+#             */
/*   Updated: 2024/01/22 14:32:04 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int value)
{
	while (*str)
	{
		if (*str == (char)value)
			return ((char *)str);
		str++;
	}
	if (*str == (char)value)
		return ((char *)str);
	return (0);
}
