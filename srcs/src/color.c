/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabartho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 02:25:47 by sabartho          #+#    #+#             */
/*   Updated: 2024/11/10 16:18:59 by sabartho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	print_pixels(t_mlx *app, int x, int y, int n)
{
	int		red;
	int		green;
	int		blue;
	int		tmp_pxl;
	float	v;

	if (n == app->iteration + 1)
	{
		mlx_pixel_put(app->mlx, app->win, x, y, 0);
		return ;
	}
	v = powf(n / (float)150.0 + 0.6, 2.0);
	red = v * (75);
	green = v * (40);
	blue = v * (255);
	tmp_pxl = app->pixel_print;
	while (tmp_pxl-- >= 0)
		mlx_pixel_put(app->mlx, app->win, x - tmp_pxl, y, 0xFF000000
			| red << 16 | green << 8 | blue);
}
