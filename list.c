/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   list.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: Xiaojing <Xiaojing@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/11 13:11:51 by Xiaojing      #+#    #+#                 */
/*   Updated: 2021/06/17 11:53:40 by Xiaojing      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_nb	*ft_lstlast(t_nb *lst)
{
	t_nb	*head;

	if (!lst)
		return (NULL);
	head = lst;
	while (head->next)
	{
		head = head->next;
	}
	return (head);
}

void	ft_lstadd_back(t_nb **lst, t_nb *new)
{
	t_nb	*last;

	if (new && *lst)
	{
		last = ft_lstlast(*lst);
		last->next = new;
		new->next = NULL;
	}
	else if (!*lst)
	{
		*lst = new;
		new->next = NULL;
	}
}

void	free_list(t_nb **lst)
{
	t_nb	*head;
	t_nb	*next;

	if (!lst)
		return ;
	head = *lst;
	while (head)
	{
		next = head->next;
		free(head);
		head = NULL;
		head = next;
	}
	*lst = NULL;
}

t_nb	*create_note(int t)
{
	t_nb	*a;

	a = malloc(sizeof(t_nb));
	if (!a)
		return (NULL);
	a->nb = t;
	a->next = NULL;
	return (a);
}
