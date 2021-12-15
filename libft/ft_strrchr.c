/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkandemi <bkandemi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 15:22:15 by bkandemi          #+#    #+#             */
/*   Updated: 2021/11/16 13:45:14 by bkandemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	len;
	size_t	i;
	char	*ptr;

	ptr = (char *)s;
	len = ft_strlen(s);
	i = 0;
	while (i < len + 1)
	{
		if (s[len - i] == (char)c)
			return (ptr + len - i);
		i++;
	}
	return (NULL);
}
