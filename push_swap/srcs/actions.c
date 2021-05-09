/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 13:47:53 by yeslee            #+#    #+#             */
/*   Updated: 2021/05/09 13:33:21 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_stack *stack)
{
	int	tmp;

	if (!stack)
		return ;
	if (stack->a->cnt > 1)
	{
		tmp = stack->a->head->data;
		stack->a->head->data = stack->a->head->next->data;
		stack->a->head->next->data = tmp;
		if (stack->is_push_swap)
			write(1, "sa\n", 3);
	}
}

void	ft_sb(t_stack *stack)
{
	int	tmp;

	if (!stack)
		return ;
	if (stack->b->cnt > 1)
	{
		tmp = stack->b->head->data;
		stack->b->head->data = stack->b->head->next->data;
		stack->b->head->next->data = tmp;
		if (stack->is_push_swap)
			write(1, "sb\n", 3);
	}
}

void	ft_ss(t_stack *stack)
{
	if (!stack)
		return ;
	if (stack->is_push_swap)
	{
		write(1, "ss\n", 3);
		stack->is_push_swap = 0;
	}
	ft_sa(stack);
	ft_sb(stack);
}

int	ft_ra(t_stack *stack)
{
	if (!stack)
		return (0);
	if (stack->a->cnt > 1)
	{
		stack->a->head = stack->a->head->next;
		stack->a->tail = stack->a->tail->next;
		if (stack->is_push_swap)
			write(1, "ra\n", 3);
		return (1);
	}
	return (0);
}

int	ft_rb(t_stack *stack)
{
	if (!stack)
		return (0);
	if (stack->b->cnt > 1)
	{
		stack->b->head = stack->b->head->next;
		stack->b->tail = stack->b->tail->next;
		if (stack->is_push_swap)
			write(1, "rb\n", 3);
		return (1);
	}
	return (0);
}

void	ft_rr(t_stack *stack)
{
	if (!stack)
		return ;
	if (stack->is_push_swap)
	{
		write(1, "rr\n", 3);
		stack->is_push_swap = 0;
	}
	ft_ra(stack);
	ft_rb(stack);
}

void	ft_rra(t_stack *stack)
{
	t_node	*tmp;

	if (!stack)
		return ;
//	printf("out\n");
	if (stack->a->cnt > 1)
	{
//		printf("in\n");
		tmp = stack->a->head;
		stack->a->head = stack->a->tail;
		stack->a->tail = stack->a->tail->prev;
	//	stack->a->head->next = tmp;
		if (stack->is_push_swap)
			write(1, "rra\n", 4);
	}
}

void	ft_rrb(t_stack *stack)
{
	t_node	*tmp;

	if (!stack)
		return ;
	if (stack->b->cnt > 1)
	{
		tmp = stack->b->head;
		stack->b->head = stack->b->tail;
		stack->b->tail = stack->b->tail->prev;
	//	stack->b->head->next = tmp;
		if (stack->is_push_swap)
			write(1, "rrb\n", 4);
	}
}

void	ft_rrr(t_stack *stack)
{
	if (!stack)
		return ;
	if (stack->is_push_swap)
	{
		write(1, "rrr\n", 4);
		stack->is_push_swap = 0;
	}
	ft_rra(stack);
	ft_rrb(stack);
}

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
