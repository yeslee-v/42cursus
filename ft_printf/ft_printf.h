/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 22:12:53 by yeslee            #+#    #+#             */
/*   Updated: 2021/01/29 02:06:54 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct	s_lst
{
	int			left;
	int			left_size;
	int			zero;
	int			zero_size;
	int			width;
	int			dot;
	int			prec;

	char		type;

	long long	res;
	char		res_pct;
	char		*res_s;
	int			sign;
	int			len;
	int			cnt;
}				t_lst;

int				ft_printf(const char *str, ...);
void			ft_handle_conversion(t_lst *lst);
void			ft_reset(t_lst *lst);

void			ft_check_flag(const char **str, t_lst *lst);
void			ft_check_width(const char **str, t_lst *lst, va_list *ap);
void			ft_check_prec(const char **str, t_lst *lst, va_list *ap);
int				ft_input_wid_prec(const char **str, va_list *ap);

void			ft_check_result(const char **str, t_lst *lst, va_list *ap);
void			ft_negative_result(t_lst *lst);
int				ft_istype(const char **str, t_lst *lst);
void			ft_check_len_pux(t_lst *lst);

void			ft_handle_conversion(t_lst *lst);

void			ft_print_num(t_lst *lst);
void			ft_neg_to_pos(t_lst *lst);
void			ft_dflag_on(t_lst *lst);
void			ft_dflag_off(t_lst *lst);
void			ft_res_print_d(t_lst *lst);

void			ft_print_char(t_lst *lst);
void			ft_cflag_on(t_lst *lst);
void			ft_cflag_off(t_lst *lst);
void			ft_res_print_c(t_lst *lst);

void			ft_print_str(t_lst *lst);
void			ft_set_size(t_lst *lst);
void			ft_sflag_on(t_lst *lst);
void			ft_sflag_off(t_lst *lst);
void			ft_res_print_s(t_lst *lst);

void			ft_print_p(t_lst *lst);
void			ft_pflag_on(t_lst *lst);
void			ft_pflag_off(t_lst *lst);
void			ft_res_print_p(t_lst *lst);

char			*ft_itoa_base(unsigned long long value, int base, char type);

#endif
