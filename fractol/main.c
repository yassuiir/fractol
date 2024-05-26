/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-nas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 16:42:42 by yait-nas          #+#    #+#             */
/*   Updated: 2024/05/03 23:03:31 by yait-nas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_fractol	*mlx_data;
	int			endian;

	if ((argc == 2 && !ft_strcmp(argv[1], "Mandelbrot"))
		|| (argc == 4 && !ft_strcmp(argv[1], "Julia") && check(argv)))
	{
		mlx_data = malloc(sizeof(t_fractol));
		if (!mlx_data)
			return (1);
		initialize(mlx_data, argv);
		mlx_data->address = mlx_get_data_addr(mlx_data->img, &(mlx_data->bpp),
				&(mlx_data->line_len), &endian);
		fractol(mlx_data);
		mlx_key_hook(mlx_data->win, keyboard_handler, mlx_data);
		mlx_hook(mlx_data->win, 4, 4, mouse_handler, mlx_data);
		mlx_hook(mlx_data->win, 17, 1, destroy, mlx_data);
		mlx_loop(mlx_data->mlx_ptr);
	}
	else
	{
		write(1, "Please follow the ordre : \n", 27);
		write(1, "\tMandelbrot\n", 12);
		write(1, "\tJulia <real> <imaginary>\n", 26);
	}
}
