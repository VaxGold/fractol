/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 16:09:11 by omercade          #+#    #+#             */
/*   Updated: 2021/08/25 16:10:49 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fractol.h"

static int	(*get_formula(char *name))(t_fractol *fractol)
{
	int							i;
	int							(*formula)
	(t_fractol					*fractol);
	static t_formula			formulas[] = {
		{"Mandelbrot", &fractal_mandelbrot},
		{"Julia", &fractal_julia}
	};

	i = 0;
	formula = NULL;
	while (i < (int)(sizeof(formulas) / sizeof(t_formula)))
	{
		if (!ft_strncmp(name, formulas[i].name, ft_strlen(name) + 1))
			formula = formulas[i].formula;
		i++;
	}
	return (formula);
}

int	awake(int narg, char **xarg, t_fractol *this)
{
	this->name = ft_strdup(xarg[1]);
	this->formula = get_formula(this->name);
	if (!this->formula)
		return (0);
	this->origin = get_complex(narg, xarg);
	return (1);
}

void	start(t_fractol *this)
{
	char	*str;

	str = ft_strjoin("fract'ol_", this->name);
	this->mlx = mlx_init();
	this->window = mlx_new_window(this->mlx, WIDTH, HEIGHT, str);
	free(str);
	this->image = ft_calloc(sizeof(t_image), sizeof(t_image));
	if (!this->image)
		return ;
	this->image->ptr = mlx_new_image(this->mlx, WIDTH, HEIGHT);
	this->image->data_addr = mlx_get_data_addr(this->image->ptr,
			&this->image->bpp, &this->image->size_l, &this->image->endian);
	set_default(this);
	return ;
}

int	main(int narg, char **xarg)
{
	t_fractol	this;

	if (narg > 1 && awake(narg, xarg, &this))
	{
		start(&this);
		mlx_hook(this.window, MOUSE_EVENT_INPUT, 0, &zoom, &this);
		mlx_hook(this.window, X_EVENT_KEY_PRESS, 0, &key_press, &this);
		mlx_hook(this.window, X_EVENT_KEY_EXIT, 0, &close_window, &this);
		mlx_loop(this.mlx);
	}
	else
		return (print_help(0));
	return (0);
}
