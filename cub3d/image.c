/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysay <ysay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 11:43:39 by ysay              #+#    #+#             */
/*   Updated: 2022/02/08 19:06:09 by ysay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <image.h>

int	kill_images(t_images *imgs)
{
	int	i;

	i = 0;
	if (!imgs)
		return (0);
	while (i < imgs->img_s)
	{
		if (imgs->img[i])
			kill_image(imgs->img[i]);
		imgs->img[i] = 0;
		i++;
	}
	free(imgs);
	return (1);
}

int	kill_image(t_image *img)
{
	if (!img)
		return (0);
	if (!img->obj)
		return (0);
	if (img->data)
		mlx_destroy_image(img->obj, img->data);
	else if (img->win)
		mlx_destroy_window(img->obj, img->win);
	else
		return (0);
	free(img);
	return (1);
}

t_images	*take_images(void *init, char **path)
{
	int			i;
	t_images	*imgs;

	i = 0;
	if (!path)
		return (NULL);
	while (path[i])
		i++;
	if (!i)
		return (NULL);
	imgs = ft_calloc(sizeof(t_images) + (sizeof(t_image *) * i), 1);
	imgs->img_s = i;
	i = 0;
	while (i < imgs->img_s)
	{
		imgs->img[i] = take_image(init, path[i]);
		if (!imgs->img[i])
		{
			perror(path[i]);
			kill_images(imgs);
			return (NULL);
		}
		i++;
	}
	return (imgs);
}

t_image	*take_image(void *init, char *path)
{
	t_image	*img;

	if (!path)
		return (NULL);
	img = ft_calloc(sizeof(t_image), 1);
	if (!img)
		return (NULL);
	img->obj = init;
	img->data = mlx_xpm_file_to_image(img->obj, path,
			&img->width, &img->height);
	if (!img->data)
	{
		kill_image(img);
		return (0);
	}
	img->addr = mlx_get_data_addr(img->data, &img->bit_pp,
			&img->l_len, &img->endian);
	if (!img->addr)
	{
		kill_image(img);
		return (0);
	}
	return (img);
}

t_image	*take_new_window(void *init, char *name, int width, int height)
{
	t_image	*img;

	img = ft_calloc(sizeof(t_image), 1);
	if (!img)
		return (0);
	img->obj = init;
	img->win = mlx_new_window(img->obj, width, height, name);
	return (img);
}
