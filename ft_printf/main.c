/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 15:03:51 by yeslee            #+#    #+#             */
/*   Updated: 2020/12/03 17:35:50 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <stdlib.h>
int	ft_printf(const char *str, ...);
void	ft_flag(t_list lst);

int main()
{
/*	printf("01. -%d\n", 123);
	ft_printf("01. -%d\n\n", 123);
	
	printf("02. %-d\n", 123);
	ft_printf("02. %-d\n\n", 123);*/

//	printf("[1]%-4dhello\n", 123);
//	printf("[2]%04dhello\n", 123);
	
	ft_printf("[3]%-4dhello\n", 123);
	ft_printf("[4]%04dhello\n", 123);

	return (0);
}
