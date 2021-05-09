/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 18:21:06 by yeslee            #+#    #+#             */
/*   Updated: 2021/05/09 15:49:37 by yeslee           ###   ########.fr       */
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
	int			cnt; // number of nodes
}				t_lst;

typedef	struct	s_stack
{
	t_lst		*a;
	t_lst		*b;
	int			*arr;
	int			is_push_swap;
}				t_stack;

t_node	*ft_get_node(t_node *new);
t_lst	*ft_init_list(t_lst *lst);

int		main(int ac, char **av);
void	ft_print_node(t_lst *stack);
int		ft_lstcnt(t_lst *lst);

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

int		ft_ra(t_stack *stack);
int		ft_rb(t_stack *stack);
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

int		*ft_set_idx(t_lst *lst);
void	ft_quick_sort_init(t_stack *stack, int min, int max);
void	ft_bubble_sort(int *arr, int max);
int		*ft_intdup(t_lst *stack);

void	ft_a_to_b(t_stack *stack, int min, int max);
void	ft_b_to_a(t_stack *stack, int min, int max);
int		ft_count_element(t_lst *stack);

void	ft_sort_two(t_stack *stack);
void	ft_sort_three(t_stack *stack);
void	ft_reverse_sort_three(t_stack *stack);
void	ft_sort_five(t_stack *stack);

#endif
