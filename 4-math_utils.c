/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleitas <bfleitas@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 02:00:23 by bfleitas          #+#    #+#             */
/*   Updated: 2024/06/18 02:01:21 by bfleitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "1-fractol.h"

/*
  Parameters:
    z1: The first complex number to add.
    z2: The second complex number to add.
  Return value:
    A new complex number that is the sum of z1 and z2.
  Description:
    Adds two complex numbers together by adding their real 
	and imaginary components separately.
*/
t_complex	sum(t_complex z1, t_complex z2)
{
	t_complex	temp;

	temp.real = z1.real + z2.real;
	temp.imaginary = z1.imaginary + z2.imaginary;
	return (temp);
}

/*
  Parameters:
    z1: The complex number to square.
  Return value:
    A new complex number that is the square of z1.
  Description:
    Calculates the square of a complex number using the formula:
      (a + bi)^2 = (a^2 - b^2) + 2abi,
    where a is the real part and b is the imaginary part of the complex number.
*/
t_complex	square(t_complex z1)
{
	t_complex	temp;

	temp.real = (z1.real * z1.real) - (z1.imaginary * z1.imaginary);
	temp.imaginary = 2 * (z1.real * z1.imaginary);
	return (temp);
}

/*
  Parameters:
    z1: The complex number whose absolute value square is to be calculated.
  Return value:
    A new complex number representing the square of the absolute value of z1.
  Description:
    Calculates the square of the absolute value of a complex number. First, 
	it computes the absolute values of both the real and imaginary parts of 
	the input complex number. Then, it calculates the square using these 
	absolute values with the formula:
      (|a| + |b|i)^2 = (|a|^2 - |b|^2) + 2|a||b|i,
    where |a| is the absolute value of the real part and |b| is the absolute 
	value of the imaginary part of the complex number.
*/
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
