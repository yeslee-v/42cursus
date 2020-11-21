/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 14:42:58 by yeslee            #+#    #+#             */
/*   Updated: 2020/11/21 16:08:42 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

// %d%f 맨 처음 초기화 + 다음 % 가 나왔을 때 몇몇 인자들 초기화

void	ft_reset(t_list *lst)
{
	if (!lst)
		return ;
	else
	{
		//lst.space = 0;
		//lst.plus = 0;
		lst->left = '0';
		lst->zero = '0';
		//lst.sharp = 0;

		lst->width = 0;
		lst->prec = 0;

		lst->type = '0';

		lst->len = 0;

		lst->result = 0;
		lst->cnt = 0;
	}
	return ;
}
