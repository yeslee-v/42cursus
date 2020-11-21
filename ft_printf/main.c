/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 15:03:51 by yeslee            #+#    #+#             */
/*   Updated: 2020/11/21 12:29:33 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <stdlib.h>
int	ft_printf(const char *str, ...);
void	ft_flag(t_list lst);

int main()
{
	printf("%d\n", printf("%d\n", 123));
	printf("%d\n", ft_printf("%d\n", 123));
	
	//printf("%04d\n", 123);
	//ft_printf("%03d\n", 123);

/* memory leak check
	ft_printf("%d %c %s %i %u %x %X %p\n", 1, 10, 'c', "hello", 1, 1, 1, 1, NULL);
	while (1)
		;
*/
	return (0);
}
