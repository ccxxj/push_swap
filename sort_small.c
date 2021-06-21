/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_small.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: Xiaojing <Xiaojing@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/16 13:45:42 by Xiaojing      #+#    #+#                 */
/*   Updated: 2021/06/17 11:52:02 by Xiaojing      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_2(t_nb **list)
{
	if ((*list)->nb > (*list)->next->nb)
	{
		swap(list);
		write(1, "sa\n", 3);
		return (0);
	}
	else if ((*list)->nb == (*list)->next->nb)
		return (1);
	else
		return (0);
}

void	sort_3i(int a, int b, int c, t_nb **list)
{
	if (a > b && b > c)
	{
		swap(list);
		rv_rotate(list);
		write(1, "sa\nrra\n", 7);
	}
	if (a > c && c > b)
	{
		rotate(list);
		write(1, "ra\n", 3);
	}
	if (a < c && b > c)
	{
		swap(list);
		rotate(list);
		write(1, "sa\nra\n", 6);
	}
	if (a > c && b > a)
	{
		rv_rotate(list);
		write(1, "rra\n", 4);
	}
}

int	sort_3(t_nb **list)
{
	int		a;
	int		b;
	int		c;
	t_nb	*head;

	head = *list;
	a = head->nb;
	head = head->next;
	b = head->nb;
	c = (head->next)->nb;
	if (a == b || b == c || a == c)
		return (1);
	else if (check_ascend(*list) == 0)
		return (0);
	if (a > b && a < c)
	{
		swap(list);
		write(1, "sa\n", 3);
	}
	else
		sort_3i(a, b, c, list);
	return (0);
}

int	sort_small(int n, t_nb *list_a, t_nb *list_b)
{
	int	result;

	if (n == 2)
	{
		result = sort_2(&list_a);
		free_list(&list_a);
		return (result);
	}
	if (n == 3)
	{
		result = sort_3(&list_a);
		free_list(&list_a);
		return (result);
	}
	if (n > 3)
	{
		result = sort_3plus(n, &list_a, &list_b);
		free_list(&list_a);
		return (result);
	}
	return (0);
}
