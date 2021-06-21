/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rules1.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: Xiaojing <Xiaojing@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/10 15:36:54 by Xiaojing      #+#    #+#                 */
/*   Updated: 2021/06/17 09:53:18 by Xiaojing      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_nb **nb)
{
	t_nb	*first;
	t_nb	*second;
	t_nb	*third;

	first = *nb;
	*nb = (*nb)->next;
	if (!nb)
		return ;
	second = *nb;
	*nb = (*nb)->next;
	if (!nb)
		return ;
	third = *nb;
	second->next = first;
	first->next = third;
	*nb = second;
}

void	push(t_nb **a, t_nb **b)
{
	t_nb	*first;
	t_nb	*second;

	if (!b)
		return ;
	first = *b;
	second = (*b)->next;
	first->next = *a;
	*a = first;
	*b = second;
}

void	rotate(t_nb **a)
{
	t_nb	*first;
	t_nb	*second;
	t_nb	*last;

	first = *a;
	last = ft_lstlast(*a);
	second = (*a)->next;
	last->next = first;
	first->next = NULL;
	*a = second;
}

void	rv_rotate(t_nb **a)
{
	t_nb	*first;
	t_nb	*old;

	if (!a)
		return ;
	first = *a;
	while ((*a)->next)
	{
		old = *a;
		*a = (*a)->next;
	}
	old->next = NULL;
	(*a)->next = first;
}
