/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   heap_sort.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: Xiaojing <Xiaojing@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/14 14:08:55 by Xiaojing      #+#    #+#                 */
/*   Updated: 2021/06/17 11:39:19 by Xiaojing      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sswap(int *array, int a, int b)
{
	int	temp;

	temp = array[a];
	array[a] = array[b];
	array[b] = temp;
}

int	*heapify(int *array, int i, int n)
{
	int	left;
	int	right;
	int	max;

	left = 2 * i;
	right = 2 * i + 1;
	if ((left <= n) && (array[left] > array[i]))
		max = left;
	else
		max = i;
	if ((right <= n) && (array[max] < array[right]))
		max = right;
	if (max != i)
	{
		sswap(array, max, i);
		return (heapify(array, max, n));
	}
	else
		return (array);
}

int	*build_maxheap(int *array, int n)
{
	int	i;

	i = n / 2;
	while (i > 0)
	{
		heapify(array, i, n);
		i--;
	}
	return (array);
}

int	*heap_sort(int *array, int n)
{
	int	i;

	i = n;
	array = build_maxheap(array, n);
	while (i > 0)
	{
		sswap(array, 1, i);
		heapify(array, 1, i - 1);
		i--;
	}
	if (array[1] > array[2])
		sswap(array, 1, 2);
	return (array);
}
