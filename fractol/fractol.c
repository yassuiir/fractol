/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-nas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 18:34:05 by yait-nas          #+#    #+#             */
/*   Updated: 2024/05/02 13:02:59 by yait-nas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_fractol *mlx_data, int color, int i, int j)
{
	char	*offset;

	offset = mlx_data->address + (j * mlx_data->line_len)
		+ (i * (mlx_data->bpp / 8));
	*(unsigned int *)offset = color;
}

void	mandel_vs_julia(t_complex *z, t_complex *c, t_fractol *mlx_data)
{
	if (!ft_strcmp(mlx_data->argv[1], "Julia"))
	{
		z->real = c->real;
		z->im = c->im;
		c->real = ft_atod(mlx_data->argv[2]);
		c->im = ft_atod(mlx_data->argv[3]);
	}
	else
	{
		z->real = 0.0;
		z->im = 0.0;
	}
}

void	handle_pixel(t_fractol *mlx_data, int i, int j)
{
	t_complex	z;
	t_complex	c;
	int			index;
	int			color;

	index = 0;
	c.real = (scale(i, -2, 2, 800) * mlx_data->ratio);
	c.im = (scale(j, 2, -2, 800) * mlx_data->ratio);
	mandel_vs_julia(&z, &c, mlx_data);
	while (index < mlx_data->iterations)
	{
		z = sum_complex(square_complex(z), c);
		if ((z.real * z.real) + (z.im * z.im) > 4)
		{
			color = scale(index, BLACK, WHITE, 1000000);
			my_mlx_pixel_put(mlx_data, color, i, j);
			return ;
		}
		index++;
	}
	my_mlx_pixel_put(mlx_data, WHITE, i, j);
}

void	fractol(t_fractol *mlx_data)
{
	int	i;
	int	j;

	j = 0;
	while (j < 800)
	{
		i = 0;
		while (i < 800)
		{
			handle_pixel(mlx_data, i, j);
			i++;
		}
		j++;
	}
	mlx_put_image_to_window(mlx_data->mlx_ptr,
		mlx_data->win, mlx_data->img, 0, 0);
}
