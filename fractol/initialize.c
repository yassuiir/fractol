/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-nas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 18:17:57 by yait-nas          #+#    #+#             */
/*   Updated: 2024/05/02 13:11:35 by yait-nas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_values(t_fractol *mlx_data, char **argv)
{
	mlx_data->iterations = 100;
	mlx_data->argv = argv;
	mlx_data->ratio = 1;
}

void	initialize(t_fractol *mlx_data, char **argv)
{
	mlx_data->mlx_ptr = mlx_init();
	if (!mlx_data->mlx_ptr)
	{
		free(mlx_data);
		exit(EXIT_FAILURE);
	}
	mlx_data->win = mlx_new_window(mlx_data->mlx_ptr, 800, 800, argv[1]);
	if (!mlx_data->win)
	{
		mlx_destroy_display(mlx_data->mlx_ptr);
		free(mlx_data->mlx_ptr);
		free(mlx_data);
		exit(EXIT_FAILURE);
	}
	mlx_data->img = mlx_new_image(mlx_data->mlx_ptr, 800, 800);
	if (!mlx_data->img)
	{
		mlx_destroy_window(mlx_data->mlx_ptr, mlx_data->win);
		mlx_destroy_display(mlx_data->mlx_ptr);
		free(mlx_data->mlx_ptr);
		free(mlx_data);
		exit(EXIT_FAILURE);
	}
	init_values(mlx_data, argv);
}
