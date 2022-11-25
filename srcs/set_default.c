/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_default.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 16:31:16 by omercade          #+#    #+#             */
/*   Updated: 2021/08/23 15:51:00 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	set_default(t_fractol *this)
{
	this->max_iteration = 50;
	this->min = init_complex(-2.0, -2.0);
	this->max.re = 2.0;
	this->max.im = this->min.im
		+ (this->max.re - this->min.re) * HEIGHT / WIDTH;
	this->z = init_complex(this->origin.re, this->origin.im);
	this->color_shift = 0;
	draw_fractal(this);
	return ;
}
