/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 16:50:11 by sergio            #+#    #+#             */
/*   Updated: 2024/01/22 16:57:42 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	size_t	str_len;
	char	*sub_str;
	size_t	i;

	if (!str)
		return (NULL);
	str_len = ft_strlen(str);
	if (start > str_len)
		len = 0;
	else if (start + len > str_len)
		len = str_len - start;
	sub_str = (char *)malloc(sizeof(char) * (len + 1));
	if (!sub_str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		sub_str[i] = str[start + i];
		i++;
	}
	sub_str[i] = '\0';
	return (sub_str);
}
