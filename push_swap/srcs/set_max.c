/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_max.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 17:23:36 by yeslee            #+#    #+#             */
/*   Updated: 2021/05/14 20:25:42 by parkjaekw        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_from_top(t_stack *stack, int max)
{
	int		top_cnt;
	t_node	*tmp;

	top_cnt = 0;
	tmp = stack->b->head;
	while (tmp)
	{
		if (tmp->data == max)
			return (top_cnt);
		top_cnt++;
		tmp = tmp->next;
		if (tmp == stack->b->head)
			break ;
	}
	return (top_cnt);
}

static int	ft_from_bottom(t_stack *stack, int max)
{
	int		bot_cnt;
	t_node	*tmp;

	bot_cnt = 0;
	tmp = stack->b->tail;
	while (tmp)
	{
		if (tmp->data == max)
			return (bot_cnt);
		bot_cnt++;
		tmp = tmp->prev;
		if (tmp == stack->b->tail)
			break ;
	}
	return (bot_cnt);
}

static void	ft_cnt_is_zero(t_stack *stack, int top_cnt, int bot_cnt)
{
	if (top_cnt == 0)
	{
		ft_pa(stack);
		return ;
	}
	if (bot_cnt == 0)
	{
		ft_rrb(stack);
		ft_pa(stack);
		return ;
	}
}

static void	ft_cnt_is_not_zero(t_stack *stack, int top_cnt, int bot_cnt)
{
	if (top_cnt <= bot_cnt)
	{
		while (top_cnt)
		{
			ft_rb(stack);
			top_cnt--;
		}
	}
	else if (bot_cnt < top_cnt)
	{
		while (bot_cnt)
		{
			ft_rrb(stack);
			bot_cnt--;
		}
		ft_rrb(stack);
	}
}

void		ft_find_max(t_stack *stack, int max)
{
	int		top_cnt;
	int		bot_cnt;

	top_cnt = ft_from_top(stack, max);
	bot_cnt = ft_from_bottom(stack, max);
	if ((top_cnt == 0) || (bot_cnt == 0))
	{
		ft_cnt_is_zero(stack, top_cnt, bot_cnt);
		return ;
	}
	else
		ft_cnt_is_not_zero(stack, top_cnt, bot_cnt);
	ft_pa(stack);
}
