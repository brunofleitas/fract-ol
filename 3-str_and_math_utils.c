/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3-str_and_math_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleitas <bfleitas@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 00:08:54 by bfleitas          #+#    #+#             */
/*   Updated: 2024/06/14 16:04:53 by bfleitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "1-fractol.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

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

t_complex	sum(t_complex z1, t_complex z2)
{
	t_complex	temp;

	temp.real = z1.real + z2.real;
	temp.imaginary = z1.imaginary + z2.imaginary;
	return (temp);
}

t_complex	square(t_complex z1)
{
	t_complex	temp;

	temp.real = (z1.real * z1.real) - (z1.imaginary * z1.imaginary);
	temp.imaginary = 2 * (z1.real * z1.imaginary);
	return (temp);
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

t_complex	square_abs(t_complex z1)
{
	t_complex	abs;
	t_complex	temp;

	if (z1.real < 0)
		abs.real = -z1.real;
	else
		abs.real = z1.real;
	if (z1.imaginary < 0)
		abs.imaginary = -z1.imaginary;
	else
		abs.imaginary = z1.imaginary;
	temp.real = (abs.real * abs.real) - (abs.imaginary * abs.imaginary);
	temp.imaginary = 2 * (abs.real * abs.imaginary);
	return (temp);
}

