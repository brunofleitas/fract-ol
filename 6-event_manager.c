/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6-event_manager.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleitas <bfleitas@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 15:57:20 by bfleitas          #+#    #+#             */
/*   Updated: 2024/06/13 16:38:08 by bfleitas         ###   ########.fr       */
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
        fractal->events.left_right_x -= 1;
    if (keycode == 0xff53)
        fractal->events.left_right_x += 1;
    if (keycode == 0xff54)
        fractal->events.up_down_y -= 1;
    if (keycode == 0xff52)
        fractal->events.up_down_y += 1;
    return (0);
}

int     mouse_action(int button, int x, int y, t_fractal *fractal)
{
    if (button == 4)
        fractal->events.mouse_roll += 0.1;
    if (button == 5)
        fractal->events.mouse_roll -= 0.1;
    return (0);
}

int     close_window(t_fractal *fractal)
{
    manage_close_key(fractal);
    return (0);
}

void    manage_close_key(t_fractal *fractal)
{
    mlx_destroy_window(fractal->mlx, fractal->window);
    mlx_destroy_display(fractal->mlx);
    free(fractal->mlx);
    exit(0);
}