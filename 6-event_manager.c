/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6-event_manager.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleitas <bfleitas@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 15:57:20 by bfleitas          #+#    #+#             */
/*   Updated: 2024/06/13 18:41:45 by bfleitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "1-fractol.h"

void    listener(t_fractal *fractal)
{
    mlx_hook(fractal->window, 2, (1L<<0), key_action, fractal);
    mlx_hook(fractal->window, 4, (1L<<2), mouse_action, fractal);
    mlx_hook(fractal->window, 17, (1L<<17), close_window, fractal);
}

int     key_action(int keycode, t_fractal *fractal)
{
    if (keycode == 0xff1b)
        manage_close_key(fractal);
    if (keycode == 0xff51)
        fractal->events.left_right_x += (0.25 * fractal->events.mouse_roll);
    if (keycode == 0xff53) 
        fractal->events.left_right_x -= (0.25 * fractal->events.mouse_roll);
    if (keycode == 0xff54)
        fractal->events.up_down_y += (0.25 * fractal->events.mouse_roll);
    if (keycode == 0xff52)
        fractal->events.up_down_y -= (0.25 * fractal->events.mouse_roll);
    if (keycode == 0x002b)
        fractal->max_iter += 10;
    if (keycode == 0x002d)
        fractal->max_iter -= 10;
    rendering_mandelbrot(fractal);
    return (0);
}

int     mouse_action(int button, int x, int y, t_fractal *fractal)
{
    if (button == 4)
        fractal->events.mouse_roll *= 0.9;
    if (button == 5)
        fractal->events.mouse_roll *= 1.1;
    rendering_mandelbrot(fractal);
    return (0);
}

int     close_window(t_fractal *fractal)
{
    manage_close_key(fractal);
    return (0);
} 

void    manage_close_key(t_fractal *fractal)
{
    mlx_destroy_image(fractal->mlx, fractal->image.image);
    mlx_destroy_window(fractal->mlx, fractal->window);
    mlx_destroy_display(fractal->mlx);
    free(fractal->mlx);
    exit(0);
}