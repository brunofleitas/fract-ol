/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5-rendering_mandelbrot.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleitas <bfleitas@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 01:38:58 by bfleitas          #+#    #+#             */
/*   Updated: 2024/06/13 21:45:37 by bfleitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "1-fractol.h"

void    put_pixel_buffer(t_fractal *fractal, int x, int y, int color)
{
    char    *dst;

    dst = fractal->image.address + (y * fractal->image.line_length + x * (fractal->image.bits_per_pixel / 8));
    *(unsigned int *)dst = color;
} 

void    put_in_buffer_mandelbrot(int x, int y, t_fractal *fractal)
{
    t_complex   c;
    t_complex   z;
    int         i;
    int        color;

    z.real = 0;
    z.imaginary = 0;
    i = 0;
    c.real = scale(x, -2, 2, WIDTH) * fractal->events.mouse_roll + fractal->events.left_right_x;
    c.imaginary = scale(y, 2, -2, HEIGHT) * fractal->events.mouse_roll + fractal->events.up_down_y;
    while (i < fractal->max_iter )
    {
        z = sum(square(z), c);
        if ((z.real * z.real + z.imaginary * z.imaginary) > fractal->scape_radius)
		{
			color = scale(i, 0xFFFFFF, 0X000000, fractal->max_iter);
			put_pixel_buffer(fractal, x, y, color);
			return ;
		}
        i++;
    }
    put_pixel_buffer(fractal, x, y, 0X000000);
}

void   rendering_fractal(t_fractal *fractal)
{
    int x;
    int y;

    x = 0;
    y = 0;
    while (y < HEIGHT)
    {
        while (x < WIDTH)
        {
            if (fractal->name == "Mandelbrot")
                put_in_buffer_mandelbrot(x, y, fractal);
            else if (fractal->name == "Julia")
                put_in_buffer_julia(x, y, fractal);
            x++;
        }
        x = 0;
        y++;
    }
    mlx_put_image_to_window(fractal->mlx, fractal->window, fractal->image.image, 0, 0);
}
