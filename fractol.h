/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleitas <bfleitas@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 00:03:51 by bfleitas          #+#    #+#             */
/*   Updated: 2024/06/12 00:59:46 by bfleitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h> //write
#include "MinilibX/mlx.h" //mlx

#define WIDTH 800
#define HEIGHT 800

typedef struct s_fractal
{
    char	    *name;
    void	    *mlx;
    void	    *window;
    t_image     image;
}	t_fractal;

typedef struct s_image
{
    void	    *image;
    char	    *address;
    int	        bits_per_pixel;
    int	        line_length;
    int	        endian;
}	t_image;

typedef struct s_complex
{
    double	real;
    double	imaginary;
}	t_complex;

//STR AND MATH UTILS
int ft_strcmp(char *s1, char *s2);
void ft_putstr(char *str);
t_complex   sum(t_complex z1, t_complex z2);
t_complex   square(t_complex z1);

//CREATION MANDELBROT
void    create_conection(t_fractal *fractal);
void    create_window(t_fractal *fractal);
void    create_image(t_fractal *fractal);
void    mandelbrot(t_fractal *fractal);

