/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 15:58:03 by yeslee            #+#    #+#             */
/*   Updated: 2020/10/04 17:00:35 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_sisalpha(int c)
{
    if ((c >= 'A') && (c <= 'Z'))
        return (1);
    else if ((c > 'a') && (c <= 'z'))
        return (2);

    return (0);
}