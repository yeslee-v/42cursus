/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 18:21:06 by yeslee            #+#    #+#             */
/*   Updated: 2021/04/27 17:27:52 by yeslee           ###   ########.fr       */
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
	int			num;
}				t_lst;

t_node	*ft_get_node(void);
t_lst	*ft_init_list(void);

int		main(int ac, char **av);

void	ft_ok();
void	ft_ko();
void	ft_error_message();

int		ft_check_atoi(char *s);
int		ft_double_strlen(char **s);
int		ft_check_same(char **av);

void	ft_sa(t_lst *lst);
void	ft_sb(t_lst *lst);

void	ft_ra(t_lst *lst);
/*void	ft_rb(t_lst *lst);

void	ft_rra(t_list_a *lst_a);
void	ft_rrb(t_list_b *lst_b);

void	ft_pa(t_list_a *lst_a);
void	ft_pb(t_list_b *lst_b);*/

#endif
