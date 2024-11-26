/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1-main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleitas <bfleitas@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 00:07:30 by bfleitas          #+#    #+#             */
/*   Updated: 2024/06/18 13:26:31 by bfleitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	input_options(void)
{
	ft_putstr_fd("Invalid fractal name\nValid options:\n \
		mandelbrot\n \
		julia <real value> <imaginary value>\n \
		burningship\n", 1);
}

/*
  Main function to create fractals based on command-line arguments.
  - "mandelbrot" with 1 argument creates a Mandelbrot fractal.
  - "julia" with 3 arguments creates a Julia fractal.
  - "burningship" with 1 argument creates a Burning Ship fractal.
  - Otherwise, prints "Invalid fractal name".
  Returns 0 for successful execution.
*/
int	main(int argc, char **argv)
{
	t_fractal	fractal;

	if (argc > 1 && ft_strcmp(argv[1], "mandelbrot") == 0 && argc == 2)
	{
		fractal.name = argv[1];
		create_fractal(&fractal);
	}
	else if (argc > 1 && ft_strcmp(argv[1], "julia") == 0 && argc == 4)
	{
		fractal.name = argv[1];
		fractal.julia_point.real = array_to_double(argv[2]);
		fractal.julia_point.imaginary = array_to_double(argv[3]);
		create_fractal(&fractal);
	}
	else if (argc > 1 && ft_strcmp(argv[1], "burningship") == 0 && argc == 2)
	{
		fractal.name = argv[1];
		create_fractal(&fractal);
	}
	else
		input_options();
	return (0);
}
