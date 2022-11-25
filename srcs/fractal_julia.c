/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_julia.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 18:11:58 by omercade          #+#    #+#             */
/*   Updated: 2021/08/18 16:42:08 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	fractal_julia(t_fractol *fractol)
{
	int			iteration;
	t_complex	k;

	iteration = 0;
	k = init_complex(fractol->c.re, fractol->c.im);
	while (pow(k.re, 2.0) + pow(k.im, 2.0) <= 4
		&& iteration < fractol->max_iteration)
	{
		k = init_complex(
				pow(k.re, 2.0) - pow(k.im, 2.0) + fractol->z.re,
				2.0 * k.re * k.im + fractol->z.im);
		iteration++;
	}
	return (iteration);
}
