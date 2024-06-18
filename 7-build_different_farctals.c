/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6-build_different_farctals.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleitas <bfleitas@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 01:31:21 by bfleitas          #+#    #+#             */
/*   Updated: 2024/06/18 01:56:01 by bfleitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "1-fractol.h"

/*
  Parameters:
	x: The x-coordinate of the pixel being processed.
	y: The y-coordinate of the pixel being processed.
	fractal: A pointer to the fractal structure containing parameters for the
	calculation.
  Description:
	Implements the Mandelbrot set algorithm to calculate the color of a pixel
	in a fractal. It starts with a complex number z=0 and iteratively applies
	the formula z = z^2 + c, where c is a complex number derived from the pixel
	coordinates and mouse interaction events. The iteration stops when the
	magnitude of z exceeds a predefined radius, and the final iteration count
	determines the pixel's color. The function saves the calculated color to
	the buffer for rendering.
*/
void	mandelbrot(int x, int y, t_fractal *fractal)
{
	t_complex	c;
	t_complex	z;
	int			i;
	int			color;

	z.real = 0;
	z.imaginary = 0;
	c.real = scale(x, -2, 2, WIDTH) * fractal->events.mouse_roll
		+ fractal->events.left_right_x;
	c.imaginary = scale(y, 2, -2, HEIGHT) * fractal->events.mouse_roll
		+ fractal->events.up_down_y;
	while (i < fractal->max_iter)
	{
		z = sum(square(z), c);
		if ((z.real * z.real + z.imaginary
				* z.imaginary) > fractal->scape_radius)
		{
			color = scale(i, 0xFFFFFF, 0X000000, fractal->max_iter);
			save_pixel_on_buffer(fractal, x, y, color);
			return ;
		}
		i++;
	}
}

/*
  Parameters:
	x: The x-coordinate of the pixel being processed.
	y: The y-coordinate of the pixel being processed.
	fractal: A pointer to the fractal structure containing parameters for the
	calculation.
  Description:
	Implements the Julia set algorithm to calculate the color of a pixel in a
	fractal. It starts with a complex number z=0 and iteratively applies the
	formula z = z^2 + c, where c is a fixed complex number defined by the
	Julia point. The iteration stops when the magnitude of z exceeds a
	predefined radius, and the final iteration count determines the pixel's
	color. The function saves the calculated color to the buffer for rendering.
*/
void	julia(int x, int y, t_fractal *fractal)
{
	t_complex	c;
	t_complex	z;
	int			i;
	int			color;

	z.real = scale(x, -2, 2, WIDTH) * fractal->events.mouse_roll
		+ fractal->events.left_right_x;
	z.imaginary = scale(y, 2, -2, HEIGHT) * fractal->events.mouse_roll
		+ fractal->events.up_down_y;
	c.real = fractal->juliaPoint.real;
	c.imaginary = fractal->juliaPoint.imaginary;
	while (i < fractal->max_iter)
	{
		z = sum(square(z), c);
		if ((z.real * z.real + z.imaginary
				* z.imaginary) > fractal->scape_radius)
		{
			color = scale(i, 0xFFFFFF, 0X000000, fractal->max_iter);
			save_pixel_on_buffer(fractal, x, y, color);
			return ;
		}
		i++;
	}
}

/*
  Parameters:
	x: The x-coordinate of the pixel being processed.
	y: The y-coordinate of the pixel being processed.
	fractal: A pointer to the fractal structure containing parameters for
	the calculation.
  Description:
	Implements the Burningship algorithm to calculate the color of a pixel
	in a fractal. It starts with a complex number z=0 and iteratively applies
	the formula z = z^2 + c, where c is a complex number derived from the
	pixel coordinates and mouse interaction events. The iteration stops when
	the magnitude of z exceeds a predefined radius, and the final iteration
	count determines the pixel's color. The function saves the calculated
	color to the buffer for rendering.
*/
void	burningship(int x, int y, t_fractal *fractal)
{
	t_complex	c;
	t_complex	z;
	int			i;
	int			color;

	fractal->max_iter = 30;
	z.real = 0;
	z.imaginary = 0;
	c.real = scale(x, 2, -2, WIDTH) * fractal->events.mouse_roll
		+ fractal->events.left_right_x;
	c.imaginary = scale(y, -2, 2, HEIGHT) * fractal->events.mouse_roll
		+ fractal->events.up_down_y;
	while (i < fractal->max_iter)
	{
		z = sum(square_abs(z), c);
		if ((z.real * z.real + z.imaginary
				* z.imaginary) > fractal->scape_radius)
		{
			color = scale(i, 0xFFFFFF, 0X000000, fractal->max_iter);
			save_pixel_on_buffer(fractal, x, y, color);
			return ;
		}
		i++;
	}
}
