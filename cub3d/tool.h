/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysay <ysay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 12:41:03 by ysay              #+#    #+#             */
/*   Updated: 2022/02/08 19:04:48 by ysay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOOL_H
# define TOOL_H
# include <libft.h>
# include <map.h>

int		kill_arg(char **arg);
char	*join_and_free(char *s1, char *s2);
int		my_get_line(int fd, char **str, int f);

#endif
