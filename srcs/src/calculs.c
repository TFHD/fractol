/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabartho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 12:46:06 by sabartho          #+#    #+#             */
/*   Updated: 2024/11/10 16:22:49 by sabartho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandelbrot(t_mlx *app)
{
	int			n;
	t_complex	*cpl;

	cpl = malloc(sizeof(t_complex));
	if (!cpl)
		return ;
	cpl->x = 0;
	cpl->y = 0;
	while (cpl->y < HEIGHT)
	{
		while (cpl->x < WIDTH)
		{
			choose_fractol(cpl, app);
			n = 0;
			while ((cpl->xn * cpl->xn + cpl->yn * cpl->yn) < 4
				&& n++ < app->iteration)
				fractals_calc(app, cpl);
			cpl->x += app->pixel_print;
			print_pixels(app, cpl->x, cpl->y, n);
		}
		cpl->x = 0;
		cpl->y += 1;
	}
	free(cpl);
}

void	mandelbrot_calc(t_mlx *app, t_complex *cpl)
{
	int	ar_width;
	int	ar_height;

	ar_width = 1;
	ar_height = 1;
	if (WIDTH > HEIGHT)
		ar_width = WIDTH / HEIGHT;
	else
		ar_height = HEIGHT / WIDTH;
	cpl->xn = app->cx_custom;
	cpl->yn = app->cy_custom;
	cpl->cx = ((app->x_min + ((float)cpl->x / WIDTH)
				* (app->x_max - app->x_min))) * ar_width;
	cpl->cy = ((app->y_min + ((float)cpl->y / HEIGHT)
				* (app->y_max - app->y_min))) * ar_height;
}

void	julia(t_mlx *app, t_complex *cpl)
{
	int	ar_width;
	int	ar_height;

	ar_width = 1;
	ar_height = 1;
	if (WIDTH > HEIGHT)
		ar_width = WIDTH / HEIGHT;
	else
		ar_height = HEIGHT / WIDTH;
	cpl->xn = ((app->x_min + ((float)cpl->x / WIDTH)
				* (app->x_max - app->x_min))) * ar_width;
	cpl->yn = ((app->y_min + ((float)cpl->y / HEIGHT)
				* (app->y_max - app->y_min))) * ar_height;
	if (app->cx_custom || app->cy_custom)
	{
		cpl->cx = app->cx_custom;
		cpl->cy = app->cy_custom;
	}
	else
	{
		cpl->cx = 0.285;
		cpl->cy = 0.01;
	}
}

void	choose_fractol(t_complex *cpl, t_mlx *app)
{
	if (app->id == 0)
		julia(app, cpl);
	else if (app->id == 1)
		mandelbrot_calc(app, cpl);
}

void	fractals_calc(t_mlx *app, t_complex *cpl)
{
	float	tmp_x;

	if (app->id == 2)
	{
		tmp_x = cpl->xn * cpl->xn - cpl->yn * cpl->yn + cpl->cx;
		cpl->yn = fabsf(2 * cpl->xn * cpl->yn) + cpl->cy;
		cpl->xn = tmp_x;
	}
	else
	{
		tmp_x = cpl->xn;
		cpl->xn = cpl->xn * cpl->xn - cpl->yn * cpl->yn + cpl->cx;
		cpl->yn = 2 * tmp_x * cpl->yn + cpl->cy;
	}
}
