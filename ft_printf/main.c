/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 15:03:51 by yeslee            #+#    #+#             */
/*   Updated: 2021/01/09 11:52:13 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int main()
{
    printf("Result of applying conversion to 123\n");
    
	printf(  "1.%8d|\n", 123);
    ft_printf(  "1.%8d|\n\n", 123);
	
	printf( "2.%-8d|\n", 123);
	ft_printf( "2.%-8d|\n\n", 123);

//	printf( "3.%+8d\n", 123);
//	ft_printf( "3.%+8d\n\n", 123);

//  printf( "4.% 8d\n", 123);
//  ft_printf( "4.% 8d\n\n", 123);
    
	printf( "5.%08d|\n", 123);
	ft_printf( "5.%08d|\n\n", 123);

//	printf(  "6.%-08d\n, 123");	// 0 flag ignored == %-8d
	ft_printf(  "6.%-08d|\n\n", 123);

//	printf("7.%-+8d\n", 123);
//  printf("8.%- 8d\n", 123);
//  printf("9.%+08d\n", 123);
//  printf("10.% 08d\n", 123);

//	printf("11.%*d|\n", 5, -456); 지우기 귀찮아서 안지움_음수는 아래에
//	printf("12.%.-1d\n", 456); precision must be positive

	printf("13.%3d|\n", 123);
	ft_printf("13.%3d|\n\n", 123);
	
	printf("14.%.0d|\n", 456);
	ft_printf("14.%.0d|\n\n", 456);
	
	printf("15.%.d|\n", 456);
	ft_printf("15.%.d|\n\n", 456);
	
	printf("16.%.3d|\n", 456);
	ft_printf("16.%.3d|\n\n", 456);
	
	printf("17.%.5d|\n", 456);
	ft_printf("17.%.5d|\n\n", 456);
	
	printf("18.%.*d|\n", -1, 456);
	ft_printf("18.%.*d|\n\n", -1, 456);

	printf("19.%.*d|\n", 0, 456);
	ft_printf("19.%.*d|\n\n", 0, 456);
	
	printf("20.%.*d|\n", 1, 456);
	ft_printf("20.%.*d|\n\n", 1, 456);
	
	printf("21.%.*d|\n", 3, 456);
	ft_printf("21.%.*d|\n\n", 3, 456);
	
	printf("22.%.*d|\n", 5, 456);
	ft_printf("22.%.*d|\n\n", 5, 456);
	
	printf("23.%*.*d|\n", 8, 6, 456);
	ft_printf("23.%*.*d|\n\n", 8, 6, 456);
	
	printf("24.%*.*d|\n", 6, 8, 456);
	ft_printf("24.%*.*d|\n\n", 6, 8, 456);

	printf("25.%*.*d|\n", -1, 2, 456);
	ft_printf("25.%*.*d|\n\n", -1, 2, 456);
	
	printf("26.%*.*d|\n", 1, 6, 456);
	ft_printf("26.%*.*d|\n\n", 1, 6, 456);
	
	printf("27.%*.*d|\n", 6, 1, 456);
	ft_printf("27.%*.*d|\n\n", 6, 1, 456);

	printf("27-1.%-*.*d|\n", 6, 1, 456);
	ft_printf("27-2.%-*.*d|\n\n", 6, 1, 456);
	
	printf("27-2.% *.*d|\n", 6, 8, 456);
	ft_printf("27-2.% *.*d|\n\n", 6, 8, 456);
	
	printf("27-3.%-*.*d|\n", 6, 8, 456);
	ft_printf("27-3.%-*.*d|\n\n", 6, 8, 456);
	
	//printf("27-4.%-0*.*d|\n", 6, 1, 456);
	ft_printf("27-4.%-0*.*d|\n\n", 6, 1, 456);
	
	//printf("27-5.%-0*.*d|\n", 6, 8, 456);
	ft_printf("27-5.%-0*.*d|\n\n", 6, 8, 456);
	
	printf("27-6.% *.*d|\n", 1, 2, 456);
	ft_printf("27-6.% *.*d|\n\n", 1, 2, 456);
	
	printf("27-7.%-*.*d|\n", 2, 1, 456);
	ft_printf("27-7.%-*.*d|\n\n", 2, 1, 456);
	
	printf("Result of applying conversion to -123\n");

	printf(  "28.%8d|\n", -123);
	ft_printf(  "28.%8d|\n\n", -123);

	printf( "29.%-8d|\n", -123);
	ft_printf( "29.%-8d|\n\n", -123);

//	printf( "30.%+8d\n", -123);
//  printf( "%31. 8d\n", -123);
    
/*	printf( "32.%08d|\n", -123);
    ft_printf( "33.%08d|\n\n", -123);
 */   
//	printf("34.%-+8d\n", -123);
//  printf("35.%- 8d\n", -123);
//  printf("36.%+08d\n", -123);
//  printf("37.% 08d\n", -123);
	
//	printf("38.%-08d|\n", -123);
/*	ft_printf("39.%-08d|\n\n", -123);
*/
//	printf("40.%-+8d\n", 123);
//  printf("41.%- 8d\n", 123);
//  printf("42.%+08d\n", 123);
//  printf("43.% 08d\n", 123);

	printf("44.%*d|\n", 5, -456);
	ft_printf("44.%*d|\n\n", 5, -456);

//	printf("45.%.-1d\n", 456); precision must be positive

	printf("46.%3d|\n", -123);
	ft_printf("46.%3d|\n\n", -123);
	
	printf("47.%.0d|\n", -456);
	ft_printf("47.%.0d|\n\n", -456);
	
	printf("48.%.d|\n", -456);
	ft_printf("48.%.d|\n\n", -456);
	
	printf("49.%.3d|\n", -456);
	ft_printf("49.%.3d|\n\n", -456);
	
	printf("50.%.5d|\n", -456);
	ft_printf("50.%.5d|\n\n", -456);
	
	printf("51.%.*d|\n", -1, -456);
	ft_printf("51.%.*d|\n\n", -1, -456);

	printf("52.%.*d|\n", 0, -456);
	ft_printf("52.%.*d|\n\n", 0, -456);
	
	printf("53.%.*d|\n", 1, -456);
	ft_printf("53.%.*d|\n\n", 1, -456);
	
	printf("54.%.*d|\n", 3, -456);
	ft_printf("54.%.*d|\n\n", 3, -456);
	
	printf("55.%.*d|\n", 5, -456);
	ft_printf("55.%.*d|\n\n", 5, -456);
	
	printf("56.%*.*d|\n", 8, 6, -456);
	ft_printf("56.%*.*d|\n\n", 8, 6, -456);
	
	printf("57.%*.*d|\n", 6, 8, -456);
	ft_printf("57.%*.*d|\n\n", 6, 8, -456);

	printf("58.%*.*d|\n", -1, 2, -456);
	ft_printf("58.%*.*d|\n\n", -1, 2, -456);
	
	printf("59.%*.*d|\n", 1, 6, -456);
	ft_printf("59.%*.*d|\n\n", 1, 6, -456);
	
	printf("60.%*.*d|\n", 6, 1, -456);
	ft_printf("60.%*.*d|\n\n", 6, 1, -456);
	
	printf("61.% *.*d|\n", 6, 1, -456);
	ft_printf("61.% *.*d|\n\n", 6, 1, -456);
	
	printf("62.%-*.*d|\n", 6, 1, -456);
	ft_printf("62.%-*.*d|\n\n", 6, 1, -456);
	
	printf("63.% *.*d|\n", 6, 8, -456);
	ft_printf("63.% *.*d|\n\n", 6, 8, -456);
	
	printf("64.%-*.*d|\n", 6, 8, -456);
	ft_printf("64.%-*.*d|\n\n", 6, 8, -456);
	
	//printf("65.%-0*.*d|\n", 6, 1, -456);
	ft_printf("65.%-0*.*d|\n\n", 6, 1, -456);
	
	//printf("66.%-0*.*d|\n", 6, 8, -456);
	ft_printf("66.%-0*.*d|\n\n", 6, 8, -456);
	
	printf("67.% *.*d|\n", 1, 2, -456);
	ft_printf("67.% *.*d|\n\n", 1, 2, -456);
	
	printf("68.%-*.*d|\n", 2, 1, -456);
	ft_printf("68.%-*.*d|\n\n", 2, 1, -456);
	
	
	return (0);
}
