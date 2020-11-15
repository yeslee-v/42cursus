/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 15:03:51 by yeslee            #+#    #+#             */
/*   Updated: 2020/11/15 15:27:13 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_printf(const char *str, ...);

int main()
{
	printf("%d\n", printf("%d\n", 123));
	printf("%d\n", ft_printf("%d\n", 123));

//	printf("%d\n", printf("%.5d\n", 234));
//	printf("%d\n", ft_printf("%.5d\n", 234));

	//printf("%-08d\n", 123);	// flag '0' is ignored
	return (0);
}
