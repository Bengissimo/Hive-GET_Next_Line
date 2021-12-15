/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkandemi <bkandemi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 16:02:44 by bkandemi          #+#    #+#             */
/*   Updated: 2021/11/15 21:57:37 by bkandemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	char	*ptr;
	int		i;
	int		j;

	ptr = (char *)haystack;
	i = 0;
	if (needle[0] == '\0')
		return (ptr);
	while (haystack[i] != '\0')
	{
		j = 0;
		while (haystack[i] != '\0' && haystack[i + j] == needle[j])
		{	
			j++;
			if (needle[j] == '\0')
				return (ptr + i);
		}
		i++;
	}
	return (NULL);
}
