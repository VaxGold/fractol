/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 16:09:04 by omercade          #+#    #+#             */
/*   Updated: 2021/08/23 18:27:49 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H

# define FRACTOL_H

/* INCLUDES */
# include <stdio.h>
# include <stdlib.h>
# include <stdint.h>
# include <math.h>
# include <mlx.h>
# include "../libft/libft.h"

/* DEFINES */
# define WIDTH		1000
# define HEIGHT		1000

/* KEY EVENTS */
# define X_EVENT_KEY_PRESS		2
# define X_EVENT_KEY_RELEASE	3
# define X_EVENT_KEY_EXIT		17

# define MOUSE_EVENT_INPUT		4
# define MOUSE_SCROLL_UP		4
# define MOUSE_SCROLL_DOWN		5

# define KEY_ESC				53
# define KEY_SPACE				49
# define KEY_UP					126
# define KEY_DOWN				125
# define KEY_LEFT				123
# define KEY_RIGHT				124
# define KEY_C					8
# define KEY_H					4
# define KEY_R					15
# define KEY_PLUS				24
# define KEY_MINUS				27
# define NUMP_PLUS				69
# define NUMP_MINUS				78

/* STRUCTURES */
typedef struct s_color
{
	int8_t			channel[4];
}					t_color;

typedef struct s_complex
{
	double			re;
	double			im;
}					t_complex;

typedef struct s_image
{
	void			*ptr;
	char			*data_addr;
	int				bpp;
	int				size_l;
	int				endian;
}					t_image;

typedef struct s_fractol
{
	void				*mlx;
	void				*window;
	t_image				*image;
	int					max_iteration;
	t_complex			min;
	t_complex			max;
	t_complex			factor;
	t_complex			origin;
	t_complex			c;
	t_complex			z;
	int					color_shift;
	int					(*formula)
	(struct s_fractol	*fractol);
	char				*name;
}						t_fractol;

typedef struct s_formula
{
	char		*name;
	int			(*formula)
	(t_fractol	*fractol);
}				t_formula;

/* FUNCTIONS */
void		draw_fractal(t_fractol *fractol);
int			fractal_julia(t_fractol *fractol);
int			fractal_mandelbrot(t_fractol *fractol);

t_complex	init_complex(double re, double im);
t_complex	get_complex(int narg, char **xarg);
void		set_default(t_fractol *this);

t_color		get_color(int iteration, t_fractol *fractol);
int			print_help(int output);

int			key_press(int key, t_fractol *fractol);
int			zoom(int button, int x, int y, t_fractol *fractol);
int			close_window(t_fractol *this);

#endif
