/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 15:07:09 by yeslee            #+#    #+#             */
/*   Updated: 2020/10/05 17:00:12 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <string.h>


int		ft_atoi(const char *str);
int		strncmp(const char *s1, const char *s2, size_t n);

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(signed char c);
int		isprint(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strnstr(const char *big, const char *little, size_t len);
void	*memset(void *b, int c, size_t len);
int		ft_strlen(const char *c);

typedef	struct	s_list
{
    void	*content;
    struct	s_list	*next;
}	t_list;


t_list	*ft_lstnew(void *content);
void	ft_Istadd_front(t_list **Ist, t_list *new);
int		ft_Istsize(t_list *Ist);
t_list	*ft_Istlast(t_list *Ist);
