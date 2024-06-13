/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1-fractol.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleitas <bfleitas@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 00:03:51 by bfleitas          #+#    #+#             */
/*   Updated: 2024/06/14 00:24:21 by bfleitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MinilibX/mlx.h" //mlx
#include <X11/X.h>        //keycodes
#include <stdio.h>        //printf
#include <stdlib.h>       //malloc
#include <unistd.h>       //write

#define WIDTH 800
#define HEIGHT 800
#define MAX_ITER 300
#define ESCAPE_RADIUS 4

#define ESC 0xff1b
#define LEFT 0xff51
#define RIGHT 0xff53
#define DOWN 0xff54
#define UP 0xff52
#define PLUS 0x002b
#define MINUS 0x002d
#define SCROLL_UP 4
#define SCROLL_DOWN 5

typedef struct s_complex
{
	double		real;
	double		imaginary;
}				t_complex;

typedef struct s_image
{
	void		*image;
	char		*address;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_image;

typedef struct s_events
{
	double		left_right_x;
	double		up_down_y;
	double		mouse_roll;
}				t_events;

typedef struct s_fractal
{
	char		*name;
	void		*mlx;
	void		*window;
	t_image		image;
	int			max_iter;
	int			scape_radius;
	int			color;
	t_events	events;
	t_complex	juliaPoint;
}				t_fractal;

// STR AND MATH UTILS
int				ft_strcmp(char *s1, char *s2);
void			ft_putstr(char *str);
t_complex		sum(t_complex z1, t_complex z2);
t_complex		square(t_complex z1);
double			array_to_double(char *str);

// CREATION FRACTAL
void			create_conection(t_fractal *fractal);
void			create_window(t_fractal *fractal);
void			create_image(t_fractal *fractal);
void			create_fractal(t_fractal *fractal);

// RENDERING FRACTAL
void			rendering_fractal(t_fractal *fractal);
void			put_in_buffer(int x, int y, t_fractal *fractal);
void			put_pixel_buffer(t_fractal *fractal, int x, int y, int color);
double			scale(double input, double new_min, double new_max,
					double old_max);

// EVENT MANAGER
void			listener(t_fractal *fractal);
int				key_action(int keycode, t_fractal *fractal);
int				mouse_action(int button, int x, int y, t_fractal *fractal);
int				close_window(t_fractal *fractal);
void			manage_close_key(t_fractal *fractal);
