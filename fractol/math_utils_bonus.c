/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-nas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 09:33:56 by yait-nas          #+#    #+#             */
/*   Updated: 2024/05/02 18:43:35 by yait-nas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

double	scale(double x, double a, double b, double max)
{
	return ((x - 0) * (b - a) / (max - 0) + a);
}

t_complex	sum_complex(t_complex z1, t_complex z2)
{
	t_complex	result;

	result.real = z1.real + z2.real;
	result.im = z1.im + z2.im;
	return (result);
}

t_complex	square_complex(t_complex z, char **argv)
{
	t_complex	result;

	if (!ft_strcmp(argv[1], "Burning ship"))
	{
		result.real = fabs(z.real * z.real) - fabs(z.im * z.im);
		result.im = -2 * fabs(z.real * z.im);
	}
	else
	{
		result.real = (z.real * z.real) - (z.im * z.im);
		result.im = 2 * z.real * z.im;
	}
	return (result);
}
