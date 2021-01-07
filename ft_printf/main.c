/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 15:03:51 by yeslee            #+#    #+#             */
/*   Updated: 2021/01/07 22:47:57 by yeslee           ###   ########.fr       */
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

//	printf("%*d|\n", 5, -456);
//	printf("%.-1d\n", 456);

//	printf("%3d|\n", 123);
//	ft_printf("%3d|\n\n", 123);
	
	printf("%.0d|\n", 456);
	ft_printf("%.0d|\n\n", 456);
	
	printf("%.d|\n", 456);
	ft_printf("%.d|\n\n", 456);
	
/*	printf("%.3d|\n", 456);
	printf("%.5d|\n\n", 456);
	
	printf("%.*d|\n", -1, 456);
	printf("%.*d|\n", 0, 456);
	printf("%.*d|\n", 1, 456);
	printf("%.*d|\n", 3, 456);
	printf("%.*d|\n", 5, 456);
	printf("%*.*d|\n", 8, 6, 456);
	printf("%*.*d|\n", 8, 6, 456);
	ft_printf("%*.*d|\n\n", 8, 6, 456);
*/
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
/*	ft_printf("%-08d|\n\n", -123);
*/
	return (0);
}
