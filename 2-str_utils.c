/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2-str_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleitas <bfleitas@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 00:08:54 by bfleitas          #+#    #+#             */
/*   Updated: 2024/06/18 11:17:04 by bfleitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

/*
  Parameters: 
      c: The character to write to the file descriptor.
      fd: The file descriptor to write to.
  Description:
      Writes the character 'c' to the file descriptor 'fd'.
*/
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

/*
  Parameters: 
      s: The string to write to the file descriptor.
      fd: The file descriptor to write to.
  Description:
      Writes the string 's' to the file descriptor 'fd'.
*/
void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
}

/*
//CAMBIAR CON ORIGINAL
double	array_to_double(char *str)
{
	double	integer;
	int		i;
	int		sign;
	double	power;
	double	decimal;

	i = 0;
	sign = 1;
	integer = 0;
	decimal = 0;
	power = 1;
	while (str[i] != 0 && ((str[i] == ' ')
		|| (str[i] >= 9 && str[i] <= 13)))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] && str[i] != '.')
	{
		if ((str[i] >= '0' && str[i] <= '9'))
			integer = integer * 10 + (str[i] - '0');
		else 
			return (0);
		i++;
	}
	if (str[i] == '.')
		i++;
	while (str[i])
	{
		if ((str[i] >= '0' && str[i] <= '9'))
		{
			power = power / 10;
			decimal = decimal + (str[i] - '0') * power;
		}
		else 
			return (0);
		i++;
	}
	return ((integer + decimal) * sign);
}*/