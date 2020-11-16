/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 14:42:58 by yeslee            #+#    #+#             */
/*   Updated: 2020/11/16 18:02:15 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// %d%f 맨 처음 초기화 + 다음 % 가 나왔을 때 몇몇 인자들 초기화

typedef	struct	s_list {
	s_list.right = 0;
//	s_list.plus = 0;
	s_list.left = 0;

	s_list.flag = 0;
	s_list.width = 0;
	s_list.precision = 0;
	
	s_list->print = 0;
	
	s_list.result = 0;
	s_list.cnt = 1;
	s_list.len = 0;
}				t_list;
