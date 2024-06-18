/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5-rendering_fractal.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleitas <bfleitas@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 01:38:58 by bfleitas          #+#    #+#             */
/*   Updated: 2024/06/18 01:58:50 by bfleitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "1-fractol.h"

/*
  Parameters:
	input: The value to scale.
	new_min: The minimum value of the new range.
	new_max: The maximum value of the new range.
	old_max: The maximum value of the old range.
  Return value:
	The input value scaled to the new range.
  Description:
	Scales the input value from the old range to the new range.
*/
double	scale(double input, double new_min, double new_max, double old_max)
{
	return (new_min + (new_max - new_min) * ((input) / (old_max)));
}

/*
  Parameters:
	fractal: A pointer to the fractal structure where the pixel will be drawn.
	x: The x-coordinate of the pixel.
	y: The y-coordinate of the pixel.
	color: The color of the pixel.
  Description:
	Saves pixel with the specified color at the given coordinates in the 
	fractal's image buffer.
*/
void	save_pixel_on_buffer(t_fractal *fractal, int x, int y, int color)
{
	char	*dst;

	dst = fractal->image.address + (y * fractal->image.line_length + x
			* (fractal->image.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

/*
  Parameters:
	x: The x-coordinate of the pixel.
	y: The y-coordinate of the pixel.
	fractal: A pointer to the fractal structure that will be rendered.
  Description:
	Calculates the complex number corresponding to the pixel's coordinates 
	and renders the pixel based on the fractal's parameters.
*/
void	put_in_buffer(int x, int y, t_fractal *fractal)
{
	if (ft_strcmp(fractal->name, "mandelbrot") == 0)
		mandelbrot(x, y, fractal);
	if (ft_strcmp(fractal->name, "julia") == 0)
		julia(x, y, fractal);
	if (ft_strcmp(fractal->name, "burningship") == 0)
		burningship(x, y, fractal);
	save_pixel_on_buffer(fractal, x, y, 0X000000);
}

/*
  Parameters:
	fractal: A pointer to the fractal structure that will be rendered.
  Description:
	Renders the fractal by iterating over each pixel in the image and 
	calculating the corresponding complex number based on the pixel's 
	coordinates. It then calculates the color of the pixel based on the 
	complex number and the fractal's parameters.
*/
void	rendering_fractal(t_fractal *fractal)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < HEIGHT)
	{
		while (x < WIDTH)
		{
			put_in_buffer(x, y, fractal);
			x++;
		}
		x = 0;
		y++;
	}
	mlx_put_image_to_window(fractal->mlx, fractal->window, fractal->image.image,
		0, 0);
}
