/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6-rendering_julia.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleitas <bfleitas@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 02:55:28 by bfleitas          #+#    #+#             */
/*   Updated: 2024/06/12 03:13:39 by bfleitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


void    put_in_buffer(int x, int y, t_fractal *fractal, t_complex julia)
{
    t_complex   c;
    t_complex   z;
    int         i;

    z.real = julia.real;
    z.imaginary = julia.imaginary;
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

void   rendering_julia(t_fractal *fractal, t_complex julia)
{
    int x;
    int y;

    x = 0;
    y = 0;
    while (y < HEIGHT)
    {
        while (x < WIDTH)
        {
            put_in_buffer(x, y, fractal, julia);
            x++;
        }
        x = 0;
        y++;
    }
    mlx_put_image_to_window(fractal->mlx, fractal->window, fractal->image.image, 0, 0);
}