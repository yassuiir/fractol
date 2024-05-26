/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-nas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 18:57:00 by yait-nas          #+#    #+#             */
/*   Updated: 2024/05/02 21:46:07 by yait-nas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	destroy(t_fractol *mlx_data)
{
	mlx_destroy_image(mlx_data->mlx_ptr, mlx_data->img);
	mlx_destroy_window(mlx_data->mlx_ptr, mlx_data->win);
	mlx_destroy_display(mlx_data->mlx_ptr);
	free(mlx_data->mlx_ptr);
	free(mlx_data);
	exit(EXIT_SUCCESS);
}

void	in_de_crease_display_iterations(t_fractol *mlx_data, char c)
{
	if (c == '+')
		mlx_data->iterations += 10;
	else
		mlx_data->iterations -= 10;
	ft_putnbr(mlx_data->iterations);
	write (1, " itarations\n", 12);
}

int	keyboard_handler(int keycode, t_fractol *mlx_data)
{
	if (keycode == 65307)
		return (destroy(mlx_data));
	else if (keycode == 65451)
		in_de_crease_display_iterations(mlx_data, '+');
	else if (keycode == 65453)
		in_de_crease_display_iterations(mlx_data, '-');
	else if (keycode == 65363)
		mlx_data -> shift_x += (0.5 * mlx_data->ratio);
	else if (keycode == 65361)
		mlx_data -> shift_x -= (0.5 * mlx_data->ratio);
	else if (keycode == 65362)
		mlx_data -> shift_y -= (0.5 * mlx_data->ratio);
	else if (keycode == 65364)
		mlx_data -> shift_y += (0.5 * mlx_data->ratio);
	else if (keycode == 65505)
	{
		mlx_data->depends = mlx_data->iterations;
		mlx_data->iterations += 10;
	}
	else if (keycode == 117)
		mlx_data->depends = 1000000;
	fractol(mlx_data);
	return (0);
}

int	mouse_handler(int botton, int x, int y, t_fractol *mlx_data)
{
	double	mouse_x;
	double	mouse_y;
	double	factor;

	if (botton == 5 || botton == 4)
	{
		factor = 0;
		if (botton == 5)
			factor = 0.95;
		else if (botton == 4)
			factor = 1.05;
		mouse_x = scale(x, -2, 2, 800) * factor + mlx_data->shift_x;
		mouse_y = scale(y, -2, 2, 800) * factor + mlx_data->shift_y;
		mlx_data->shift_x = mouse_x - (mouse_x - mlx_data->shift_x) * factor;
		mlx_data->shift_y = mouse_y - (mouse_y - mlx_data->shift_y) * factor;
		mlx_data->ratio *= factor;
		fractol(mlx_data);
	}
	return (0);
}
