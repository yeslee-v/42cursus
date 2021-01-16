/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 22:12:53 by yeslee            #+#    #+#             */
/*   Updated: 2021/01/16 11:13:42 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include "libft/libft.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct	s_lst
{
	int			left;
	int			zero;
	int			width;
	int			prec;

	char		type;
	int			res;
	int			sign;
	int			len;
	int			cnt;
}				t_lst;

int				ft_printf(const char *str, ...);
int				ft_istype(const char *str);

void			ft_parsing(const char **str, t_lst *lst, va_list ap);
void			ft_check_flag(const char **str, t_lst *lst);
void			ft_check_width(const char **str, t_lst *lst, va_list ap);
void			ft_check_prec(const char **str, t_lst *lst, va_list ap);
void			ft_print_d_i(t_lst *lst);
#endif
