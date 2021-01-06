/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 15:03:51 by yeslee            #+#    #+#             */
/*   Updated: 2021/01/06 17:40:38 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int main()
{
    printf("Result of applying conversion to 123\n");
    
	printf(  "%8d|\n", 123);
    ft_printf(  "%8d|\n\n", 123);
	
	printf( "%-8d|\n", 123);
	ft_printf( "%-8d|\n\n", 123);

//	printf( "%+8d\n", 123);
//	ft_printf( "%+8d\n\n", 123);

//  printf( "% 8d\n", 123);
//  ft_printf( "% 8d\n\n", 123);
    
	printf( "%08d|\n", 123);
	ft_printf( "%08d|\n\n", 123);

//	printf(  "%-08d\n, 123");	// 0 flag ignored == %-8d
	ft_printf(  "%-08d|\n\n", 123);
//	printf("%-+8d\n", 123);
//  printf("%- 8d\n", 123);
//  printf("%+08d\n", 123);
//  printf("% 08d\n", 123);

	printf("%*.*d|\n\n", 5, 6,  456);
	printf("%*d|\n\n", 5, -456);
	ft_printf("%*.*d|\n\n", 5, 6, 456);

/*    printf("Result of applying conversion to -123\n");

	printf(  "%8d|\n", -123);
	ft_printf(  "%8d|\n\n", -123);

	printf( "%-8d|\n", -123);
	ft_printf( "%-8d|\n\n", -123);
*/
//	printf( "%+8d\n", -123);
//  printf( "% 8d\n", -123);
    
/*	printf( "%08d|\n", -123);
    ft_printf( "%08d|\n\n", -123);
*/    
//	printf("%-+8d\n", -123);
//  printf("%- 8d\n", -123);
//  printf("%+08d\n", -123);
//  printf("% 08d\n", -123);
	
//	printf("%-08d|\n", -123);
//	ft_printf("%-08d|\n\n", -123);

	return (0);
}
