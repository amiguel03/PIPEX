/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 17:27:11 by sergio            #+#    #+#             */
/*   Updated: 2024/01/22 17:51:45 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(const char *str, char value)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] != value)
		{
			count++;
			while (str[i] != value && str[i])
				i++;
		}
		else if (str[i] == value)
			i++;
	}
	return (count);
}

static size_t	get_inti_len(const char *str, char value)
{
	size_t	len;

	len = 0;
	while (str[len] != value && str[len])
		len++;
	return (len);
}

static void	free_memory(size_t row, char **array)
{
	while (row--)
		free(array[row]);
	free(array);
}

static char	**fill_array(const char *str, char value, char **array, size_t word)
{
	size_t	row;
	size_t	col;

	row = 0;
	col = 0;
	while (row < word)
	{
		while (*(str + col) == value && *(str + col))
			col++;
		array[row] = ft_substr(str, col, get_inti_len(&*(str + col), value));
		if (!*(str + row))
		{
			free_memory(row, array);
			return (NULL);
		}
		while (*(str + col) != value && *(str + col))
			col++;
		row++;
	}
	array[row] = NULL;
	return (array);
}

char	**ft_split(const char *str, char value)
{
	size_t	word;
	char	**array;

	if (!str)
		return (NULL);
	word = count_words(str, value);
	array = (char **)malloc(sizeof(char *) * (word + 1));
	if (!array)
		return (NULL);
	array = fill_array(str, value, array, word);
	return (array);
}
