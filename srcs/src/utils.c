/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabartho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 02:28:54 by sabartho          #+#    #+#             */
/*   Updated: 2024/11/10 12:00:10 by sabartho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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

void	init_values(t_mlx *app, float *params, int ac)
{
	app->x_min = -2;
	app->y_min = -2;
	app->x_max = 2;
	app->y_max = 2;
	app->pixel_print = 1;
	app->zoom = 1;
	if (ac == 4)
	{
		app->cx_custom = params[0];
		app->cy_custom = params[1];
	}
	else
	{
		app->cx_custom = 0;
		app->cy_custom = 0;
	}
	app->iteration = ITERATION;
}

int	set_id(char *str)
{
	if (ft_strcmp("julia", str) == 0)
		return (0);
	else if (ft_strcmp("mandelbrot", str) == 0)
		return (1);
	return (-1);
}
