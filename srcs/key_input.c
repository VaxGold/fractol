/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 17:14:45 by omercade          #+#    #+#             */
/*   Updated: 2021/08/18 16:49:55 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	change_max_iteration(int key, t_fractol *fractol)
{
	if (key == KEY_PLUS || key == NUMP_PLUS)
	{
		if (fractol->max_iteration < 50)
			fractol->max_iteration += 1;
		else if (fractol->max_iteration < 1000000000)
			fractol->max_iteration = (int)(fractol->max_iteration * 1.05);
	}
	if (key == KEY_MINUS || key == NUMP_MINUS)
	{
		if (fractol->max_iteration > 50)
			fractol->max_iteration = (int)(fractol->max_iteration * 0.95);
		else if (fractol->max_iteration > 1)
			fractol->max_iteration -= 1;
	}
	draw_fractal(fractol);
}

int	key_press(int key, t_fractol *fractol)
{
	if (key == KEY_ESC)
		exit(0);
	else if (key == KEY_MINUS || key == NUMP_MINUS
		|| key == KEY_PLUS || key == NUMP_PLUS)
		change_max_iteration(key, fractol);
	else if (key == KEY_R)
		set_default(fractol);
	else if (key == KEY_C)
	{
		fractol->color_shift = (fractol->color_shift + 1) % 3;
		draw_fractal(fractol);
	}
	return (0);
}
