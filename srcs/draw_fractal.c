/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 17:33:07 by omercade          #+#    #+#             */
/*   Updated: 2021/08/18 16:51:10 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	put_pixel(t_fractol *fractol, int x, int y, t_color color)
{
	int	i;

	i = (x * fractol->image->bpp / 8)
		+ (y * fractol->image->size_l);
	fractol->image->data_addr[i] = color.channel[3];
	fractol->image->data_addr[++i] = color.channel[2];
	fractol->image->data_addr[++i] = color.channel[1];
	fractol->image->data_addr[++i] = color.channel[0];
}

void	draw_fractal(t_fractol *fractol)
{
	int		x;
	int		y;
	t_color	color;

	fractol->factor = init_complex(
			(fractol->max.re - fractol->min.re) / (WIDTH - 1),
			(fractol->max.im - fractol->min.im) / (HEIGHT - 1));
	y = 0;
	while (y < HEIGHT)
	{
		fractol->c.im = fractol->max.im - y * fractol->factor.im;
		x = 0;
		while (x < WIDTH)
		{
			fractol->c.re = fractol->min.re + x * fractol->factor.re;
			color = get_color(fractol->formula(fractol), fractol);
			put_pixel(fractol, x, y, color);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractol->mlx, fractol->window,
		fractol->image->ptr, 0, 0);
	return ;
}
