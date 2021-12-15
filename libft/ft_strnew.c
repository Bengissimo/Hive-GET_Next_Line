/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkandemi <bkandemi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 10:00:16 by bkandemi          #+#    #+#             */
/*   Updated: 2021/11/08 10:36:06 by bkandemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*str;
	int		index;

	str = (char *)malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	index = 0;
	while (size-- > 0)
	{
		str[index] = '\0';
		index++;
	}
	str[index] = '\0';
	return (str);
}
