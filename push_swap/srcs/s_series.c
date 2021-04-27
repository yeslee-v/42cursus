/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_series.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 12:42:17 by yeslee            #+#    #+#             */
/*   Updated: 2021/04/27 17:26:25 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_lst *lst)
{
	int	tmp;

	tmp = lst->tail->data;
	lst->tail->data = lst->tail->prev->data;
	lst->tail->prev->data = tmp;
}

void	ft_sb(t_lst *lst)
{
	int	tmp;

	tmp = lst->tail->data;
	lst->tail->data = lst->tail->prev->data;
	lst->tail->prev->data = tmp;
}
