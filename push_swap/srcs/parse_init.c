/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 14:09:02 by yeslee            #+#    #+#             */
/*   Updated: 2021/05/06 19:02:06 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*int		ft_count_element(t_lst *stack)	// min,mid,max로 몇 개 보냈는
{
	int		cnt;
	t_node	*node;

	cnt = 0;
	node = stack->head;
	while (node)
	{
		cnt++;
		node = node->next;
		if (node == stack->head)
			break ;
	}
	return (cnt);
}*/

void	ft_b_to_a(t_stack *stack, int min, int max)	// idx
{
	int	i;
//	int	piv1;
//	int	piv2;

	i = max - min + 1; // whole node count
	printf("min:max:i = %d:%d:%d\n", min, max, i); // i == pb_num
	if (stack->b->cnt < 4)
	{
		while (stack->b->cnt)
			stack->a->p1_num += ft_pa(stack->b, stack->a);
		return ;
	}
/*	else if (i < 4)
	{

	}
	else
	{
		piv1 = (max - min) / 3 + min;
		piv2 = (2 * (max - min)) / 3 + min;
		printf("piv1:piv2 = %d:%d\n", piv1, piv2);
		printf("[b_to_a]%d:%d\n", stack->arr[piv1], stack->arr[piv2]);*/
	/*	while (stack->b && (--i > 0))
		{
			if (stack->b->head->data < stack->arr[piv1])
			{
			//	printf("min:%d\n", stack->a->head->data);
				stack->b->r2_num += ft_rb(stack->b);
			}
			else if ((stack->arr[piv1] <= stack->b->head->data) && (stack->b->head->data < stack->arr[piv2]))
			{
			//	printf("mid:%d\n", stack->a->head->data);
			//	ft_print_node(stack->b);
				stack->b->p1_num += ft_pa(stack->a, stack->b);
				stack->b->r2_num += ft_ra(stack->a);
			//	ft_print_node(stack->b);
			}
			 else
			 {
			//	printf("max:%d\n", stack->a->head->data);
				stack->b->p1_num += ft_pa(stack->a, stack->b);
			 }
		}
	}
	printf("r1:%d|r2:%d|p1:%d\n", stack->a->r1_num, stack->b->r2_num, stack->b->p1_num);*/
//	ft_print_node(stack->a);
//	ft_print_node(stack->b);
	
}

void	ft_a_to_b(t_stack *stack, int min, int max)	// idx
{
	int	i;
	int	piv1;
	int	piv2;
	int	ra_num;
	int	rb_num;

	i = max - min + 1; // whole node count
	if (i == 3)
		return (ft_sort_three(stack->a));
	else if	(i == 2)
		return (ft_sort_two(stack->a));
	piv1 = (max - min) / 3 + min;
	piv2 = (2 * (max - min)) / 3 + min;
//	printf("[a_to_b]%d:%d\n", stack->arr[piv1], stack->arr[piv2]);
	while (stack->a && (--i > 0))
	{
	//	printf("cnt:%d\n", stack->a->cnt);
	//	ft_print_node(stack->a);
		//printf("i:%d\n", i);
		if (stack->a->head->data < stack->arr[piv1])
		{
		//	printf("min:%d\n", stack->a->head->data);
			p1_num += ft_pb(stack->a, stack->b);
			r2_num += ft_rb(stack->b);
		}
		else if ((stack->arr[piv1] <= stack->a->head->data) && (stack->a->head->data < stack->arr[piv2]))
		{
		//	printf("mid:%d\n", stack->a->head->data);
		//	ft_print_node(stack->b);
			p1_num += ft_pb(stack->a, stack->b);
		//	ft_print_node(stack->b);
		}
		 else
		 {
		//	printf("max:%d\n", stack->a->head->data);
			r1_num += ft_ra(stack->a);
		 }
	}
//	printf("r1:%d|r2:%d|p1:%d\n", stack->a->r1_num, stack->b->r2_num, stack->b->p1_num);
	ft_a_to_b(stack, piv2, max); //max
	ft_b_to_a(stack, piv1, piv2); //mid
//	ft_b_to_a(stack, min, piv1); //min
	ft_print_node(stack->a);
	ft_print_node(stack->b);
}
