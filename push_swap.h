/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: Xiaojing <Xiaojing@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/10 15:39:28 by Xiaojing      #+#    #+#                 */
/*   Updated: 2021/06/17 12:59:44 by Xiaojing      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_nb{
	int			nb;
	int			position;
	struct s_nb	*next;
}				t_nb;

/* list */
t_nb			*ft_lstlast(t_nb *lst);
void			free_list(t_nb **lst);
t_nb			*create_note(int t);

/* utils */
long long		ft_atoi(const char *str);
int				isnumber(char c);
void			locate(int a, int b, int *array, t_nb *list);
int				check_ascend(t_nb *list);
int				check_duplicate_list(int n, t_nb *list);

/* rules */
void			swap(t_nb **nb);
void			push(t_nb **a, t_nb **b);
void			rotate(t_nb **a);
void			rv_rotate(t_nb **a);

/*heap sort*/
int				*heap_sort(int *array, int n);

/* sort*/
int				sort(int n, t_nb **list);
void			convert_array(int *array, t_nb *list, int n);

/*
radix sort
*/
void			radix_sort(t_nb *list_a, t_nb *list_b, int n);

/* sort small*/
int				sort_3(t_nb **list);
int				sort_small(int n, t_nb *list_a, t_nb *list_b);

/*sort small2*/
int				sort_3plus(int n, t_nb **list_a, t_nb **list_b);

#endif
