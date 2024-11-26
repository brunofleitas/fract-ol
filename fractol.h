/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleitas <bfleitas@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 00:03:51 by bfleitas          #+#    #+#             */
/*   Updated: 2024/06/18 13:56:45 by bfleitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

/* ************************************************************************** */
/* LIBRARIES                                                                  */
/* ************************************************************************** */
# include "MinilibX/mlx.h" //mlx
# include <X11/X.h>        //keycodes
# include <stdlib.h>       //malloc
# include <unistd.h>       //write

/* ************************************************************************** */
/* DEFINITIONS                                                                */
/* ************************************************************************** */
# define WIDTH 800
# define HEIGHT 800
# define MAX_ITER 120
# define ESCAPE_RADIUS 4

# define ESC 0xff1b
# define LEFT 0xff51
# define RIGHT 0xff53
# define DOWN 0xff54
# define UP 0xff52
# define PLUS 0xffab
# define MINUS 0xffad
# define SCROLL_UP 4
# define SCROLL_DOWN 5

/* ************************************************************************** */
/* STRUCTURES                                                                 */
/* ************************************************************************** */
typedef struct s_complex
{
	double			real;
	double			imaginary;
}					t_complex;

typedef struct s_image
{
	void			*image;
	char			*address;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
}					t_image;

typedef struct s_events
{
	double			left_right_x;
	double			up_down_y;
	double			mouse_roll;
}					t_events;

typedef struct s_fractal
{
	char			*name;
	void			*mlx;
	void			*window;
	t_image			image;
	int				max_iter;
	int				scape_radius;
	int				color;
	t_events		events;
	t_complex		julia_point;
}					t_fractal;

/* ************************************************************************** */
/* FUNCTIONS                                                                  */
/* ************************************************************************** */
// STR UTILS
int					ft_strcmp(char *s1, char *s2);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);

// ARRAY TO DOUBLE
double				array_to_double(char *str);
void				generate_decimal(int *i, char *str, double *power,
						double *decimal);
void				generate_integer(int *i, char *str, double *integer);

// MATH UTILS
t_complex			sum(t_complex z1, t_complex z2);
t_complex			square(t_complex z1);
t_complex			square_abs(t_complex z1);

// CREATION FRACTAL
void				create_conection(t_fractal *fractal);
void				create_window(t_fractal *fractal);
void				create_image(t_fractal *fractal);
void				create_fractal(t_fractal *fractal);

// RENDERING FRACTAL
void				rendering_fractal(t_fractal *fractal);
void				put_in_buffer(int x, int y, t_fractal *fractal);
void				save_pixel_on_buffer(t_fractal *fractal, int x, int y,
						int color);
double				scale(double input, double new_min, double new_max,
						double old_max);

// BUILD DIFFERENT FRACTALS
void				mandelbrot(int x, int y, t_fractal *fractal);
void				julia(int x, int y, t_fractal *fractal);
void				burningship(int x, int y, t_fractal *fractal);

// EVENT MANAGER
void				listener(t_fractal *fractal);
int					key_action(int keycode, t_fractal *fractal);
int					mouse_action(int button, int x, int y, t_fractal *fractal);
int					close_window(t_fractal *fractal);
void				manage_close_key(t_fractal *fractal);

#endif