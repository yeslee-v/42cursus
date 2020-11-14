/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 15:03:51 by yeslee            #+#    #+#             */
/*   Updated: 2020/11/14 21:18:32 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_printf(const char *str, ...);

int main()
{
	//printf("%d\n", printf("%d\n", 123));
	//printf("%d\n", ft_printf("qwe%d\n", 123));

	printf("%.5d\n", 234);
	ft_printf("%.5d\n", 234);
//	printf("%-08d\n", 123);	// flag '0' is ignored
	return (0);
}
