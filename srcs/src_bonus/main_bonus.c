/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabartho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 11:44:42 by sabartho          #+#    #+#             */
/*   Updated: 2024/11/10 12:45:48 by sabartho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	error_manager(t_mlx *app, float *params, int ac, int is_params)
{
	if (!app)
	{
		ft_printf("Malloc Error !");
		return (0);
	}
	if (is_params || (ac < 2 || ac > 4))
	{
		if (!params || app->id == -1)
		{
			ft_printf("Use this format :");
			ft_printf(" ./fractol <fractol_name> <Cx> <Cy>\n");
			ft_printf("Fractol name :\n1) mandelbrot\n2) julia\n");
			ft_printf("3) burning-ship\n");
			free(app);
			free(params);
			return (0);
		}
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_mlx		*app;
	float		*params;

	app = malloc(sizeof(t_mlx));
	if (!error_manager(app, NULL, ac, 0))
		return (0);
	params = ft_parse(ac, av + 2);
	init_values(app, params, ac);
	app->id = set_id(av[1]);
	if (!error_manager(app, params, ac, 1))
		return (0);
	app->mlx = mlx_init();
	mlx_set_fps_goal(app->mlx, FPS);
	app->win = mlx_new_window(app->mlx, WIDTH, HEIGHT, "Fractol Bonus");
	mandelbrot(app);
	mlx_on_event(app->mlx, app->win, MLX_KEYDOWN, key_event, app);
	mlx_on_event(app->mlx, app->win, MLX_MOUSEWHEEL, mouse_event, app);
	mlx_on_event(app->mlx, app->win, MLX_WINDOW_EVENT, win_event, app->mlx);
	mlx_loop(app->mlx);
	mlx_clear_window(app->mlx, app->win);
	mlx_destroy_window(app->mlx, app->win);
	mlx_destroy_display(app->mlx);
	free(params);
	free(app);
	return (0);
}
