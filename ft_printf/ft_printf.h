/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 22:12:53 by yeslee            #+#    #+#             */
/*   Updated: 2021/01/13 10:30:59 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

typedef struct	s_list
{
	int			left;
	int			zero;

	int			width;
	int			prec;

	int			len_mod;
	char		type;
	int			len;
	int			result;
	int			cnt;
}				t_list;

int				ft_printf(const char *str, ...);
const char		*ft_parsing(const char *str, t_list *lst, va_list ap);
int				ft_atoi(char *str);
void			ft_print_d(t_list *lst);
char			*ft_itoa(int n);
int				ft_intlen(int n);
#endif
