/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3-str_and_math_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleitas <bfleitas@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 00:08:54 by bfleitas          #+#    #+#             */
/*   Updated: 2024/06/12 03:15:37 by bfleitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "1-fractol.h"

int ft_strcmp(char *s1, char *s2)
{
    int i;
    
    i = 0;
    while (s1[i] && s2[i] && s1[i] == s2[i])
        i++;
    return (s1[i] - s2[i]);
}

void ft_putstr(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        write(1, &str[i], 1);
        i++;
    }
}

t_complex   sum(t_complex z1, t_complex z2)
{
    t_complex temp;

    temp.real = z1.real + z2.real;
    temp.imaginary = z1.imaginary + z2.imaginary;
    return (temp);
}

t_complex   square(t_complex z1)
{
    t_complex temp;

    temp.real = (z1.real * z1.real) - (z1.imaginary * z1.imaginary);
    temp.imaginary = 2 * (z1.real * z1.imaginary);
    return (temp);
}

double scale(double input, double new_min, double new_max, double old_max)
{
    return (new_min + (new_max - new_min) * ((input) / (old_max)));
}

