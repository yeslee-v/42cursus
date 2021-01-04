/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 22:12:53 by yeslee            #+#    #+#             */
/*   Updated: 2021/01/04 10:47:57 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct	s_list
{
	int			left;
	int			zero;
	int			width;
	int			result;

	//	int		space;
	//	char	plus;
	//	char	sharp;
	int prec;  // precision
	char type; // cspdiuxX%
	int len;   // length of va_arg(ap, int)
	// char	*value;
	int cnt; // printf("%d\n", printf("%d\n", 123));
}				t_list;
int				ft_printf(const char *str, ...);
const char		*ft_parsing(const char *str, t_list *lst);
char			ft_type(char c);
int				ft_atoi(char *str);
void			ft_flag_d(t_list *lst);
char			*ft_itoa(int n);
int				ft_len(int n);
#endif
