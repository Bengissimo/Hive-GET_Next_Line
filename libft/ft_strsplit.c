/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkandemi <bkandemi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 12:43:09 by bkandemi          #+#    #+#             */
/*   Updated: 2021/12/08 14:16:35 by bkandemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	word_count(char const *s, char c)
{
	unsigned int	i;
	unsigned int	is_word;
	unsigned int	count;

	i = 0;
	is_word = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (is_word == 0 && s[i] != c)
		{
			is_word = 1;
			count++;
		}
		else if (is_word == 1 && s[i] == c)
		{
			is_word = 0;
		}
		i++;
	}
	return (count);
}

static unsigned int	word_len(char const *s, char c)
{
	unsigned int	i;
	unsigned int	is_word;
	unsigned int	len;

	i = 0;
	is_word = 0;
	len = 0;
	while (s[i] != '\0')
	{
		if (is_word == 0 && s[i] != c)
		{
			is_word = 1;
			len++;
		}
		else if (is_word == 1 && s[i] != c)
			len++;
		else if (is_word == 1 && s[i] == c)
			return (len);
		i++;
	}
	return (len);
}

static char	**split(char const *s, char c, char **array)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			array[j] = ft_strsub(s, i, word_len((s + i), c));
			if (!array[j])
			{
				ft_free_array(array, j);
				return (NULL);
			}
			i += word_len((s + i), c) - 1;
			j++;
		}
		i++;
	}
	array[j] = NULL;
	return (array);
}

char	**ft_strsplit(char const *s, char c)
{
	char	**array;

	if (!s)
		return (NULL);
	array = (char **)malloc(sizeof(char *) * (word_count(s, c) + 1));
	if (!array)
		return (NULL);
	array = split(s, c, array);
	return (array);
}
