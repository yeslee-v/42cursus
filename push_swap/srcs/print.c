/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 22:08:42 by yeslee            #+#    #+#             */
/*   Updated: 2021/04/28 22:09:04 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_node(t_lst *t)
{
	t_node *tmp;

	tmp = t->tail;
	while (tmp)
	{
		printf("%d\n", tmp->data);
		tmp = tmp->prev;
		if (tmp == t->tail)
			break ;
	}
}
