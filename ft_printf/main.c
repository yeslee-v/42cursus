/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 15:03:51 by yeslee            #+#    #+#             */
/*   Updated: 2020/11/14 14:47:22 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_printf(const char *str, ...);

int main()
{
	printf("%d\n", printf("%d\n", 123));
	printf("%d\n", ft_printf("qwe%d\n", 123));
	printf("% 08.2dab", 234);
	
/*	printf("%8d\n", 123);
//	ft_printf("%8d\n", 123);

	printf("%-8d|\n", 123);
//	ft_printf("%-8d\n", 123);
	
	printf("%+8d\n", 123);
//	ft_printf("%+8d\n", 123);
	
	printf("% 8d\n", 123);
//	ft_printf("% 8d\n", 123);
	
	printf("%08d\n", 123);
//	ft_printf("%08d\n", 123);

	printf("%-+8d\n", 123);
//	ft_printf("%-+8d\n", 123);
	
	printf("%- 8d\n", 123);
//	ft_printf("%- 8d\n", 123);

//	printf("%-08d\n", 123);	// flag '0' is ignored
	
	printf("%+08d\n", 123);
//	ft_printf("%+08d\n", 123);
	
	printf("% 08d\n", 123);
//	ft_printf("% 08d\n", 123);

	printf("%.5d\n", 123);
*/	
	return (0);
}
