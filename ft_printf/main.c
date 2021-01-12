/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 15:03:51 by yeslee            #+#    #+#             */
/*   Updated: 2021/01/12 20:33:05 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int main()
{
	ft_printf("this %d number", 17);

    printf("Result is Positive\n\n");
	
	printf(  "0.%d|\n", 123);
    ft_printf(  "0.%d|\n\n", 123);
	
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

	printf("11.%2d|\n", 123);
	ft_printf("11.%2d|\n\n", 123);

	printf("12.%3d|\n", 123);
	ft_printf("12.%3d|\n\n", 123);

//	printf("12-1.%.-1d\n", 456); precision must be positive

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
	
	printf("20.%-.*d|\n", 1, 456);
	ft_printf("20.%-.*d|\n\n", 1, 456);
	
	printf("20-1.%-.*d|\n", 4, 456);
	ft_printf("20-1.%-.*d|\n\n", 4, 456);
	
	printf("20-2.%0.*d|\n", 1, 456);
	ft_printf("20-2.%0.*d|\n\n", 1, 456);
	
	printf("20-3.%0.*d|\n", 4, 456);
	ft_printf("20-3.%0.*d|\n\n", 4, 456);
	
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
	ft_printf("27-1.%-*.*d|\n\n", 6, 1, 456);
	
	//printf("27-2.% *.*d|\n", 6, 8, 456);
	//ft_printf("27-2.% *.*d|\n\n", 6, 8, 456);
	
	printf("27-3.%-*.*d|\n", 6, 8, 456);
	ft_printf("27-3.%-*.*d|\n\n", 6, 8, 456);
	
	//printf("27-4.%-0*.*d|\n", 6, 1, 456);
	ft_printf("27-4.%-0*.*d|\n\n", 6, 1, 456);
	
	//printf("27-5.%-0*.*d|\n", 6, 8, 456);
	ft_printf("27-5.%-0*.*d|\n\n", 6, 8, 456);
	
//	printf("27-6.% *.*d|\n", 1, 2, 456);
//	ft_printf("27-6.% *.*d|\n\n", 1, 2, 456);
	
	printf("27-7.%-*.*d|\n", 2, 1, 456);
	ft_printf("27-7.%-*.*d|\n\n", 2, 1, 456);
	
	printf("Result is Negative\n\n");

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
	
	printf("55-1.%-.*d|\n", 1, 456);
	ft_printf("55-1.%-.*d|\n\n", 1, 456);
	
	printf("55-2.%-.*d|\n", 4, 456);
	ft_printf("55-2.%-.*d|\n\n", 4, 456);
	
	printf("55-3.%0.*d|\n", 1, 456);
	ft_printf("55-3.%0.*d|\n\n", 1, 456);
	
	printf("55-4.%0.*d|\n", 4, 456);
	ft_printf("55-4.%0.*d|\n\n", 4, 456);
	
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
	
//	printf("63.% *.*d|\n", 6, 8, -456);
//	ft_printf("63.% *.*d|\n\n", 6, 8, -456);
	
	printf("64.%-*.*d|\n", 6, 8, -456);
	ft_printf("64.%-*.*d|\n\n", 6, 8, -456);
	
	//printf("65.%-0*.*d|\n", 6, 1, -456);
	ft_printf("65.%-0*.*d|\n\n", 6, 1, -456);
	
	//printf("66.%-0*.*d|\n", 6, 8, -456);
	ft_printf("66.%-0*.*d|\n\n", 6, 8, -456);
	
//	printf("67.% *.*d|\n", 1, 2, -456);
//	ft_printf("67.% *.*d|\n\n", 1, 2, -456);
	
	printf("68.%-*.*d|\n", 2, 1, -456);
	ft_printf("68.%-*.*d|\n\n", 2, 1, -456);
	
	printf("[width, prec > 9]\n\n");
	
	printf("69.%10.23d|\n", 789);
	ft_printf("69.%10.23d|\n\n", 789);

	printf("70.%*d|\n", 12, 123);
	ft_printf("70.%*d|\n\n", 12, 123);

	printf("71.%.*d|\n", 12, 123);
	ft_printf("71.%.*d|\n\n", 12, 123);

	printf("72.%*.*d|\n", 10, 12, 123);
	ft_printf("72.%*.*d|\n\n", 10, 12, 123);

	printf("73.%12.11d|\n", 123);
	ft_printf("73.%12.11d|\n\n", 123);

	printf("74.%*d|\n", 12, 123);
	ft_printf("74.%*d|\n\n", 12, 123);

	printf("75.%.*d|\n", 12, 123);
	ft_printf("75.%.*d|\n\n", 12, 123);

	printf("76.%*.*d|\n", 12, 10, 123);
	ft_printf("76.%*.*d|\n\n", 12, 10, 123);

	printf("77.%10.12d|\n", -123);
	ft_printf("77.%10.12d|\n\n", -123);

	printf("78.%*d|\n", 12, -123);
	ft_printf("78.%*d|\n\n", 12, -123);

	printf("79.%.*d|\n", 12, -123);
	ft_printf("79.%.*d|\n\n", 12, -123);

	printf("80.%*.*d|\n", 10, 12, -123);
	ft_printf("80.%*.*d|\n\n", 10, 12, -123);

	printf("81.%12.11d|\n", -123);
	ft_printf("81.%12.11d|\n\n", -123);

	printf("82.%*d|\n", 12, -123);
	ft_printf("82.%*d|\n\n", 12, -123);

	printf("83.%.*d|\n", 12, -123);
	ft_printf("83.%.*d|\n\n", 12, -123);

	printf("84.%*.*d|\n", 12, 10, -123);
	ft_printf("84.%*.*d|\n\n", 12, 10, -123);

	printf("85.%d %d|\n", 12, 10);
	ft_printf("85.%d %d|\n\n", 12, 10);

//	printf("86.%2.3.4d|\n", 1);
//	ft_printf("86.%2.3.4d|\n", 1);

	printf("86.%001.02d|\n", 3);
	ft_printf("86.%001.02d|\n\n", 3);

	printf("[count]\n\n");
		
	printf("87.%d\n", printf("87-1.%d\n", 1));
    ft_printf("87.%d\n", ft_printf("87-1.%d\n", 1));
	
	printf("88.%d\n", printf("88-1.%d\n", 123));
    ft_printf("88.%d\n", ft_printf("88-1.%d\n", 123));
	
	printf("89.%-d\n", printf("89-1.%-d\n", 1));
    ft_printf("89.%-d\n", ft_printf("89-1.%-d\n", 1));
	
	printf("90.%4d\n", printf("90-1.%4d\n", 1));
    ft_printf("90.%4d\n", ft_printf("90-1.%4d\n", 1));
	
	printf("91.%-5d\n", printf("91-1.%-5d\n", 1));
    ft_printf("91.%-5d\n", ft_printf("91-1.%-5d\n", 1));
	
	printf("92.%.6d\n", printf("92-1.%.6d\n", 1));
    ft_printf("92.%.6d\n", ft_printf("92-1.%.6d\n", 1));
	
	printf("93.%7.8d\n", printf("93-1.%7.8d\n", 1));
    ft_printf("93.%7.8d\n", ft_printf("93-1.%7.8d\n", 1));
	
	printf("94.%-9.10d\n", printf("94-1.%-9.10d\n", 1));
    ft_printf("94.%-9.10d\n", ft_printf("94-1.%-9.10d\n", 1));
	
//	printf("95.%d %d|\n", printf("95-1.%d %d|\n", 12, 10));
//	ft_printf("95.%d %d|\n\n", ft_printf("95-1.%d %d|\n\n", 12, 10));

	return (0);
}
