/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_mandelbrot.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleitas <bfleitas@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 01:38:58 by bfleitas          #+#    #+#             */
/*   Updated: 2024/06/12 02:17:30 by bfleitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double scale(double input, double new_min, double new_max, double old_max)
{
    return (new_min + (new_max - new_min) * ((input) / (old_max)));
}

void    put_in_buffer(int x, int y, t_fractal *fractal)
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
        my_mlx_pixel_put(&fractal->image, x, y, 0x000000);
    else
        my_mlx_pixel_put(&fractal->image, x, y, 0xFFFFFF);
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
