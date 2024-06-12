/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5-rendering_mandelbrot.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleitas <bfleitas@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 01:38:58 by bfleitas          #+#    #+#             */
/*   Updated: 2024/06/13 01:07:02 by bfleitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "1-fractol.h"

void    put_pixel_buffer(t_fractal *fractal, int x, int y, int color)
{
    int    *dst;

    dst = (y * fractal->image.line_length + x * (fractal->image.bits_per_pixel / 8));
    *(unsigned int *)(img->pixels_ptr + dst) = color;
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
    c.real = scale(x, -2, 2, WIDTH);
    c.imaginary = scale(y, 2, -2, HEIGHT);
    while (i < fractal->max_iter )
    {
        z = sum(square(z), c);
        if ((z.real * z.real + z.imaginary * z.imaginary) < fractal->escape_value)
		{
			color = map(i, 0xFFFFFF, 0X000000, 0, fractal->max_iter);
			my_pixel_put(x, y, &fractal->img, color);
			return ;
		}
        i++;
    }
    my_pixel_put(x, y, &fractal->img, 0x000000);
}

void   rendering_mandelbrot(t_fractal *fractal)
{
    int x;
    int y;

    x = 0;
    y = 0;
    while (y < HEIGHT)
    {
        while (x < WIDTH)
        {
            put_in_buffer_mandelbrot(x, y, fractal);
            x++;
        }
        x = 0;
        y++;
    }
    mlx_put_image_to_window(fractal->mlx, fractal->window, fractal->image.image, 0, 0);
}
