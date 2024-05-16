/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 18:36:12 by sergio            #+#    #+#             */
/*   Updated: 2024/01/22 18:38:30 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *str, char (*f)(unsigned int, char))
{
	char	*new_str;
	int		i;

	if (!str || !f)
		return (NULL);
	new_str = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!new_str)
		return (NULL);
	i = 0;
	while (str[i])
	{
		new_str[i] = f(i, str[i]);
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}
