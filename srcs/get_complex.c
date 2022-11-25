/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_complex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 15:33:36 by omercade          #+#    #+#             */
/*   Updated: 2021/08/24 16:52:32 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	ft_isfloat(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i] && str[i] != '.')
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	if (str[i] == '.')
	{
		i++;
		while (str[i])
		{
			if (!ft_isdigit(str[i]))
				return (0);
			i++;
		}
	}
	return (1);
}

int	check_params(char **xarg)
{
	if (ft_strncmp(xarg[1], "Julia", 5))
		return (0);
	if (!ft_isfloat(xarg[2]) || !ft_isfloat(xarg[3]))
		return (0);
	return (1);
}

int	get_digits(int n)
{
	int	digits;

	digits = 1;
	while (n > 10)
	{
		digits++;
		n /= 10;
	}
	return (digits);
}

double	set_complex(char *str)
{
	double	n;
	double	f;
	int		sign;
	int		i;

	i = 0;
	n = 0;
	f = 0;
	sign = 1;
	if (str[i] == '-')
	{
		sign = -sign;
		i++;
	}
	while (str[i] && str[i] != '.')
		n = n * 10 + (str[i++] - 48);
	if (str[i] == '.')
	{
		i++;
		while (str[i])
			f = f * 10 + (str[i++] - 48);
	}
	n = sign * (n + f / pow(10, get_digits((int)f)));
	return (n);
}

t_complex	get_complex(int narg, char **xarg)
{
	t_complex	complex;

	if (narg != 4 || !check_params(xarg))
		complex = init_complex(-0.4, -0.6);
	else
		complex = init_complex(set_complex(xarg[2]), -1 * set_complex(xarg[3]));
	return (complex);
}
