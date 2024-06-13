/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4-creation_fractal.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleitas <bfleitas@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 00:31:58 by bfleitas          #+#    #+#             */
/*   Updated: 2024/06/13 16:06:58 by bfleitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "1-fractol.h"

void    create_conection(t_fractal *fractal) 
{
    fractal->mlx = mlx_init();
    if (!fractal->mlx)
        ft_putstr("Error\n");
}

void    create_window(t_fractal *fractal)
{
    fractal->window = mlx_new_window(fractal->mlx, WIDTH, HEIGHT, fractal->name);
    if (!fractal->window)
    {
        mlx_destroy_display(fractal->mlx);
        free(fractal->mlx);
        ft_putstr("Error\n");
    }
}

void    create_image(t_fractal *fractal)
{
    fractal->image.image = mlx_new_image(fractal->mlx, WIDTH, HEIGHT);
    if (!fractal->image.image)
    {
        mlx_destroy_window(fractal->mlx, fractal->window);
        mlx_destroy_display(fractal->mlx);
        free(fractal->mlx);
        ft_putstr("Error\n");
    }
    fractal->image.address = mlx_get_data_addr(fractal->image.image, 
                                                &fractal->image.bits_per_pixel, 
                                                &fractal->image.line_length, 
                                                &fractal->image.endian);
}

void    mandelbrot(t_fractal *fractal)
{
    fractal->name = "Mandelbrot";
    fractal->max_iter = MAX_ITER;
    fractal->scape_radius = ESCAPE_RADIUS;
    fractal->events.left_right_x = 0;
    fractal->events.up_down_y = 0;
    fractal->events.mouse_roll = 1;
    create_conection(fractal);
    create_window(fractal);
    create_image(fractal);
    rendering_mandelbrot(fractal);
    mlx_loop(fractal->mlx);
}

void    julia(t_fractal *fractal, t_complex juliaPoint)
{
    fractal->name = "Julia";
    fractal->max_iter = MAX_ITER;
    fractal->scape_radius = ESCAPE_RADIUS;
    create_conection(fractal);
    create_window(fractal);
    create_image(fractal);
    rendering_julia(fractal, juliaPoint);
    mlx_loop(fractal->mlx);
}
