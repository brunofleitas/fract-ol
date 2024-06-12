/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5-rendering_mandelbrot.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleitas <bfleitas@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 01:38:58 by bfleitas          #+#    #+#             */
/*   Updated: 2024/06/12 03:11:55 by bfleitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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

    z.real = 0;
    z.imaginary = 0;
    i = 0;
    c.real = scale(x, -2, 2, WIDTH);
    c.imaginary = scale(y, 2, -2, HEIGHT);
    while (i < fractal->max_iter && (z.real * z.real + z.imaginary * z.imaginary) < fractal->scape_radius)
    {
        z = sum(square(z), c);
        i++;
    }
    if (i == fractal->max_iter)
        put_pixel_buffer(fractal, x, y, 0x000000);
    else
        put_pixel_buffer(fractal, x, y, 0xFFFFFF);
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
            put_in_buffer(x, y, fractal);
            x++;
        }
        x = 0;
        y++;
    }
    mlx_put_image_to_window(fractal->mlx, fractal->window, fractal->image.image, 0, 0);
}
