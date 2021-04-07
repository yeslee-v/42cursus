/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_bmp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 16:30:54 by yeslee            #+#    #+#             */
/*   Updated: 2021/04/07 17:00:57 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	write_int(char *color, unsigned param)
{
	color[0] = (param >> 0);
	color[1] = (param >> 8);
	color[2] = (param >> 16);
}

void	ft_write_pixel(int fd, t_all *all)
{
	int		i;
	int		j;
	char	color[3];
	char	padding[3];
	int		padding_size;
	
	ft_bzero(padding, 3);
	padding_size = (4 - (all->game.r.width * IMG_DEPTH) % 4) % 4;
	i = all->game.r.height;
	while (--i >= 0)
	{
		j = -1;
		while (++j < all->game.r.width)
		{
			write_int(color, all->img.data[i * all->img.size_l / all->img.bpp * 8 + j]);
			write(fd, color, 3);
		}
		write(fd, padding, padding_size);
	}
}

/*void	ft_bmp_init(t_all *all, unsigned char *file_header[14], unsigned char *info_header[40])
{
	int		file_size;
	int		h_size;

	h_size = FILE_HEADER_SIZE + INFO_HEADER_SIZE;
	file_size = (h_size) + (all->game.r.width * all->game.r.height * IMG_DEPTH);
	ft_bzero(file_header, FILE_HEADER_SIZE);
	ft_bzero(info_header, INFO_HEADER_SIZE);
	*file_header[0] = (unsigned char)‘B’;
	*file_header[1] = (unsigned char)‘M’;
	*file_header[2] = (unsigned char)(file_size);
	*file_header[3] = (unsigned char)(file_size >> 8);
	*file_header[4] = (unsigned char)(file_size >> 16);
	*file_header[5] = (unsigned char)(file_size >> 24);
	*file_header[10] = (unsigned char)(h_size);
	*info_header[0] = (unsigned char)(INFO_HEADER_SIZE);
	*info_header[4] = (unsigned char)(all->game.r.width);
	*info_header[5] = (unsigned char)(all->game.r.width >> 8);
	*info_header[6] = (unsigned char)(all->game.r.width >> 16);
	*info_header[7] = (unsigned char)(all->game.r.width >> 24);
	*info_header[8] = (unsigned char)(all->game.r.height);
	*info_header[9] = (unsigned char)(all->game.r.height >> 8);
	*info_header[10] = (unsigned char)(all->game.r.height >> 16);
	*info_header[11] = (unsigned char)(all->game.r.height >> 24);
	*info_header[12] = (unsigned char)1;
	*info_header[14] = (unsigned char)(BMP_BPP);
}*/

int		ft_save_bmp_intro(t_all *all)
{
	int		file_size;
	int		h_size;
	int		fd;
	unsigned char	file_header[14];	// file_header_size
	unsigned char	info_header[40];	// info_header_size

	fd = open("save.bmp", O_CREAT | O_WRONLY | O_TRUNC, 0744);
	if (fd < 0)
	{
		//mlx_destroy_image(game->mlx, game->img.img);
		printf("error bmp\n");
	}
	//ft_bmp_init(all, &file_header, &info_header);
	h_size = FILE_HEADER_SIZE + INFO_HEADER_SIZE;
	file_size = (h_size) + (all->game.r.width * all->game.r.height * IMG_DEPTH);
	ft_bzero(file_header, FILE_HEADER_SIZE);
	ft_bzero(info_header, INFO_HEADER_SIZE);
	file_header[0] = (unsigned char)'B';
	file_header[1] = (unsigned char)'M';
	file_header[2] = (unsigned char)(file_size);
	file_header[3] = (unsigned char)(file_size >> 8);
	file_header[4] = (unsigned char)(file_size >> 16);
	file_header[5] = (unsigned char)(file_size >> 24);
	file_header[10] = (unsigned char)(h_size);
	info_header[0] = (unsigned char)(INFO_HEADER_SIZE);
	info_header[4] = (unsigned char)(all->game.r.width);
	info_header[5] = (unsigned char)(all->game.r.width >> 8);
	info_header[6] = (unsigned char)(all->game.r.width >> 16);
	info_header[7] = (unsigned char)(all->game.r.width >> 24);
	info_header[8] = (unsigned char)(all->game.r.height);
	info_header[9] = (unsigned char)(all->game.r.height >> 8);
	info_header[10] = (unsigned char)(all->game.r.height >> 16);
	info_header[11] = (unsigned char)(all->game.r.height >> 24);
	info_header[12] = (unsigned char)1;
	info_header[14] = (unsigned char)(BMP_BPP);
	write(fd, file_header, 14);
	write(fd, info_header, 40);
	ft_write_pixel(fd, all);
	close(fd);
	exit(0);
	return (1);
}
