/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_series.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 12:42:17 by yeslee            #+#    #+#             */
/*   Updated: 2021/04/26 17:40:15 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_node *node)
{
	int	tmp;

	if (!(node))
		return ;
	printf("ft:%d\n", node->data);
	tmp = node->data;
	node->data = node->next->data;
	node->next->data = tmp;
}

// void	ft_sb(t_node *node)
// {
// 	int	tmp;

// 	if (!(node))
// 		return ;
// 	tmp = node->data;
// 	node->data = node->next->data;
// 	node->next->data = tmp;
// }
