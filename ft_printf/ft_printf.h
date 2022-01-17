/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooz <ozomerfaruk009@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 16:33:46 by ooz               #+#    #+#             */
/*   Updated: 2022/01/14 18:26:39 by ooz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "libft/libft.h"

int		ft_printf(const char *str, ...);
void	ft_putstrxxx(char *s, int *x);
void	ft_putcharxxx(char c, int *x);
void	ft_putnbrxxx(int n, int *x);
#endif
