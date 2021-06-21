/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_small2.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: Xiaojing <Xiaojing@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/16 23:15:11 by Xiaojing      #+#    #+#                 */
/*   Updated: 2021/06/17 11:51:38 by Xiaojing      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	insertfront(t_nb **a, t_nb **b, int i)
{
	int	temp;

	temp = i;
	while (i > 0)
	{
		rotate(a);
		write(1, "ra\n", 3);
		i--;
	}
	push(a, b);
	write(1, "pa\n", 3);
	while (temp > 0)
	{
		rv_rotate(a);
		write(1, "rra\n", 4);
		temp--;
	}
}

void	insertback(t_nb **a, t_nb **b, int i)
{
	int	temp;

	temp = i;
	while (i > 0)
	{
		rv_rotate(a);
		write(1, "rra\n", 4);
		i--;
	}
	push(a, b);
	write(1, "pa\n", 3);
	while (temp >= 0)
	{
		rotate(a);
		write(1, "ra\n", 3);
		temp--;
	}
}

int	map_position(t_nb *a, t_nb *b)
{
	int	i;

	i = 0;
	while (a)
	{
		if (b->nb == a->nb)
			return (-1);
		else if (b->nb < a->nb)
			return (i);
		else
			a = a->next;
		i++;
	}
	return (i);
}

int	add_back(t_nb **a, t_nb **b)
{
	int	i;
	int	n;

	n = 3;
	while (*b)
	{
		i = map_position(*a, *b);
		if (i == -1)
			return (1);
		if (i <= n / 2)
			insertfront(a, b, i);
		else
			insertback(a, b, n - i);
		n++;
	}
	return (0);
}

int	sort_3plus(int n, t_nb **list_a, t_nb **list_b)
{
	if (check_duplicate_list(n, *list_a) == 1)
		return (1);
	if (check_ascend(*list_a) == 0)
		return (0);
	while (n > 3)
	{
		push(list_b, list_a);
		write(1, "pb\n", 3);
		n--;
	}
	sort_3(list_a);
	add_back(list_a, list_b);
	return (0);
}
