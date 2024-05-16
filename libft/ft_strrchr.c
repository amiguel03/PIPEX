/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 14:37:30 by sergio            #+#    #+#             */
/*   Updated: 2024/01/22 23:14:29 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int value)
{
	char	*last;

	last = NULL;
	while (*str)
	{
		if (*str == (char)value)
			last = (char *)str;
		str++;
	}
	if ((char)value == '\0')
		return ((char *)str);
	return (last);
}
