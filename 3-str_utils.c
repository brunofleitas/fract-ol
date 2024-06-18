/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3-str_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleitas <bfleitas@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 00:08:54 by bfleitas          #+#    #+#             */
/*   Updated: 2024/06/18 02:01:26 by bfleitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "1-fractol.h"

//CAMBIAR CON ORIGINAL
int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

//CAMBIAR CON ORIGINAL
void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

//CAMBIAR CON ORIGINAL
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
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i] && str[i] != '.')
	{
		integer = integer * 10 + (str[i] - '0');
		i++;
	}
	if (str[i] == '.')
		i++;
	while (str[i])
	{
		power = power / 10;
		decimal = decimal + (str[i] - '0') * power;
		i++;
	}
	return ((integer + decimal) * sign);
}
