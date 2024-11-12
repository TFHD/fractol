/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabartho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 19:41:21 by sabartho          #+#    #+#             */
/*   Updated: 2024/11/10 19:41:25 by sabartho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_BONUS_H
# define FRACTOL_BONUS_H

# define FPS 120
# define WIDTH 1000
# define HEIGHT 800
# define ITERATION 150

# include "../srcs/MacroLibX/includes/mlx.h"
# include "../srcs/ft_printf/ft_printf.h"
# include <stdlib.h>
# include <math.h>

typedef struct s_mlx
{
	int		id;
	void	*mlx;
	void	*win;
	int		x_mouse;
	int		y_mouse;
	float	x_move;
	float	y_move;
	float	zoom;
	int		color;
	float	x_min;
	float	y_min;
	float	x_max;
	float	y_max;
	float	cx_custom;
	float	cy_custom;
	int		pixel_print;
	int		iteration;
}			t_mlx;

typedef struct s_complex
{
	int		x;
	int		y;
	float	cx;
	float	cy;
	float	xn;
	float	yn;
}			t_complex;

float	*ft_parse(int ac, char **av);
void	mandelbrot(t_mlx *app);
void	fractals_calc(t_mlx *app, t_complex *cpl);
void	choose_fractol(t_complex *cpl, t_mlx *app);
float	get_mouse_caption(int pos_mouse, int win_size);
int		win_event(int event, void *mlx);
void	ft_move_arrow(int key, t_mlx *app);
int		key_event(int key, void *params);
int		mouse_event(int event, void *params);
void	ft_color_shift(t_mlx *app);
void	print_pixels(t_mlx *app, int x, int y, int n);
int		set_id(char *str);
void	init_values(t_mlx *app, float *params, int ac);
int		ft_strcmp(const char *s1, const char *s2);
void	mandelbrot(t_mlx *app);
void	julia(t_mlx *app, t_complex *cpl);
void	mandelbrot_burning_ship(t_mlx *app, t_complex *cpl);

#endif
