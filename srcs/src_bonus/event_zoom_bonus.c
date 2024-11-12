/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_zoom_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabartho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 02:25:57 by sabartho          #+#    #+#             */
/*   Updated: 2024/11/09 04:29:26 by sabartho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

float	get_mouse_caption(int pos_mouse, int win_size)
{
	float	move;

	move = pos_mouse - (win_size / 2);
	move = (move * 2) / (win_size / 2);
	return (move);
}

int	win_event(int event, void *mlx)
{
	if (event == 0)
		mlx_loop_end(mlx);
	return (0);
}

void	ft_move_arrow(int key, t_mlx *mlbx)
{
	mlx_clear_window(mlbx->mlx, mlbx->win);
	if (key == 79 || key == 7)
	{
		mlbx->x_move += 0.1 * mlbx->zoom;
		mandelbrot(mlbx);
	}
	if (key == 80 || key == 4)
	{
		mlbx->x_move -= 0.1 * mlbx->zoom;
		mandelbrot(mlbx);
	}
	if (key == 81 || key == 22)
	{
		mlbx->y_move += 0.1 * mlbx->zoom;
		mandelbrot(mlbx);
	}
	if (key == 82 || key == 26)
	{
		mlbx->y_move -= 0.1 * mlbx->zoom;
		mandelbrot(mlbx);
	}
}

int	key_event(int key, void *params)
{
	t_mlx	*mlbx;

	mlbx = (t_mlx *)params;
	mlx_mouse_get_pos(mlbx->mlx, &mlbx->x_mouse, &mlbx->y_mouse);
	if (key == 41)
		mlx_loop_end(mlbx->mlx);
	if (key == 30)
	{
		mlbx->pixel_print++;
		mlx_clear_window(mlbx->mlx, mlbx->win);
		mandelbrot(mlbx);
	}
	if (key == 31 && mlbx->pixel_print > 1)
	{
		mlbx->pixel_print--;
		mlx_clear_window(mlbx->mlx, mlbx->win);
		mandelbrot(mlbx);
	}
	if ((key >= 79 && key <= 82) || (key >= 4 && key < 30))
		ft_move_arrow(key, mlbx);
	if (key == 225)
		ft_color_shift(mlbx);
	return (0);
}

int	mouse_event(int event, void *params)
{
	t_mlx	*mlbx;

	mlbx = (t_mlx *)params;
	mlx_clear_window(mlbx->mlx, mlbx->win);
	mlx_mouse_get_pos(mlbx->mlx, &mlbx->x_mouse, &mlbx->y_mouse);
	if (event == 2)
	{
		mlbx->x_min *= 2.0;
		mlbx->x_max *= 2.0;
		mlbx->y_min *= 2.0;
		mlbx->y_max *= 2.0;
		mlbx->zoom *= 2.0;
	}
	else if (event == 1)
	{
		mlbx->x_min *= 0.5;
		mlbx->x_max *= 0.5;
		mlbx->y_min *= 0.5;
		mlbx->y_max *= 0.5;
		mlbx->zoom *= 0.5;
	}
	mlbx->x_move += get_mouse_caption(mlbx->x_mouse, WIDTH) * mlbx->zoom;
	mlbx->y_move += get_mouse_caption(mlbx->y_mouse, HEIGHT) * mlbx->zoom;
	mandelbrot(mlbx);
	return (0);
}
