/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabartho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 11:44:42 by sabartho          #+#    #+#             */
/*   Updated: 2024/11/06 20:29:39 by sabartho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

void	init_values(t_mlx *mlbx, float *params)
{
	mlbx->width = params[0];
	mlbx->length = params[1];
	mlbx->x_min = params[2];
	mlbx->y_min = params[3];
	mlbx->x_max = params[4];
	mlbx->y_max = params[5];
	mlbx->iteration = params[6];
}

void	print_pixel(t_mlx mlbx, int x, int y, int n)
{
	int	red;
	int	green;
	int	blue;

	red = (n % 10) * (25);
	green = (n % 10) * (25);
	blue = (n % 10) * (25);
	mlx_pixel_put(mlbx.mlx, mlbx.win, x, y, 0xFF000000 | red << 16 | green << 8 | blue);
}

float	get_mouse_caption(int pos_mouse, int win_size)
{
	float	move;

	move = pos_mouse - (win_size / 2);
	move = (move * 2) / (win_size / 2);
	return (move);
}

void mandelbrot(t_mlx mlbx, float zoom, float x_mouse, float y_mouse)
{
	int		x;
	int		y;
	float	cx;
	float	cy;
	float	xn;
	float	yn;
	float	tmp_x;
	float	tmp_y;
	int		n;


	x = 0;
	y = 0;

	float ar = mlbx.width / mlbx.length;
	while (y < mlbx.length)
	{
		while (x < mlbx.width)
		{
			cx = (mlbx.x_min * ar + ((float)x / mlbx.width) * (mlbx.x_max * ar - mlbx.x_min * ar)) / zoom + get_mouse_caption(x_mouse, mlbx.width);
			cy = (mlbx.y_min + ((float)y / mlbx.length) * (mlbx.y_max - mlbx.y_min)) / zoom + get_mouse_caption(y_mouse, mlbx.length);
			xn = 0;
			yn = 0;
			n = 0;
			while ((xn * xn + yn * yn) < 4 && n < mlbx.iteration)
			{
				tmp_x = xn;
				tmp_y = yn;
				xn = tmp_x * tmp_x - tmp_y * tmp_y + cx;
				yn = 2 * tmp_x * yn + cy;
				n++;
			}
			if (n == mlbx.iteration)
				mlx_pixel_put(mlbx.mlx, mlbx.win, x, y, 0);
			else
				print_pixel(mlbx, x, y, n);
			x += 1;
		}
		x = 0;
		y += 1;
	}
}

int	win_event(int event, void *mlx)
{
	if (event == 0)
		mlx_loop_end(mlx);
	return (0);
}

int	key_event(int key, void *params)
{
	t_mlx	*mlbx = (t_mlx *)params;
	if (key == 41)
		mlx_loop_end(mlbx->mlx);
	return (0);
}

int	mouse_event(int event, void *params)
{
	int				x;
	int				y;
	t_mlx			*mlbx = (t_mlx *)params;
	static float 	zoom = 1;

	mlx_clear_window(mlbx->mlx, mlbx->win);
	mlx_mouse_get_pos(mlbx->mlx, &x, &y);
	printf("x : %d\n", x);
	if (event == 1)
	{
		zoom *= 2;
		mandelbrot(*mlbx, zoom, x, y);
	}
	else if (event == 2)
	{
			if (zoom > 1)
				zoom /= 2;
			mandelbrot(*mlbx, zoom, x, y);
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_mlx		mlbx;
	float		*params;

	mlbx.mlx = mlx_init();
	params = ft_parse(ac, av + 1);
	init_values(&mlbx, params);
	mlbx.win = mlx_new_window(mlbx.mlx, mlbx.width, mlbx.length, "Bonjour");
	mandelbrot(mlbx, 1, mlbx.width / 2, mlbx.length / 2);

	mlx_on_event(mlbx.mlx, mlbx.win, MLX_KEYDOWN, key_event, &mlbx);
	mlx_on_event(mlbx.mlx, mlbx.win, MLX_MOUSEWHEEL, mouse_event, &mlbx);
	mlx_on_event(mlbx.mlx, mlbx.win, MLX_WINDOW_EVENT, win_event, mlbx.mlx);
	mlx_loop(mlbx.mlx);
	mlx_destroy_window(mlbx.mlx, mlbx.win);
	mlx_destroy_display(mlbx.mlx);
	return (0);
}
