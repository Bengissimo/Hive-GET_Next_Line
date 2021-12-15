/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkandemi <bkandemi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 10:21:13 by bkandemi          #+#    #+#             */
/*   Updated: 2021/11/22 22:42:42 by bkandemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *ndl, size_t len)
{
	char	*ptr;
	size_t	i;
	size_t	j;

	ptr = (char *)haystack;
	i = 0;
	if (ndl[0] == '\0')
		return (ptr);
	while (haystack[i] != '\0')
	{
		j = 0;
		while (haystack[i] != '\0' && haystack[i + j] == ndl[j] && i + j < len)
		{	
			j++;
			if (ndl[j] == '\0')
				return (ptr + i);
		}
		i++;
	}
	return (NULL);
}
