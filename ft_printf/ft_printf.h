/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 22:12:53 by yeslee            #+#    #+#             */
/*   Updated: 2021/01/05 20:16:54 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct	s_list
{
	int			space;
	int			plus;
	int			left;
	int			zero;

	int			width;
	int			prec;

	//	char	sharp;
	int			len_mod;
	char		type;
	int			len;
	int			result;
	int			cnt;
}				t_list;

int				ft_printf(const char *str, ...);
const char		*ft_parsing(const char *str, t_list *lst);
int				ft_atoi(char *str);
void			ft_print_d(t_list *lst);
char			*ft_itoa(int n);
int				ft_len(int n);
#endif
