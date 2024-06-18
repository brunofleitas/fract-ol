/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4-creation_fractal.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleitas <bfleitas@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 00:31:58 by bfleitas          #+#    #+#             */
/*   Updated: 2024/06/18 01:25:07 by bfleitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "1-fractol.h"

/*
  Parameters:
    fractal: A pointer to the fractal structure where the MLX connection will 
	be initialized.
  Description:
    Initializes the MLX library for rendering graphics associated with the 
	given fractal. It checks if the initialization was successful; if not, 
	it prints an error message.
*/
void	create_conection(t_fractal *fractal)
{
	fractal->mlx = mlx_init();
	if (!fractal->mlx)
		ft_putstr("Error\n");
}

/*
  Parameters:
    fractal: A pointer to the fractal structure where the window will
	be created.
  Description:
    Creates a new graphical window using the MLX library based on the 
	dimensions and name specified in the fractal structure. If the window 
	creation fails, it destroys the display and frees the memory allocated 
	for the MLX instance, then prints an error message.
*/
void	create_window(t_fractal *fractal)
{
	fractal->window = mlx_new_window(fractal->mlx, WIDTH, HEIGHT,
			fractal->name);
	if (!fractal->window)
	{
		mlx_destroy_display(fractal->mlx);
		free(fractal->mlx);
		ft_putstr("Error\n");
	}
}

/*
  Parameters:
    fractal: A pointer to the fractal structure where the image will be created
  Description:
    Creates a new image using the MLX library based on the specified width and 
	height. If the image creation fails, it destroys the window and display, 
	frees the memory allocated for the MLX instance, and prints an error message
	Otherwise, it retrieves the address of the image data for further processing
*/
void	create_image(t_fractal *fractal)
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
			&fractal->image.bits_per_pixel, &fractal->image.line_length,
			&fractal->image.endian);
}

/*
  Parameters:
	fractal: A pointer to the fractal structure that will be rendered.
  Description:
	Renders the fractal by iterating over each pixel in the image and 
	calculating the corresponding complex number based on the pixel's 
	coordinates. It then calculates the color of the pixel based on the 
	complex number and the fractal's parameters.
*/
void	create_fractal(t_fractal *fractal)
{
	fractal->max_iter = MAX_ITER;
	fractal->scape_radius = ESCAPE_RADIUS;
	fractal->events.left_right_x = 0;
	fractal->events.up_down_y = 0;
	fractal->events.mouse_roll = 1;
	create_conection(fractal);
	create_window(fractal);
	create_image(fractal);
	rendering_fractal(fractal);
	listener(fractal);
	mlx_loop(fractal->mlx);
}
