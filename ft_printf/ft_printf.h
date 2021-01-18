/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 22:12:53 by yeslee            #+#    #+#             */
/*   Updated: 2021/01/18 22:45:43 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include "libft/libft.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/*typedef struct	s_flag
{
	int			left;
	int			zero;
}				t_flag;
*/
typedef struct	s_lst
{
	//t_flag			size;
	int			left;
	int			left_size;
	int			zero;
	int			zero_size;
	int			width;
	int			prec;

	char			type;

	int			res;
	int			sign;
	int			len;
	int			cnt;
}				t_lst;

int				ft_printf(const char *str, ...);
int				ft_istype(const char *str);

void			ft_reset(t_lst *lst);
void			ft_parsing(const char **str, t_lst *lst, va_list *ap);
void			ft_check_flag(const char **str, t_lst *lst);
void			ft_check_width(const char **str, t_lst *lst, va_list *ap);
void			ft_check_prec(const char **str, t_lst *lst, va_list *ap);
void			input_wid_prec(const char **str, int w_p, va_list *ap);
void			ft_check_result(const char **str, t_lst *lst, va_list *ap);
void			ft_negative_result(t_lst *lst);
void			ft_handle_conversion(const char **str, t_lst *lst);
void			ft_print_d_i(t_lst *lst);
void			ft_print_detail(t_lst *lst);
#endif
