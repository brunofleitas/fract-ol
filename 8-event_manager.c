/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   8-event_manager.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleitas <bfleitas@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 15:57:20 by bfleitas          #+#    #+#             */
/*   Updated: 2024/06/18 13:32:08 by bfleitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
  Parameters:
	fractal: A pointer to the fractal structure that will be rendered.
  Description:
	Listens for user input events and calls the appropriate function to handle
	the event.
*/
void	listener(t_fractal *fractal)
{
	mlx_hook(fractal->window, 2, (1L << 0), key_action, fractal);
	mlx_hook(fractal->window, 4, (1L << 2), mouse_action, fractal);
	mlx_hook(fractal->window, 17, (1L << 17), close_window, fractal);
}

/*
  Parameters:
	keycode: The keycode of the pressed key.
	fractal: A pointer to the fractal structure that will be rendered.
  Return value:
	0 if the key action was successful.
  Description:
	Handles the key events and calls the appropriate function to manage 
	the event.
*/
int	key_action(int keycode, t_fractal *fractal)
{
	if (keycode == ESC)
		manage_close_key(fractal);
	if (keycode == LEFT)
		fractal->events.left_right_x += (0.25 * fractal->events.mouse_roll);
	if (keycode == RIGHT)
		fractal->events.left_right_x -= (0.25 * fractal->events.mouse_roll);
	if (keycode == DOWN)
		fractal->events.up_down_y += (0.25 * fractal->events.mouse_roll);
	if (keycode == UP)
		fractal->events.up_down_y -= (0.25 * fractal->events.mouse_roll);
	if (keycode == PLUS)
		fractal->max_iter += 10;
	if (keycode == MINUS)
		fractal->max_iter -= 10;
	rendering_fractal(fractal);
	return (0);
}

/*
  Parameters:
	button: The button code of the pressed mouse button.
	x: The x-coordinate of the mouse cursor.
	y: The y-coordinate of the mouse cursor.
	fractal: A pointer to the fractal structure that will be rendered.
  Return value:
	0 if the mouse action was successful.
  Description:
	Handles the mouse events and calls the appropriate function to manage the
	event.
*/
int	mouse_action(int button, int x, int y, t_fractal *fractal)
{
	(void)x;
	(void)y;
	
	if (button == SCROLL_UP)
		fractal->events.mouse_roll *= 0.9;
	if (button == SCROLL_DOWN)
		fractal->events.mouse_roll *= 1.1;
	rendering_fractal(fractal);
	return (0);
}

/*
  Parameters:
	fractal: A pointer to the fractal structure that will be rendered.
  Return value:
	0 if the window is closed successfully.
  Description:
	Closes the window and frees the memory allocated for the MLX instance.
*/
int	close_window(t_fractal *fractal)
{
	manage_close_key(fractal);
	return (0);
}

/*
  Parameters:
	fractal: A pointer to the fractal structure that will be rendered.
  Description:
	Destroys the image and window, frees the memory allocated for the MLX
	instance, and exits the program.
*/
void	manage_close_key(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx, fractal->image.image);
	mlx_destroy_window(fractal->mlx, fractal->window);
	mlx_destroy_display(fractal->mlx);
	free(fractal->mlx);
	exit(0);
}
