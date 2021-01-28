/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 15:03:51 by yeslee            #+#    #+#             */
/*   Updated: 2021/01/28 18:53:19 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int main()
{
/*	printf("<<<<<< Print d and i >>>>>>>\n\n");

	ft_printf("this %d number", 17);

    ft_printf("%07d", -54);

    printf("Result is Positive\n\n");
	
	printf(  "0.%d|\n", 123);
    ft_printf(  "0.%d|\n\n", 123);
	
	printf(  "0-1.%0d|\n", 123);
    ft_printf(  "0-1.%0d|\n\n", 123);
	
	printf(  "0-2.%-d|\n", 123);
    ft_printf(  "0-2.%-d|\n\n", 123);
	
	printf(  "0-3.%d|\n", 0);
    ft_printf(  "0-3.%d|\n\n", 0);
	
	printf(  "1.%8d|\n", 123);
    ft_printf(  "1.%8d|\n\n", 123);
	
	printf( "2.%-3d|\n", 123);
	ft_printf( "2.%-3d|\n\n", 123);

	printf( "2-1.%-8d|\n", 123);
	ft_printf( "2-1.%-8d|\n\n", 123);

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
	
	printf("23.%4.4d|\n", 456);
	ft_printf("23.%4.4d|\n\n", 456);
	
	printf("23-1.%*.*d|\n", 8, 6, 456);
	ft_printf("23-1.%*.*d|\n\n", 8, 6, 456);
	
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
	
	printf("27-8.%0*.*d|\n", 2, 1, 456);
	ft_printf("27-8.%0*.*d|\n\n", 2, 1, 456);
	
	printf("27-9.%0.d|\n", 123);
	ft_printf("27-9.%0.d|\n\n", 123);
	
	printf("Result is Negative\n\n");

	printf(  "28.%8d|\n", -123);
	ft_printf(  "28.%8d|\n\n", -123);

	printf( "29.%-8d|\n", -123);
	ft_printf( "29.%-8d|\n\n", -123);

//	printf( "30.%+8d\n", -123);
//  printf( "%31. 8d\n", -123);
    
//	printf( "32.%08d|\n", -123);
//    ft_printf( "33.%08d|\n\n", -123);

//	printf("34.%-+8d\n", -123);
//  printf("35.%- 8d\n", -123);
//  printf("36.%+08d\n", -123);
//  printf("37.% 08d\n", -123);
	
//	printf("38.%-08d|\n", -123);
//	ft_printf("39.%-08d|\n\n", -123);

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
	
//	printf("61.% *.*d|\n", 6, 1, -456);
//	ft_printf("61.% *.*d|\n\n", 6, 1, -456);
	
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

//	printf("86-1.%d|\n", "");
//	ft_printf("86-1.%d|\n\n", "");

	printf("[count]\n\n");

	printf("87.%d\n", printf("87-1. %d\n", -123));
    ft_printf("87.%d\n", ft_printf("87-1. %d\n", -123));
	
	printf("88.%d\n", printf("88-1. %d\n", 123));
    ft_printf("88.%d\n", ft_printf("88-1. %d\n", 123));
	
	printf("89.%-d\n", printf("89-1. %-d\n", -123));
    ft_printf("89.%-d\n", ft_printf("89-1. %-d\n", -123));
	
	printf("90.%4d\n", printf("90-1. %4d\n", -12));
    ft_printf("90.%4d\n", ft_printf("90-1. %4d\n", -12));
	
	printf("91.%-5d\n", printf("91-1. %-5d\n", -123));
    ft_printf("91.%-5d\n", ft_printf("91-1. %-5d\n", -123));
	
	printf("92.%.6d\n", printf("92-1. %.6d\n", -123));
    ft_printf("92.%.6d\n", ft_printf("92-1. %.6d\n", -123));
	
	printf("93.%7.8d\n", printf("93-1. %7.8d\n", -123));
    ft_printf("93.%7.8d\n", ft_printf("93-1. %7.8d\n", -123));
	
	printf("94.%-9.10d\n", printf("94-1. %-9.10d\n", -123));
    ft_printf("94.%-9.10d\n", ft_printf("94-1. %-9.10d\n", -123));
	
//	printf("95.%d %d|\n", printf("95-1.%d %d|\n", 12, 10));
//	ft_printf("95.%d %d|\n\n", ft_printf("95-1.%d %d|\n\n", 12, 10));

	printf("%d\n", printf("%3.3d\n", 12));
	ft_printf("%d\n", ft_printf("%3.3d\n", 12));

    printf("|%08.5d|\n", 34);
    ft_printf("|%08.5d|\n", 34);

    printf("|%08.d|", 0);
    ft_printf("|%08.d|", 0);
*/
/*	printf("\n\n<< print %% >>\n\n");

//	printf("1.%\n");
	ft_printf("1.%\n\n");
	
	printf("2.%%\n");
	ft_printf("2.%%\n\n");
	
//	printf("3.%%%\n");
	ft_printf("3.%%%\n\n");
	
	printf("3-1.%%%%\n");
	ft_printf("3-1.%%%%\n\n");

	printf("4.-%%\n");
	ft_printf("4.-%%\n\n");
	
	printf("5.0%%\n");
	ft_printf("5.0%%\n\n");
	
	printf("6.3%%\n");
	ft_printf("6.3%%\n\n");
	
	printf("7.-3%%\n");
	ft_printf("7.-3%%\n\n");
	
	printf("8.4%%\n");
	ft_printf("7.4%%\n\n");
	
	printf("9.-4%%\n");
	ft_printf("9.-4%%\n\n");
	*/

/*	printf("|%2c|%2d|\n",(char)1, (char)1);
	printf("|%2c|%2d|\n",'1','1');
	//printf("|%2c|",'!');
	printf("|%2c|%2d|\n",1,1);*/
	//printf("|%2c%3c|",1,2);
	//printf("|%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c|",(char)1,(char)2,(char)1,(char)2,(char)1,(char)2,(char)1,(char)2,(char)1,2);
	//printf("|%c%c%c%c%c%c%c%c%c%c|",(char)1,(char)2,(char)1,(char)2,(char)1,(char)2,(char)1,(char)2,(char)1,2);
	//ft_printf("%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c",(char)1,(char)2,(char)1,(char)2,(char)1,(char)2,(char)1,(char)2,(char)1,(char)2);

//    printf("%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c",(char)1,(char)2,);
   
//	printf("%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c");

  //  printf("%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c");

/*	printf("\n\n<< print s>>\n\n");
	
	printf("|%-*.*s|\n", -7, -3, "yolo");
	ft_printf("|%-*.*s|\n", -7, -3, "yolo");*/
/*	printf("0.|%4s|\n", "123");
	ft_printf("0.|%4s|*\n", "123");
	
	printf("0-1.|%4.s|\n", "123");
	ft_printf("0-1.|%4.s|*\n", "123");
	
	printf("1.|%2.2s|\n", "123");
	ft_printf("1.|%2.2s|*\n", "123");
	
	printf("2.|%2.4s|\n", "123");
	ft_printf("2.|%2.4s|*\n", "123");
	
	printf("3.|%4.2s|\n", "123");
	ft_printf("3.|%4.2s|*\n", "123");
	
	printf("3-1.|%5.4s|\n", "123");
	ft_printf("3-1.|%5.4s|*\n", "123");
	
	printf("4.|%4.4s|\n", "123");
	ft_printf("4.|%4.4s|*\n", "123");
	
	printf("5.|%3.3s|\n", "123");
	ft_printf("5.|%3.3s|*\n", "123");
	
	printf("6.|%4.3s|\n", "123");
	ft_printf("6.|%4.3s|*\n", "123");
	
	printf("7.|%.s|\n", "123");
	ft_printf("7.|%.s|*\n", "123");
	
	printf("8.|%.0s|\n", "123");
	ft_printf("8.|%.s|*\n", "123");
	
	printf("9.|%s|\n", "123");
	ft_printf("9.|%s|*\n", "123");
	
	printf("10.|%-4.2s|\n", "123");
	ft_printf("10.|%-4.2s|*\n", "123");
	
	printf("11.|%-4.4s|\n", "123");
	ft_printf("11.|%-4.4s|*\n", "123");
	
	printf("12.|%3.s|\n", NULL);
	ft_printf("12.|%3.s|*\n", NULL);

	printf("13.|%3.s|\n", "0");
	ft_printf("13.|%3.s|*\n", "0");
*/	
	//printf("%.3s%.2s", "holla", "bitch");
	//ft_printf("%.3s%.2s*", "holla", "bitch");

	//printf("hello, %s.\n", NULL);
	//ft_printf("hello, %s.\n", NULL);

	//printf("|%3.6s|\n", "");
	//ft_printf("|%3.6s|*\n", "");

	//printf("%.*s\n", -3, 0);
	
	//printf("|%.03s|\n", NULL);
	//ft_printf("|%.03s|\n", NULL);

	//printf("|%.*s|", -3, NULL);
	//ft_printf("f|%.*s|*", -3, NULL);
	
/*	printf("<< print p>>\n\n");

	char *i;

	i = "123";
	//printf("%.*p", 3, 12345);
	ft_printf("|%.*p|", 10, i);
*/

//	printf("|w:%1c%2c%3c%4c%1c%2c%3c%4c|\n", 128, 129, 130, 131, 132, 133, 134, 135);
//	ft_printf("|w:%1c%2c%3c%4c%1c%2c%3c%4c|\n", 128, 129, 130, 131, 132, 133, 134, 135);
	
//	printf("|w:%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c|\n", 128, 129, 130, 131, 132, 133, 134, 135);
//	ft_printf("|w:%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c|\n", 128, 129, 130, 131, 132, 133, 134, 135);

/*	char value = 'y';

	printf("|%-4.c|\n", value);
	ft_printf("|%-4.c|\n\n", value);

	printf("|%-4c|\n", value);
	ft_printf("|%-4c|\n\n", value);

	printf("|%-3.c|\n", value);
	ft_printf("|%-3.c|\n\n", value);

	printf("|%-3c|\n", value);
	ft_printf("|%-3c|\n\n", value);
*/
/*	printf("===s < 0===\n\n");

	printf("|w:%-1c|\n", 128);
	ft_printf("|w:%-1c|*\n\n", 128);
	
	printf("|w:%-2c|\n", 128);
	ft_printf("|w:%-2c|*\n\n", 128);
	
	printf("|w:%-3c|\n", 128);
	ft_printf("|w:%-3c|*\n\n", 128);
	
	printf("|w:%-4c|\n", 128);
	ft_printf("|w:%-4c|*\n\n", 128);
	
	printf("|w:%-1c|\n", 129);
	ft_printf("|w:%-1c|*\n\n", 129);
	
	printf("|w:%-2c|\n", 129);
	ft_printf("|w:%-2c|*\n\n", 129);
	
	printf("|w:%-3c|\n", 129);
	ft_printf("|w:%-3c|*\n\n", 129);
	
	printf("|w:%-4c|\n", 129);
	ft_printf("|w:%-4c|*\n\n", 129);*/

	//printf("===print %===\n\n");

	//printf("%zu%\n", ft_valuelen("%"));
	//ft_printf("1.%d%\n\n", ft_valuelen("%"));
	
	//printf("2.%zu%%\n", ft_valuelen("%%"));
	//ft_printf("{%%}\n", ft_printf("|%%|\n"));

	//printf("%zu%%%\n", ft_valuelen("%%%"));
	//ft_printf("3-1.%d%%%\n\n", ft_valuelen("%%%"));
	
	//printf("4.%zu%%%%\n", ft_valuelen("%%%%"));
	//ft_printf("{%%%%}\n", ft_printf("|%%%%|\n"));

	printf("< print_lover >\n\n");

/*	printf("-->|%0*.*d|<--\n", 4, -3, 12);
	ft_printf("-->|%0*.*d|<--\n\n", 4, -3, 12);
	
	printf("-->|%0*.*d|<--\n", 4, -2, 12);
	ft_printf("-->|%0*.*d|<--\n\n", 4, -2, 12);
	
	printf("-->|%0*.*d|<--\n", 4, -1, 12);
	ft_printf("-->|%0*.*d|<--\n\n", 4, -1, 12);
	
	printf("-->|%04.*d|<--\n", -4, 12);
	ft_printf("-->|%04.*d|<--\n", -4, 12);

	printf("-->|%04.*d|<--\n", -3, 12);
	ft_printf("-->|%04.*d|<--\n", -3, 12);

	printf("-->|%04.*d|<--\n", -2, 12);
	ft_printf("-->|%04.*d|<--\n", -2, 12);

	printf("-->|%04.*d|<--\n", -1, 12);
	ft_printf("-->|%04.*d|<--\n", -1, 12);
*/	

/*	printf("-->|%-15.16s|<--\n", "abc");
	ft_printf("-->|%-15.16s|<--\n", "abc");

	printf("-->|%*.*s|<--\n", -3, -4, "abc");
	ft_printf("-->|%*.*s|<--\n", -3, -4, "abc");

	printf("|%d|\n", printf("-->|%4.5s|<--\n", "abc"));
	ft_printf("|%d|\n", ft_printf("-->|%4.5s|<--\n", "abc"));

	printf("-->|%8.9s|<--\n", "abc");
	ft_printf("-->|%8.9s|<--\n", "abc");

	printf("-->|%--15.16s|<--\n", "abc");
	ft_printf("-->|%--15.16s|<--\n", "abc");

	printf("-->|%-*.*s|<--\n", -3, -4, "abc");
	ft_printf("-->|%-*.*s|<--\n", -3, -4, "abc");

	printf("-->|%-14.15s|<--\n", NULL);
	ft_printf("-->|%-14.15s|<--\n", NULL);*/

/*	printf("-->|%-16.p|<--\n", "123");
	ft_printf("-->|%-16.p|<--\n", "123");

	printf("-->|%-16p|<--\n", "123");
	ft_printf("-->|%-16p|<--\n", "123");*/

/*	printf("|%0%|\n");
	ft_printf("|%0%|\n\n");

	printf("1.%d\n", printf("|%0%|\n"));
	ft_printf("|%d|\n", ft_printf("|%0%|\n"));

	printf("|%-%|\n");
	ft_printf("|%-%|\n\n");

	printf("|%03%|\n");
	ft_printf("|%03%|\n\n");

	printf("|%-.3%|\n");
	ft_printf("|%-.3%|\n\n");

	printf("|%3%|\n");
	ft_printf("|%3%|\n\n");

	printf("|%.3%|\n");
	ft_printf("|%.3%|\n\n");

	printf("|%4.3%|\n");
	ft_printf("|%4.3%|\n\n");

	printf("|%3.4%|\n");
	ft_printf("|%3.4%|\n\n");

	printf("2.%d\n", printf("|%3.4%%%|\n"));
	ft_printf("|%d|\n", ft_printf("|%3.4%%%|\n"));

	printf("|%-4.*%|\n", -4);
	ft_printf("|%-4.*%|\n\n", -4);
*/
/*	printf("-->|%-4d|<--\n", 3);
	ft_printf("-->|%-4.-1d|<--\n", 3);
	ft_printf("-->|%-4.-2d|<--\n", 3);
	ft_printf("-->|%-4.-3d|<--\n", 3);
	ft_printf("-->|%-4.-4d|<--\n", 3);
	ft_printf("-->|%-4.-5d|<--\n", 3);
	
	printf("-->|%-4d|<--\n", 12345);
	ft_printf("-->|%-4.-1d|<--\n", 12345);
	ft_printf("-->|%-4.-2d|<--\n", 12345);
	ft_printf("-->|%-4.-3d|<--\n", 12345);
	ft_printf("-->|%-4.-4d|<--\n", 12345);
	ft_printf("-->|%-4.-5d|<--\n", 12345);
	
	printf("-->|%-4d|<--\n", -3);
	ft_printf("-->|%-4.-1d|<--\n", -3);
	ft_printf("-->|%-4.-2d|<--\n", -3);
	ft_printf("-->|%-4.-3d|<--\n", -3);
	ft_printf("-->|%-4.-4d|<--\n", -3);
	ft_printf("-->|%-4.-5d|<--\n", -3);
	
	printf("-->|%-4d|<--\n", -12345);
	ft_printf("-->|%-4.-1d|<--\n", -12345);
	ft_printf("-->|%-4.-2d|<--\n", -12345);
	ft_printf("-->|%-4.-3d|<--\n", -12345);
	ft_printf("-->|%-4.-4d|<--\n", -12345);
	ft_printf("-->|%-4.-5d|<--\n", -12345);
*/	
/*	printf("-->|%-4.d|<--\n", 123);
	ft_printf("-->|%-4.d|<--\n", 123);
	
	printf("-->|%--1.*u|<--\n", 4, 0);
	ft_printf("-->|%--1.*u|<--\n", 4, 0);

	printf("-->|%-4.*X|<--\n", -4, 0);
	ft_printf("-->|%-4.*X|<--\n", -4, 0);
	
//	printf("-->|%-4.*X|<--\n", 4, 4294967295);
	ft_printf("-->|%-4.*X|<--\n", 4, 4294967295);
	
//	printf("-->|%-4.*X|<--\n", -4, 4294967295);
	ft_printf("-->|%-4.*X|<--\n", -4, 4294967295);
*/	
/*	printf("-->|%-16.s|<--\n", "1");
	ft_printf("-->|%-16.s|<--\n", "1");

	printf("-->|%-16s|<--\n", "1");
	ft_printf("-->|%-16.-4s|<--\n", "1");

	printf("-->|%-16s|<--\n", "1");
	ft_printf("-->|%-16.-3s|<--\n", "1");

	printf("-->|%-16s|<--\n", "1");
	ft_printf("-->|%-16.-2s|<--\n", "1");
*/

/*	printf("-->|%-4.c|<--\n", 'y');
	ft_printf("-->|%-4.c|<--\n", 'y');

	printf("-->|%-4c|<--\n", 'y');
	ft_printf("-->|%-4c|<--\n", 'y');

	printf("-->|%-3.c|<--\n", 'y');
	ft_printf("-->|%-3.c|<--\n", 'y');

	printf("-->|%-3c|<--\n", 'y');
	ft_printf("-->|%-3c|<--\n", 'y');

	printf("-->|%-2.c|<--\n", 'y');
	ft_printf("-->|%-2.c|<--\n", 'y');

	printf("-->|%-2c|<--\n", 'y');
	ft_printf("-->|%-2c|<--\n", 'y');
*/
/*	int a = 0;
	int *b = NULL;
	
	printf("-->|%-16.p|<--\n", b);
	ft_printf("-->|%-16.p|<--\n\n", b);

	printf("-->|%-16p|<--\n", b);
	ft_printf("-->|%-16p|<--\n\n", b);

	printf("-->|%-15.p|<--\n", b);
	ft_printf("-->|%-15.p|<--\n\n", b);

	printf("-->|%-15p|<--\n", b);
	ft_printf("-->|%-15p|<--\n\n", b);

	printf("-->|%-14.p|<--\n", b);
	ft_printf("-->|%-14.p|<--\n\n", b);

	printf("-->|%-14p|<--\n", b);
	ft_printf("-->|%-14p|<--\n\n", b);

	printf("-->|%-13.p|<--\n", b);
	ft_printf("-->|%-13.p|<--\n\n", b);

	printf("-->|%-13p|<--\n", b);
	ft_printf("-->|%-13p|<--\n\n", b);*/

/*	printf("%5.2d|\n", 0);
	ft_printf("%5.2d|\n", 0);
	
	printf("%5.3d|\n", 12);
	ft_printf("%5.3d|\n", 12);
	
	printf("%5.3d|\n", 1234);
	ft_printf("%5.3d|\n", 1234);
	
	printf("%5.6d|\n", 12);
	ft_printf("%5.6d|\n", 12);*/
	
/*	unsigned int u;
	int d;
	char *s;

	u = 1234567;
	d = 123;
	s = NULL;
	printf("-->|%.u|<--\n", u);
	ft_printf("-->|%.u|<--\n\n", u);
	
	printf("-->|%-4u|<--\n", u);
	ft_printf("-->|%-4.-4u|<--\n\n", u);
	
	//printf("-->|%-4u|<--\n", u);
	ft_printf("-->|%--4.-4u|<--\n\n", u);
	
	printf("-->|%0*.*u|<--\n", -2, 4, u);
	ft_printf("-->|%0*.*u|<--\n\n", -2, 4, u);
*/
/*	printf("-->|%0*.*u|<--\n", 2, -4, u);
	ft_printf("-->|%0*.*u|<--\n\n", 2, -4, u);

	printf("-->|%0*.*x|<--\n", 2, -4, u);
	ft_printf("-->|%0*.*x|<--\n\n", 2, -4, u);

	printf("-->|%0*.*X|<--\n", 2, -4, u);
	ft_printf("-->|%0*.*X|<--\n\n", 2, -4, u);

	printf("-->|%-4.d|<--\n", d);
	ft_printf("-->|%-4.d|<--\n\n", d);
	
	printf("-->|%-4.*d|<--\n", -1, d);
	ft_printf("-->|%-4.*d|<--\n\n", -1, d);
	
	printf("-->|%-16s|<--\n", s);
	ft_printf("-->|%-16s|<--\n\n", s);*/

	//printf("hello%2.3");

//	printf("%d\n", printf("%0i, %0d, %0d, %0d, %0d, %0d, %d, %d\n", 8, -12, 123456789, 0, -12345678, 97, -2147483648, 2147483647));
	
/*	printf("%d\n", printf("|%0i\n", 8));
	printf("%d\n", printf("|%0d\n", -12));
	printf("%d\n", printf("|%0d\n", 123456789));
	printf("%d\n", printf("|%0d\n", 0));
	printf("%d\n", printf("|%0d\n", -123456789));
	printf("%d\n", printf("|%0d\n", 97));
//	printf("%d\n", printf("|%0d\n", -2147483648));
	printf("%d\n", printf("|%0d\n", 2147483647));
	printf("=================\n");

	ft_printf("%d\n", ft_printf("|%0i\n", 8));
	ft_printf("%d\n", ft_printf("|%0d\n", -12));
	ft_printf("%d\n", ft_printf("|%0d\n", 123456789));
	ft_printf("%d\n", ft_printf("|%0d\n", 0));
	ft_printf("%d\n", ft_printf("|%0d\n", -123456789));
	ft_printf("%d\n", ft_printf("|%0d\n", 97));
	ft_printf("%d\n", ft_printf("|%0d\n", -2147483648));
	ft_printf("%d\n", ft_printf("|%0d\n", 2147483647));*/
	
/*	printf("%d|\n", printf("%2s\n", "abcdefghijklmnop"));
	printf("%d|\n", printf("%2s\n", "-a"));
	printf("%d|\n", printf("%2s\n", "-12"));
	printf("%d|\n", printf("%2s|", "0"));
	printf("%d|\n", printf("%2s\n", "%%"));
	
	printf("================\n");
	
	ft_printf("%d|\n", ft_printf("%2s\n", "abcdefghijklmnop"));
	ft_printf("%d|\n", ft_printf("%2s\n", "-a"));
	ft_printf("%d|\n", ft_printf("%2s\n", "-12"));
	ft_printf("%d|\n", ft_printf("%2s|", "0"));
	ft_printf("%d|\n", ft_printf("%2s\n", "%%"));*/

	printf("|%d|\n", printf("%.*s", 1, "abcdefghijklmnop"));
	printf("|%d|\n", printf("%.*s", 1, "-a"));
	printf("|%d|\n", printf("%.*s", 1, "0"));
	printf("|%d|\n", printf("%.*s", 1, "%%"));
	printf("|%d|\n", printf("%.*s", 1, "-2147483648"));
	printf("|%d|\n", printf("%.*s", 1, "0x12345678"));
	
	printf("\n------------\n");

	ft_printf("|%d|\n", ft_printf("%.*s", 1, "abcdefghijklmnop"));
	ft_printf("|%d|\n", ft_printf("%.*s", 1, "-a"));
	ft_printf("|%d|\n", ft_printf("%.*s", 1, "0"));
	ft_printf("|%d|\n", ft_printf("%.*s", 1, "%%"));
	ft_printf("|%d|\n", ft_printf("%.*s", 1, "-2147483648"));
	ft_printf("|%d|\n", ft_printf("%.*s", 1, "0x12345678"));
	ft_printf("|%d|\n", ft_printf("%.*s", 1, "-0"));


	//	printf("NULL");
	return (0);
}
