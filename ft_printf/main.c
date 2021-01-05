/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 15:03:51 by yeslee            #+#    #+#             */
/*   Updated: 2021/01/05 21:52:19 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Result of applying conversion to 123\n");
    
	printf(  "%8d\n", 123);
    ft_printf(  "%8d\n\n", 123);
	
	printf( "%-8d\n", 123);
	ft_printf( "%-8d\n\n", 123);

//	printf( "%+8d\n", 123);
//	ft_printf( "%+8d\n\n", 123);

//    printf( "% 8d\n", 123);
//    ft_printf( "% 8d\n\n", 123);
    
    printf( "%08d\n", 123);
    ft_printf( "%08d\n\n", 123);
    
//	printf("%-+8d\n", 123);
//    printf("%- 8d\n", 123);
//    printf("%+08d\n", 123);
//    printf("% 08d\n", 123);

    printf("Result of applying conversion to -123\n");

	printf(  "%8d\n", -123);
	ft_printf(  "ft:%8d\n", -123);

/*	printf( "%-8d\n", -123);
    printf( "%+8d\n", -123);
    printf( "% 8d\n", -123);
    printf( "%08d\n", -123);
    printf("%-+8d\n", -123);
    printf("%- 8d\n", -123);
    printf("%+08d\n", -123);
    printf("% 08d\n", -123);
*/
	return (0);
}
