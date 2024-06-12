/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1-fractol.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleitas <bfleitas@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 00:03:51 by bfleitas          #+#    #+#             */
/*   Updated: 2024/06/12 03:29:01 by bfleitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h> //write
#include <stdlib.h> //malloc
#include "MinilibX/mlx.h" //mlx

#define WIDTH 800
#define HEIGHT 800
#define MAX_ITER 1000
#define ESCAPE_RADIUS 4

typedef struct s_complex
{
    double	real;
    double	imaginary;
}	t_complex;

typedef struct s_image
{
    void	    *image;
    char	    *address;
    int	        bits_per_pixel;
    int	        line_length;
    int	        endian;
}	t_image;

typedef struct s_fractal
{
    char	    *name;
    void	    *mlx;
    void	    *window;
    t_image     image;
    int	        max_iter;
    int         scape_radius;
    int         color;
}	t_fractal;

//STR AND MATH UTILS
int ft_strcmp(char *s1, char *s2);
void ft_putstr(char *str);
t_complex   sum(t_complex z1, t_complex z2);
t_complex   square(t_complex z1);

//CREATION FRACTAL
void    create_conection(t_fractal *fractal);
void    create_window(t_fractal *fractal);
void    create_image(t_fractal *fractal);
void    mandelbrot(t_fractal *fractal);
void    julia(t_fractal *fractal, t_complex julia);

//RENDERING MANDELBROT
double  scale(double input, double new_min, double new_max, double old_max);
void    put_in_buffer_mandelbrot(int x, int y, t_fractal *fractal);
void    rendering_mandelbrot(t_fractal *fractal);
void   rendering_julia(t_fractal *fractal, t_complex julia);
void    put_pixel_buffer(t_fractal *fractal, int x, int y, int color);
void    put_in_buffer_julia(int x, int y, t_fractal *fractal, t_complex julia);

