/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: Xiaojing <Xiaojing@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/11 15:17:02 by Xiaojing      #+#    #+#                 */
/*   Updated: 2021/06/17 11:07:00 by Xiaojing      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long	ft_atoi(const char *str)
{
	int			i;
	int			sign;
	long long	num;

	i = 0;
	sign = 1;
	num = 0;
	while (str[i] == 32 || (str[i] > 8 && str[i] < 14))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		i++;
		if (str[i - 1] == '-')
			sign = -1;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	num = num * sign;
	return (num);
}

int	isnumber(char c)
{
	if (c < 58 && c > 47)
		return (1);
	else
		return (-1);
}

void	locate(int a, int b, int *array, t_nb *list)
{
	while (a <= b)
	{
		if (list->nb == array[a])
			list->position = a;
		a++;
	}
}

int	check_ascend(t_nb *list)
{
	while (list->next)
	{
		if (list->nb > list->next->nb)
			return (1);
		else
			list = list->next;
	}
	return (0);
}

int	check_duplicate_list(int n, t_nb *list)
{
	int	*array;
	int	i;
	int	j;

	i = 1;
	array = malloc((n + 1) * sizeof(int));
	if (!array)
	{
		free_list(&list);
		return (1);
	}
	convert_array(array, list, n);
	while (i < n + 1)
	{
		j = i + 1;
		while (j < n + 1)
		{
			if (array[i] == array[j])
				return (1);
			j++;
		}
		i++;
	}
	free(array);
	return (0);
}
