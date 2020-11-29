/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 15:03:51 by yeslee            #+#    #+#             */
/*   Updated: 2020/11/29 21:36:35 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <stdlib.h>
int	ft_printf(const char *str, ...);
void	ft_flag(t_list lst);

int main()
{
//	printf("%d\n", printf("%d\n", 123));
//	printf("%d\n", ft_printf("%d\n", 123));
	
	//printf("%04d\n", 123);
	ft_printf("hello\n%---123.123d\nworld\n%2.12f\n", 123, 10);

	return (0);
}
