/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 15:03:51 by yeslee            #+#    #+#             */
/*   Updated: 2020/11/19 17:33:48 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_printf(const char *str, ...);

int main()
{
//	printf("%d\n", printf("%d\n", 123));
//	printf("%d\n", ft_printf("%d\n", 123));
	
//	printf("printf: %0*d\n", 8, 123);
	ft_printf("hello%05.2d", 123);

	//printf("%-08d\n", 123);	// flag '0' is ignored

/* memory leak check
	ft_printf("%d %c %s %i %u %x %X %p\n", 1, 10, 'c', "hello", 1, 1, 1, 1, NULL);
	while (1)
		;
*/
	return (0);
}
