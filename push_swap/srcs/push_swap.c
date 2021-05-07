/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 12:21:43 by yeslee            #+#    #+#             */
/*   Updated: 2021/05/07 20:31:55 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_set_rrr(t_stack *stack, int ra_num, int rb_num)
{
	if (ra_num == rb_num)
	{
		while (ra_num)
		{
			ft_rrr(stack->a, stack->b);
			write(1, "rrr\n", 4);
			ra_num--;
		}
	}
	else
	{
		if (ra_num < rb_num)
		{
			while (ra_num)
			{
				ft_rrr(stack->a, stack->b);
				write(1, "rrr\n", 4);
				ra_num--;
			}
			ft_rrb(stack->b);
			write(1, "rrb\n", 4);
		}
		else
		{
			while (rb_num)
			{
				ft_rrr(stack->a, stack->b);
				write(1, "rrr\n", 4);
				rb_num--;
			}
			ft_rra(stack->a);
			write(1, "rra\n", 4);
		}
	}
}

void	ft_b_to_a(t_stack *stack, int min, int max)	// idx
{
//	printf("[ Printing b_to_a ]\n");	
	int	i;
	int	piv1;
	int	piv2;
	int	ra_num;
	int	rb_num;
	
	ra_num = 0;
	rb_num = 0;
	i = max - min; // whole node count
	int cnt = i + 1;
	piv1 = (max - min) / 3 + min;
	piv2 = (2 * (max - min)) / 3 + min;
//	printf("piv1:piv2 = %d:%d\n", piv1, piv2);
//	printf("[b_to_a >> piv]%d:%d\n", stack->arr[piv1], stack->arr[piv2]);
//	printf("min:max:i = %d:%d:%d\n", min, max, i); // i == pb_num
//	ft_print_node(stack->a);
//	ft_print_node(stack->b);
//	printf(">>>>>>>>cnt:%d\n", stack->b->cnt);
	if (!(stack->b->cnt) || i < 1)
		return ;
	else if (stack->b->cnt == 1)
	{
//		printf("b_cnt is 1\n");
		ft_pa(stack->b, stack->a);
		return ;
	}
	else if (stack->b->cnt == 2)
	{
	//	printf("b_cnt is 2\n");
		if (stack->b->head->data < stack->b->head->next->data)
			ft_sb(stack->b);
		ft_pa(stack->b, stack->a);
		ft_pa(stack->b, stack->a);
		return ;
	}
	else if (stack->b->cnt == 3)
	{
	//	printf("+++++++++++++++++++b_cnt is 3\n");
		return (ft_sort_three(stack->b));
	}
/*	else if (stack->b->cnt < 4)
	{
		// 정렬하면서 하나씩 보내줘라 >> 경우의 수 만큼 다 봐주
		while (stack->b->cnt)
			ft_pa(stack->b, stack->a);
		return ;
	}*/
	else
	{
//	ft_print_node(stack->a);
//	ft_print_node(stack->b);
		while (--cnt)
		{
			if (stack->b->head->data < stack->arr[piv1]) // min
			{
//				printf("min:%d\n", stack->b->head->data);
				rb_num += ft_rb(stack->b);
				write(1, "rb\n", 3);
			}
			else if ((stack->arr[piv1] <= stack->b->head->data) && (stack->b->head->data < stack->arr[piv2])) // mid
			{
//				printf("mid:%d\n", stack->b->head->data);
			//	ft_print_node(stack->b);
				ft_pa(stack->b, stack->a);
				write(1, "pa\n", 3);
				ra_num += ft_ra(stack->a);
				write(1, "ra\n", 3);
			//	ft_print_node(stack->b);
			}
			else // max
			{
//				printf("max:%d\n", stack->b->head->data);
				ft_pa(stack->b, stack->a);
				write(1, "pa\n", 3);
			}
		}
	}
//	printf("min:%d piv1:%d piv2:%d max:%d\n", min, piv1, piv2, max);
	ft_a_to_b(stack, piv2, max); // 큰 값에서 사용함
	ft_set_rrr(stack, ra_num, rb_num);
//	ft_print_node(stack->a);
//	ft_print_node(stack->b);
	ft_a_to_b(stack, piv1, piv2);
	ft_b_to_a(stack, min, piv1);
//	ft_print_node(stack->a);
//	ft_print_node(stack->b);
}

void	ft_a_to_b(t_stack *stack, int min, int max)	// idx
{
//	printf("[ Printing a_to_b ]\n");	
	int	i;
	int	piv1;
	int	piv2;
	int	ra_num;
	int	rb_num;

	ra_num = 0;
	rb_num = 0;
	i = max - min; // whole node count == r, 범위의 크
	int cnt = i + 1;
//	printf("min:max:i = %d:%d:%d\n", min, max, i); // i == pb_num
	if (i == 3)
	{
	//	printf("i is 3\n");
		return (ft_sort_three(stack->a));
	}
	else if	(i == 2)
	{
	//	printf("i is 2\n");
		return (ft_sort_two(stack->a));
	}
	else if (i < 2)
		return ;
	piv1 = (max - min) / 3 + min;
	piv2 = (2 * (max - min)) / 3 + min;
//	printf("[a_to_b >> piv]%d:%d\n", stack->arr[piv1], stack->arr[piv2]);
	while (--cnt)
	{
	//	printf("cnt:%d\n", stack->a->cnt);
	//	ft_print_node(stack->a);
		//printf("i:%d\n", i);
		if (stack->a->head->data < stack->arr[piv1]) // min
		{
//			printf("a_to_b_min:%d\n", stack->a->head->data);
			ft_pb(stack->a, stack->b);
			write(1, "pb\n", 3);
//			printf("rb:%d\n", rb_num);
		}
		else if ((stack->arr[piv1] <= stack->a->head->data) && (stack->a->head->data < stack->arr[piv2])) // mid
		{
//			printf("a_to_b_mid:%d\n", stack->a->head->data);
		//	ft_print_node(stack->b);
			ft_pb(stack->a, stack->b);
			write(1, "pb\n", 3);
			rb_num += ft_rb(stack->b);
			write(1, "rb\n", 3);
		//	ft_print_node(stack->b);
		}
		else // max
		{
	//		printf("a_to_b_max:%d\n", stack->a->head->data);
			ra_num += ft_ra(stack->a);
			write(1, "ra\n", 3);
		}
	}
//	ft_print_node(stack->a);
//	ft_print_node(stack->b);
//	printf("ra:rb:pb = %d:%d:%d\n", ra_num, rb_num, i - ra_num); // i == pb_num
	ft_set_rrr(stack, ra_num, rb_num);
//	printf("r1:%d|r2:%d|p1:%d\n", stack->a->r1_num, stack->b->r2_num, stack->b->p1_num);
	ft_a_to_b(stack, piv2, max); //max
//	printf("b_to_a >>>>>>>>> min:%d max:%d\n", piv1, piv2);
	ft_b_to_a(stack, piv1, piv2); //mid
	ft_b_to_a(stack, min, piv1); //min
}
