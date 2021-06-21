/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sorting.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: Xiaojing <Xiaojing@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/12 00:35:33 by Xiaojing      #+#    #+#                 */
/*   Updated: 2021/06/18 12:53:38 by Xiaojing      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* allocate elements to a array to sort, leave first element as zero for
heapsort convenience */
void	convert_array(int *array, t_nb *list, int n)
{
	int	i;

	i = 1;
	array[0] = 0;
	while (i < n + 1)
	{
		array[i] = list->nb;
		i++;
		list = list->next;
	}
}

int	check_duplicates(int *array, int n)
{
	while (n > 1)
	{
		if (array[n] == array[n - 1])
			return (1);
		n--;
	}
	return (0);
}

void	put_position(int *array, t_nb *list, int n)
{
	int	median;

	median = array[n / 2];
	while (list)
	{
		if (list->nb <= median)
			locate(1, n / 2, array, list);
		else
			locate(n / 2, n, array, list);
		list = list->next;
	}
}

int	sort_large(int n, t_nb *list, t_nb *list_b)
{
	int	*array;

	if (check_ascend(list) == 0)
		return (0);
	array = malloc((n + 1) * sizeof(int));
	if (!array)
	{
		free_list(&list);
		return (1);
	}
	convert_array(array, list, n);
	heap_sort(array, n);
	if (check_duplicates(array, n) == 1)
	{
		free(array);
		free_list(&list);
		return (1);
	}
	put_position(array, list, n);
	radix_sort(list, list_b, n);
	free(array);
	return (0);
}

int	sort(int n, t_nb **list)
{
	t_nb	*list_b;

	list_b = NULL;
	if (n == 1)
		return (0);
	if (n <= 6)
		return (sort_small(n, *list, list_b));
	if (n > 6)
		return (sort_large(n, *list, list_b));
	return (0);
}
