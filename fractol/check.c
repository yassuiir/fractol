/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-nas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 10:00:13 by yait-nas          #+#    #+#             */
/*   Updated: 2024/05/03 15:47:24 by yait-nas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	check_argument(char *str, int points)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) || str[i] == ' ' || str[i] == '.'
			|| str[i] == '+' || str[i] == '-')
		{
			if (str[i] == '+' || str[i] == '-')
				if ((i && str[i - 1] != ' ') || !ft_isdigit(str[i + 1]))
					return (0);
			if (str[i] == '.')
			{
				if (!i || !ft_isdigit(str[i - 1]) || !ft_isdigit(str[i + 1]))
					return (0);
				points++;
			}
		}
		else
			return (0);
		if (points > 1)
			return (0);
		i++;
	}
	return (1);
}

int	check(char **argv)
{
	int	points;

	points = 0;
	if (check_argument(argv[2], points) && check_argument(argv[3], points))
		return (1);
	return (0);
}
