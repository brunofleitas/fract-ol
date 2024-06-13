/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2-main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleitas <bfleitas@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 00:07:30 by bfleitas          #+#    #+#             */
/*   Updated: 2024/06/13 21:38:43 by bfleitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "1-fractol.h"

int main (int argc, char **argv)
{
    t_fractal fractal;
    t_complex juliaPoint;

    if (ft_strcmp(argv[1], "mandelbrot") == 0 && argc == 2)
        mandelbrot(&fractal);
    else if (ft_strcmp(argv[1], "julia") == 0 && argc == 4)
    {
        fractal.juliaPoint.real = array_to_double(argv[2]);
        fractal.juliaPoint.imaginary = array_to_double(argv[3]);
        julia(&fractal);
    }
    else
        ft_putstr("Invalid fractal name\n");
    return (0);
}
