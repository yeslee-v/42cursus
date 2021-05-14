/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 18:21:06 by yeslee            #+#    #+#             */
/*   Updated: 2021/05/14 15:52:26 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "../include/libft/libft.h"
#include "../headers/get_next_line.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

typedef struct	s_node
{
	int	data;
	struct s_node *next;
	struct s_node *prev;
}				t_node;

typedef struct	s_lst
{
	t_node		*head;
	t_node		*tail;
	int			cnt;
}				t_lst;

typedef struct	s_val
{
	int		piv1;
	int		piv2;
}				t_val;

typedef	struct	s_stack
{
	t_lst		*a;
	t_lst		*b;
	t_val		val;
	int			is_push_swap;
}				t_stack;

void	ft_init_val(t_val *val);
t_node	*ft_get_node(t_node *new);
t_lst	*ft_init_list(t_lst *lst);

int		ft_lstcnt(t_lst *lst);
int		main(int ac, char **av);

void	ft_ok();
void	ft_ko();
void	ft_error_message();

int		ft_check_atoi(char *s);
int		ft_double_strlen(char **s);
int		ft_check_same(char **av);
void	ft_node_init(t_lst *lst, int value);

void	ft_sa(t_stack *stack);
void	ft_sb(t_stack *stack);
void	ft_ss(t_stack *stack);

void	ft_ra(t_stack *stack);
void	ft_rb(t_stack *stack);
void	ft_rr(t_stack *stack);

void	ft_rra(t_stack *stack);
void	ft_rrb(t_stack *stack);
void	ft_rrr(t_stack *stack);

void	ft_del(t_lst *lst);
void	ft_add_p(t_lst *lst, int value);
void	ft_pa(t_stack *stack);
void	ft_pb(t_stack *stack);

void	ft_read(t_stack *stack);
void	ft_r_first(t_stack *stack, char *line);
int		ft_is_sorted(t_lst *lst);

int		*ft_set_idx(t_lst *lst);
void	ft_quick_sort_init(t_stack *stack);
void	ft_bubble_sort(int *arr, int max);
int		*ft_intdup(t_lst *stack);

int		ft_set_max(t_lst *lst);
int		ft_set_min(t_lst *lst);

void	ft_a_to_b(t_stack *stack, int size);
void	ft_b_to_a(t_stack *stack, int max);
int		ft_count_element(t_lst *stack);

void	ft_sort_two(t_stack *stack);
void	ft_sort_three(t_stack *stack);
void	ft_sort_four(t_stack *stack);
void	ft_sort_five(t_stack *stack);

int		ft_find_num(t_stack *stack, int num);

#endif
