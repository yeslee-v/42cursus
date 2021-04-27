/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_series.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 12:42:17 by yeslee            #+#    #+#             */
/*   Updated: 2021/04/28 00:23:34 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_lst *lst)
{
	int	tmp;

	tmp = lst->head->data;
	lst->head->data = lst->head->next->data;
	lst->head->next->data = tmp;
}

void	ft_sb(t_lst *lst)
{
	int	tmp;

	tmp = lst->head->data;
	lst->head->data = lst->head->next->data;
	lst->head->next->data = tmp;
}
