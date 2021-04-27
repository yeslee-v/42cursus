/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_series.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 15:02:18 by yeslee            #+#    #+#             */
/*   Updated: 2021/04/27 18:33:33 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_lst *lst)
{
	t_node	*tail_tmp;

	tail_tmp = ft_get_node();
/*	printf("before\n");
	while (lst->head)
	{
		printf("%d\n", lst->head->data);
		lst->head = lst->head->next;
	}*/
	tmp = lst->tail->data;
	while (lst->)
	{
		
	}
	lst->tail->data = lst->tail->prev->data;
	lst->head->data = tmp;
	printf("after\n");
	while (lst->head)
	{
		printf("%d\n", lst->head->data);
		lst->head = lst->head->next;
	}
}

/*void	ft_rb(t_list_b *lst_b, int n)
{

}*/
