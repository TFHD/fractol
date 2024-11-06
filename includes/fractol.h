/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabartho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 12:08:15 by sabartho          #+#    #+#             */
/*   Updated: 2024/11/06 12:58:02 by sabartho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

typedef struct	s_mlx
{
	void		*mlx;
	void		*win;
	int			width;
	int			length;
	float		x_min;
	float		y_min;
	float		x_max;
	float		y_max;
	int			iteration;
}				t_mlx;

# include "../srcs/MacroLibX/includes/mlx.h"
# include <stdlib.h>
# include <stdio.h>

float	*ft_parse(int ac, char **av);

#endif
