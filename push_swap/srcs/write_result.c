/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_result.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 16:52:59 by yeslee            #+#    #+#             */
/*   Updated: 2021/04/22 16:54:14 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ok()
{
	write(1, "OK\n", 3);
	exit(0);
}

void	ft_ko()
{
	write(1, "KO\n", 3);
	exit(0);
}

void	ft_error_message()
{
	write(2, "Error\n", 6);
	exit(0);
}
