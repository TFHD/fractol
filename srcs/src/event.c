/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabartho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 02:25:57 by sabartho          #+#    #+#             */
/*   Updated: 2024/11/09 04:29:26 by sabartho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	win_event(int event, void *mlx)
{
	if (event == 0)
		mlx_loop_end(mlx);
	return (0);
}

int	key_event(int key, void *params)
{
	t_mlx	*app;

	app = (t_mlx *)params;
	if (key == 41)
		mlx_loop_end(app->mlx);
	if (key == 30)
	{
		app->pixel_print++;
		mlx_clear_window(app->mlx, app->win);
		mandelbrot(app);
	}
	if (key == 31 && app->pixel_print > 1)
	{
		app->pixel_print--;
		mlx_clear_window(app->mlx, app->win);
		mandelbrot(app);
	}
	return (0);
}

int	mouse_event(int event, void *params)
{
	t_mlx	*app;

	app = (t_mlx *)params;
	mlx_clear_window(app->mlx, app->win);
	if (event == 2)
	{
		app->x_min *= 2.0;
		app->x_max *= 2.0;
		app->y_min *= 2.0;
		app->y_max *= 2.0;
		app->zoom *= 2.0;
	}
	else if (event == 1)
	{
		app->x_min *= 0.5;
		app->x_max *= 0.5;
		app->y_min *= 0.5;
		app->y_max *= 0.5;
		app->zoom *= 0.5;
	}
	mandelbrot(app);
	return (0);
}
