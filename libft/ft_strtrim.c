/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 17:09:03 by sergio            #+#    #+#             */
/*   Updated: 2024/01/22 17:16:38 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *str, char const *set)
{
	size_t	str_len;
	size_t	start;
	size_t	end;

	if (str == NULL || set == NULL)
		return (NULL);
	str_len = ft_strlen(str);
	start = 0;
	while (str[start] && ft_strchr(set, str[start]))
		start++;
	end = str_len;
	while (end > start && ft_strchr(set, str[end - 1]))
		end--;
	return (ft_substr(str, start, end - start));
}
