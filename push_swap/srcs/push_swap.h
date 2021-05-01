/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 18:21:06 by yeslee            #+#    #+#             */
/*   Updated: 2021/04/30 19:11:39 by yeslee           ###   ########.fr       */
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
	int			res;
}				t_lst;

t_node	*ft_get_node(t_node *new);
t_lst	*ft_init_list(t_lst *lst);

int		main(int ac, char **av);
void	ft_print_node(t_lst *stack);

void	ft_ok();
void	ft_ko();
void	ft_error_message();

int		ft_check_atoi(char *s);
int		ft_double_strlen(char **s);
int		ft_check_same(char **av);
void	ft_node_init(t_lst *lst, int value);

void	ft_check_error(int ac);

void	ft_s(t_lst *lst);
void	ft_r(t_lst *lst);
void	ft_rr(t_lst *lst);
void	ft_del(t_lst *t);
int		ft_p(t_lst *a, t_lst *b);

void	ft_set_pivot(t_lst *a, t_lst *b); 

void	ft_sort_two(t_lst *stack);
void	ft_sort_three(t_lst *stack);

#endif
