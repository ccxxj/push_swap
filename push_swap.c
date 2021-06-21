/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: Xiaojing <Xiaojing@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/11 14:41:43 by Xiaojing      #+#    #+#                 */
/*   Updated: 2021/06/18 12:55:14 by Xiaojing      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_general(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (isnumber(str[i]) == 1)
			i++;
		else
			break ;
	}
	if (str[i] || i > 11)
		return (-1);
	else
		return (1);
}

t_nb	*check_range(t_nb *temp, char *str)
{
	long long	nb;

	nb = ft_atoi(str);
	if (nb > 2147483647 || nb < -2147483648)
		temp = NULL;
	else
		temp = create_note(nb);
	return (temp);
}

void	parse_list(int ac, char **av, t_nb **head)
{
	t_nb		*temp;

	*head = NULL;
	while (ac > 1)
	{
		if (check_general(av[ac - 1]) == -1)
		{
			free_list(head);
			return ;
		}
		else
		{
			temp = check_range(temp, av[ac - 1]);
			if (!temp)
			{
				free_list(head);
				return ;
			}
			temp->next = *head;
			*head = temp;
		}
		ac--;
	}
}

int	main(int ac, char **av)
{
	t_nb	*list;

	if (ac == 1)
		return (0);
	if (ac == 2)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	else
		parse_list(ac, av, &list);
	if (!list)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	if (sort(ac - 1, &list) == 1)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	return (0);
}
