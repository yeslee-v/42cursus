/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 13:32:56 by yeslee            #+#    #+#             */
/*   Updated: 2021/05/14 13:33:11 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_del(t_lst *lst)
{
	t_node *tmp;

	if (!lst)
		return ;
	tmp = NULL;
	if (lst->cnt != 1)
	{
		tmp = lst->head;
		lst->head = tmp->next;
		lst->head->prev = tmp->prev;
		lst->tail->next = lst->head;
		free(tmp);
	}
	else if (lst->cnt == 1)
	{
		tmp = lst->head;
		free(tmp);
		lst->head = NULL;
		lst->tail = NULL;
	}
}

void	ft_pa(t_stack *stack)
{
	if (!stack)
		return ;
	if (stack->b->head != NULL)
	{
		ft_add_p(stack->a, stack->b->head->data);
		ft_del(stack->b);
		stack->a->cnt++;
		stack->b->cnt--;
		if (stack->is_push_swap)
			write(1, "pa\n", 3);
	}
	return ;
}

void	ft_pb(t_stack *stack)
{
	if (!stack)
		return ;
	if (stack->a->head != NULL)
	{
		ft_add_p(stack->b, stack->a->head->data);
		ft_del(stack->a);
		stack->a->cnt--;
		stack->b->cnt++;
		if (stack->is_push_swap)
			write(1, "pb\n", 3);
	}
	return ;
}
