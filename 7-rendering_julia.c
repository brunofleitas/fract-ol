/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   7-rendering_julia.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleitas <bfleitas@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 02:55:28 by bfleitas          #+#    #+#             */
/*   Updated: 2024/06/13 21:44:30 by bfleitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "1-fractol.h"

void    put_in_buffer_julia(int x, int y, t_fractal *fractal)
{
    t_complex   c;
    t_complex   z;
    int         i;
    int        color;

    z.real = scale(x, -2, 2, WIDTH) * fractal->events.mouse_roll + fractal->events.left_right_x;
    z.imaginary = scale(y, 2, -2, HEIGHT) * fractal->events.mouse_roll + fractal->events.up_down_y;
    i = 0;
    c.real = fractal->juliaPoint.real;
    c.imaginary = fractal->juliaPoint.imaginary;
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