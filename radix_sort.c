/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   radix_sort.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: Xiaojing <Xiaojing@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/16 09:51:48 by Xiaojing      #+#    #+#                 */
/*   Updated: 2021/06/17 12:54:16 by Xiaojing      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	bit_max(int n)
{
	int	i;

	i = 0;
	while (n > 0)
	{
		n = n / 2;
		i++;
	}
	return (i);
}

void	move_to_stackb(t_nb **list_a, t_nb **list_b, int n)
{
	while (n > 0)
	{
		if (((*list_a)->position & 1) == 0)
		{
			push(list_b, list_a);
			write(1, "pb\n", 3);
		}
		else
		{
			rotate(list_a);
			write(1, "ra\n", 3);
		}
		n--;
	}
}

void	move_back(t_nb **list_a, t_nb **list_b)
{
	while (*list_b)
	{
		push(list_a, list_b);
		write(1, "pa\n", 3);
	}
}

void	transfer_bits(t_nb *list)
{
	while (list)
	{
		list->position = list->position >> 1;
		list = list->next;
	}
}

void	radix_sort(t_nb *list_a, t_nb *list_b, int n)
{
	int	max;

	max = bit_max(n);
	while (max > 0)
	{
		move_to_stackb(&list_a, &list_b, n);
		move_back(&list_a, &list_b);
		transfer_bits(list_a);
		max--;
	}
	free_list(&list_a);
}
