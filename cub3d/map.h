/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooz <ozomerfaruk009@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 15:22:56 by ysay              #+#    #+#             */
/*   Updated: 2022/04/24 18:19:27 by ooz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H
# include <tool.h>
# include <fcntl.h>

typedef struct s_pixel
{
	int	o;
	int	r;
	int	g;
	int	b;
	int	f;
}	t_pixel;

typedef struct s_map
{
	char	**data;
	char	*no;
	char	*so;
	char	*ea;
	char	*we;
	int		x;
	int		y;
	float	ang;
	t_pixel	f;
	t_pixel	c;
}	t_map;

int		kill_map(t_map *map);
int		check_map(t_map *map, char *s, char *s2);
int		check_wall(t_map *map, char ch);
t_map	*init_map(int fd);
t_map	*create_map(char *av);

char	*give_str( char *cmp, char	*s);
int		clear_pixel(char *s);
int		give_pixel(t_pixel *p, char *cmp, char *s);
int		get_param(t_map *map, int fd, char *s);
int		my_get_map(t_map *map, int fd);

// tool.c
void	get_pos(t_map *map);
#endif
