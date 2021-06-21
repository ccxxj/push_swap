/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rules2.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: Xiaojing <Xiaojing@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/11 14:32:21 by Xiaojing      #+#    #+#                 */
/*   Updated: 2021/06/11 14:34:13 by Xiaojing      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	double_swap(t_nb **a, t_nb **b)
{
	swap(a);
	swap(b);
}

void	double_rotate(t_nb **a, t_nb **b)
{
	rotate(a);
	rotate(b);
}

void	double_rv_rotate(t_nb **a, t_nb **b)
{
	rv_rotate(a);
	rv_rotate(b);
}
