/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3-str_and_math_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleitas <bfleitas@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 00:08:54 by bfleitas          #+#    #+#             */
/*   Updated: 2024/06/14 02:52:37 by bfleitas         ###   ########.fr       */
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
/*
unsigned long long	factorial(int n)
{
	unsigned long long	fact;
	int					i;

	if (n == 0)
		return (1);
	else
	{
		fact = 1;
		i = 1;
		while (i <= n)
		{
			fact *= i;
			i++;
		}
		return (fact);
	}
}

double	exponential(double x)
{
	int	n;
	int terms;

	double result = 1.0;
	double power = 1.0; 
	n = 1;
	terms = 15;
	while (n < terms)
	{
		power *= x; 
		result += power / factorial(n);
		n++;
	}
	return (result);
}*/

t_complex	cube(t_complex z1)
{
	t_complex	tempsquare;
	t_complex	temp;

	tempsquare = square(z1);
	temp.real = (tempsquare.real * tempsquare.real) - (tempsquare.imaginary * tempsquare.imaginary);
	temp.imaginary = 2 * (tempsquare.real * tempsquare.imaginary);
	return (temp);
}

t_complex	four(t_complex z1)
{
	t_complex	tempsquare;
	t_complex	temp;

	tempsquare = cube(z1);
	temp.real = (tempsquare.real * tempsquare.real) - (tempsquare.imaginary * tempsquare.imaginary);
	temp.imaginary = 2 * (tempsquare.real * tempsquare.imaginary);
	return (temp);
}

t_complex	five(t_complex z1)
{
	t_complex	tempsquare;
	t_complex	temp;

	tempsquare = four(z1);
	temp.real = (tempsquare.real * tempsquare.real) - (tempsquare.imaginary * tempsquare.imaginary);
	temp.imaginary = 2 * (tempsquare.real * tempsquare.imaginary);
	return (temp);
}
t_complex	six(t_complex z1)
{
	t_complex	tempsquare;
	t_complex	temp;

	tempsquare = five(z1);
	temp.real = (tempsquare.real * tempsquare.real) - (tempsquare.imaginary * tempsquare.imaginary);
	temp.imaginary = 2 * (tempsquare.real * tempsquare.imaginary);
	return (temp);
}
/*
t_complex divide(t_complex a, t_complex b) 
{
    t_complex result;
	double denominador;

    denominador = b.real * b.real + b.imaginary * b.imaginary;
    result.real = (a.real * b.real + a.imaginary * b.imaginary) / denominador;
    result.imaginary = (a.imaginary * b.real - a.real * b.imaginary) / denominador;
    return (result);
}

t_complex complex_multiply(t_complex a, t_complex b)
{
    t_complex result;
    result.real = a.real * b.real - a.imaginary * b.imaginary;
    result.imaginary = a.real * b.imaginary + a.imaginary * b.real;
    return result;
}

t_complex complex_add(t_complex a, t_complex b) {
    t_complex result;
    result.real = a.real + b.real;
    result.imaginary = a.imaginary + b.imaginary;
    return result;
}

t_complex complex_exponential(t_complex z) {
    int n, terms;
    t_complex result;
    t_complex power;

    result.real = 1.0;
    result.imaginary = 0.0;
    power.real = 1.0;
    power.imaginary = 0.0;
    n = 1;
    terms = 15;
    while (n < terms) {
        power = complex_multiply(power, z);
        t_complex term;
        term.real = power.real / factorial(n);
        term.imaginary = power.imaginary / factorial(n);
        result = complex_add(result, term);
        n++;
    }

    return result;
}*/
