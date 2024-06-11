/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleitas <bfleitas@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 00:07:30 by bfleitas          #+#    #+#             */
/*   Updated: 2024/06/12 00:45:31 by bfleitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int main (int argc, char **argv)
{
    t_fractal fractal;

    if (argc == 2)
    {
        if (ft_strcmp(argv[1], "mandelbrot") == 0)
            mandelbrot(&fractal);
        else if (ft_strcmp(argv[1], "julia") == 0 && argc == 4)
            //julia();
            ft_putstr("julia\n");
        else
            ft_putstr("Invalid fractal name\n");
    }
    return (0);
}
