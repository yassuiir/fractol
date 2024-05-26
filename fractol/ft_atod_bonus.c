/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-nas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 21:11:55 by yait-nas          #+#    #+#             */
/*   Updated: 2024/05/01 20:52:06 by yait-nas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	ft_atoi(char *str, int *i, int *sign)
{
	int	result;
	int	j;

	result = 0;
	j = 0;
	while (str[j] == ' ' || (str[j] >= 9 && str[j] <= 13))
		j++;
	if (str[j] == '-' || str[j] == '+')
	{
		if (str[j] == '-')
			*sign = -1;
		j++;
	}
	while (str[j] && str[j] >= '0' && str[j] <= '9')
	{
		result = result * 10 + str[j] - '0';
		j++;
	}
	*i = j;
	return (result);
}

double	ft_atod(char *str)
{
	double	result;
	double	tmp;
	int		i;
	int		sign;

	sign = 1;
	result = 0;
	i = 0;
	tmp = 1;
	result = (double)ft_atoi(str, &i, &sign);
	if (str[i] == '.')
		i++;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		tmp = tmp / 10;
		result = result + (str[i] - '0') * tmp;
		i++;
	}
	return (result * sign);
}
