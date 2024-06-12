/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2-main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleitas <bfleitas@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 00:07:30 by bfleitas          #+#    #+#             */
/*   Updated: 2024/06/12 03:06:31 by bfleitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int main (int argc, char **argv)
{
    t_fractal fractal;
    t_complex julia;

    if (argc == 2)
    {
        if (ft_strcmp(argv[1], "mandelbrot") == 0)
            mandelbrot(&fractal);
        else if (ft_strcmp(argv[1], "julia") == 0 && argc == 4)
        {
            julia.real = atoi(argv[2]); //CAMBIAR A FT_ATOI
            julia.imaginary = atoi(argv[3]); //CAMBIAR A FT_ATOI
            julia(&fractal, julia);
        }
        else
            ft_putstr("Invalid fractal name\n");
    }
    return (0);
}
