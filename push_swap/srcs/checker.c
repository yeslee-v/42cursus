/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 15:17:20 by yeslee            #+#    #+#             */
/*   Updated: 2021/05/10 22:19:29 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_is_sorted(t_lst *lst)
{
	int		i;
	t_node	*first;
	t_node	*second;

	i = lst->cnt;
	if (i == 1)
		return (1);
	first = lst->head;
	second = first->next;
	while (--i)
	{
		if (second->data < first->data)
			return (0);
		second = second->next;
		first = first->next;
	}
	return (1);
}

void	ft_r_first(t_stack *stack, char *line)
{
	if ((line[1] == 'a') && (line[2] == '\0'))
		ft_ra(stack);
	else if ((line[1] == 'b') && (line[2] == '\0'))
		ft_rb(stack);
	else if ((line[1] == 'r') && (line[2] == '\0'))
		ft_rr(stack);
	else if ((line[1] == 'r') && (line[2] == 'a') && (line[3] == '\0'))
		ft_rra(stack);
	else if ((line[1] == 'r') && (line[2] == 'b') && (line[3] == '\0'))
		ft_rrb(stack);
	else if ((line[1] == 'r') && (line[2] == 'r') && (line[3] == '\0'))
		ft_rrr(stack);
	else
		ft_error_message();
}

void	ft_read(t_stack *stack)
{
	int		size;
	char	*line;
	
	stack->is_push_swap = 0;
	while ((size = get_next_line(0, &line) > 0))
	{

		if ((line[0] == 's') && (line[1] == 'a') && (line[2] == '\0'))
			ft_sa(stack);
		else if ((line[0] == 's') && (line[1] == 'b') && (line[2] == '\0'))
			ft_sb(stack);
		else if ((line[0] == 's') && (line[1] == 's') && (line[2] == '\0'))
			ft_ss(stack);
		else if ((line[0] == 'p') && (line[1] == 'a') && (line[2] == '\0'))
			ft_pa(stack);
		else if ((line[0] == 'p') && (line[1] == 'b') && (line[2] == '\0'))
			ft_pb(stack);
		else if (line[0] == 'r')
			ft_r_first(stack, line);
		else
			ft_error_message();
		free(line);
	// printf("stack a+++++++++\n");
	// ft_print_node(stack->a);
	// printf("stack b+++++++++\n");
	// ft_print_node(stack->b);
	}
	if (ft_is_sorted(stack->a) && !(stack->b->cnt))
		ft_ok();
	else
		ft_ko();
}
