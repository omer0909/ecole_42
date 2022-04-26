/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooz <ozomerfaruk009@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 12:41:03 by ysay              #+#    #+#             */
/*   Updated: 2022/04/24 18:01:46 by ooz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMAGE_H
# define IMAGE_H
# include <unistd.h>
# include <libft.h>
# include <mlx.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct s_image
{
	void	*obj;
	void	*data;
	void	*addr;
	void	*win;
	int		width;
	int		height;
	int		bit_pp;
	int		l_len;
	int		endian;
}	t_image;

typedef struct s_images
{
	int		img_s;
	t_image	*img[];
}	t_images;

int			kill_images(t_images *imgs);
int			kill_image(t_image *img);
t_images	*take_images(void *init, char **path);
t_image		*take_image(void *init, char *path);
t_image		*take_new_window(void *init, char *name, int width, int height);

#endif
