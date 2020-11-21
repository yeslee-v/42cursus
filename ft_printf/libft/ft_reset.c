/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 14:42:58 by yeslee            #+#    #+#             */
/*   Updated: 2020/11/21 12:29:24 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

// %d%f 맨 처음 초기화 + 다음 % 가 나왔을 때 몇몇 인자들 초기화

int	ft_reset(t_list lst)
{
	if (!lst)
		return (0);
	else
	{
		//t_list.space = 0;
		//t_list.plus = 0;
		t_list.left = '0';
		t_list.zero = '0';
		//t_list.sharp = 0;

		t_list.width = 0;
		t_list.prec = 0;

		t_list.type = '0';

		t_list.len = 0;

		t_list.result = 0;
		t_list.cnt = 0;
	}
	return (0);
}
