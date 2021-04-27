/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 18:20:54 by yeslee            #+#    #+#             */
/*   Updated: 2021/04/28 01:10:58 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char **av)
{
	int		i;
	t_lst	*lst;
	t_node	*new;

	if (ac == 1)
		ft_error_message();
	else if (ac == 2)
	{
		if (EOF)
			ft_ok();
	}
	i = 0;
	lst = ft_init_list();
	
	lst->head = ft_get_node();
	lst->tail = ft_get_node();
	
	lst->head->next = lst->tail;
	lst->head->prev = lst->tail;
	lst->tail->next = lst->head;
	lst->tail->prev = lst->head;
	while (av[++i])
	{
		new = ft_get_node();
		new->data = ft_check_same(&av[i]);
		
		if ((!(lst->head->data) && (!(lst->tail->data))))
		{
			lst->head = new;
			lst->tail = new;
		}
		else
		{
			lst->tail->next = new;
			new->prev = lst->tail;
			lst->tail = new;
		}
		//free(lst->head);
		lst->num++;
	}
	ft_sa(lst);
	ft_sb(lst);
	ft_ra(lst);
	ft_rb(lst);
	ft_rra(lst);
	// ft_rrb(lst);
	// ft_pa(lst);
	// ft_pb(lst);
	return (0);
}
