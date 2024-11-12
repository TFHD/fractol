/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabartho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 02:28:54 by sabartho          #+#    #+#             */
/*   Updated: 2024/11/10 12:00:10 by sabartho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned int	i;

	i = 0;
	while ((unsigned char)s1[i] || (unsigned char)s2[i])
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

void	init_values(t_mlx *mlbx, float *params, int ac)
{
	mlbx->x_min = -2;
	mlbx->y_min = -2;
	mlbx->x_max = 2;
	mlbx->y_max = 2;
	mlbx->x_move = 0;
	mlbx->y_move = 0;
	mlbx->color = 6;
	mlbx->pixel_print = 1;
	mlbx->zoom = 1;
	mlbx->x_mouse = WIDTH * 0.5;
	mlbx->y_mouse = HEIGHT * 0.5;
	if (ac == 4)
	{
		mlbx->cx_custom = params[0];
		mlbx->cy_custom = params[1];
	}
	else
	{
		mlbx->cx_custom = 0;
		mlbx->cy_custom = 0;
	}
	mlbx->iteration = ITERATION;
}

int	set_id(char *str)
{
	if (ft_strcmp("julia", str) == 0)
		return (0);
	else if (ft_strcmp("mandelbrot", str) == 0)
		return (1);
	else if (ft_strcmp("burning-ship", str) == 0)
		return (2);
	return (-1);
}
