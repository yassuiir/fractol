/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-nas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 18:57:00 by yait-nas          #+#    #+#             */
/*   Updated: 2024/05/02 13:02:22 by yait-nas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
	fractol(mlx_data);
	return (0);
}

int	mouse_handler(int botton, int x, int y, t_fractol *mlx_data)
{
	(void)x;
	(void)y;
	if (botton == 5)
		mlx_data -> ratio = mlx_data -> ratio * 0.95;
	else if (botton == 4)
		mlx_data -> ratio = mlx_data -> ratio * 1.05;
	fractol(mlx_data);
	return (0);
}
