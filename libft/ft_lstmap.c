/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkandemi <bkandemi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 11:59:04 by bkandemi          #+#    #+#             */
/*   Updated: 2021/12/06 11:22:47 by bkandemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	del(t_list **head)
{
	t_list	*current;
	t_list	*next;

	current = *head;
	while (current != NULL)
	{
		next = current->next;
		free(current->content);
		free(current);
		current = next;
	}
	*head = NULL;
}

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*head;
	t_list	*previous;

	head = NULL;
	previous = NULL;
	while (lst != NULL)
	{
		new = (*f)(lst);
		if (head == NULL)
			head = new;
		else if (new == NULL)
		{
			del(&head);
			return (NULL);
		}
		if (previous != NULL)
			previous->next = new;
		previous = new;
		lst = lst->next;
	}
	return (head);
}
