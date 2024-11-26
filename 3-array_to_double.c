/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3-array_to_double.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleitas <bfleitas@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 10:53:37 by bfleitas          #+#    #+#             */
/*   Updated: 2024/06/18 11:24:09 by bfleitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	generate_integer(int *i, char *str, double *integer)
{
	while (str[*i] && str[*i] != '.')
	{
		if ((str[*i] >= '0' && str[*i] <= '9'))
			*integer = *integer * 10 + (str[*i] - '0');
		(*i)++;
	}
}

void	generate_decimal(int *i, char *str, double *power, double *decimal)
{
	while (str[*i])
	{
		if ((str[*i] >= '0' && str[*i] <= '9'))
		{
			*power = *power / 10;
			*decimal = *decimal + (str[*i] - '0') * *power;
		}
		(*i)++;
	}
}

double	array_to_double(char *str)
{
	double	integer;
	int		i;
	int		sign;
	double	power;
	double	decimal;

	i = 0;
	sign = 1;
	integer = 0;
	decimal = 0;
	power = 1;
	while (str[i] != 0 && ((str[i] == ' ')
			|| (str[i] >= 9 && str[i] <= 13)))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	generate_integer(&i, str, &integer);
	if (str[i] == '.')
		i++;
	generate_decimal(&i, str, &power, &decimal);
	return ((integer + decimal) * sign);
}








