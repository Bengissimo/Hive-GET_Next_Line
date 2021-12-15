/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkandemi <bkandemi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 13:19:29 by bkandemi          #+#    #+#             */
/*   Updated: 2021/12/06 19:22:44 by bkandemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*trimmed;
	int		begin;
	int		end;

	if (!s)
		return (NULL);
	begin = 0;
	while (s[begin] == ' ' || s[begin] == '\n' || s[begin] == '\t')
	{
		begin++;
	}
	end = ft_strlen(s) - 1;
	while (end > begin && (s[end] == ' ' || s[end] == '\n' || s[end] == '\t'))
	{
		end--;
	}
	trimmed = (char *)malloc(sizeof(char) * (end - begin + 1 + 1));
	if (!trimmed)
		return (NULL);
	ft_strncpy(trimmed, s + begin, end - begin + 1);
	trimmed[end - begin + 1] = '\0';
	return (trimmed);
}
