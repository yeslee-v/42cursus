/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 18:30:21 by yeslee            #+#    #+#             */
/*   Updated: 2021/04/08 21:32:53 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_map_parsing_intro(int ac, char **av, t_all *all)
{
	int		fd;
	char	*line;

	ft_struct_init(ac, av, all);
	fd = ft_check_error(ac, av);
	while ((get_next_line(fd, &line)) > 0)
	{
		if (ft_strlen(line) > 2)
		{
			ft_read_line(line, all);
			free(line);
		}
	}
	if (!(all->map.cnt_exist))
		ft_error_message(7);
	ft_map_validation_intro(all);
	close(fd);
}

int	main(int ac, char **av)
{
	t_all	all;
	
	ft_map_parsing_intro(ac, av, &all);
	ft_t_info_init(&all);
	ft_mlx_intro(&all);
	return (0);
}
