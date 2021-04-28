/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 18:20:54 by yeslee            #+#    #+#             */
/*   Updated: 2021/04/28 22:11:50 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_node_init(t_lst *lst, int value)
{
	t_node *new;

	new = NULL;
	new = ft_get_node(new);
	new->data = value;

	if (!(lst->head) && !(lst->tail))
	{
		new->next = new;
		new->prev = new;
		lst->head = new;
		lst->tail = new;
	}
	else
	{
		lst->tail->next = new;
		new->prev = lst->tail;
		lst->tail = new;
		lst->head->prev = lst->tail;
		lst->tail->next = lst->head;
	}
	lst->cnt++;
}

int main(int ac, char **av)
{
	int		i;
	t_lst	*lst_a;
	t_lst	*lst_b;

	lst_a = NULL;
	lst_b = NULL;
	lst_a = ft_init_list(lst_a);
	lst_b = ft_init_list(lst_b);
	ft_check_error(ac);
	
	i = 0;
	while (av[++i])
		ft_node_init(lst_a, ft_check_same(&av[i]));
	return (0);
}
