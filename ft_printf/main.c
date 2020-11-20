/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 15:03:51 by yeslee            #+#    #+#             */
/*   Updated: 2020/11/20 17:33:11 by yeslee           ###   ########.fr       */
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
	
//	printf("printf: %0*d\n", 8, 123); // 우리 수준에선 놉
//	printf("hello%d", printf("%d\n", 567));
//	ft_printf("%-11.12d", 123);
	//printf("%011.12d", 123);
	printf("%--5.8d\n", 123);

	//printf("%-08d\n", 123);	// flag '0' is ignored

/* memory leak check
	ft_printf("%d %c %s %i %u %x %X %p\n", 1, 10, 'c', "hello", 1, 1, 1, 1, NULL);
	while (1)
		;
*/
	return (0);
}
