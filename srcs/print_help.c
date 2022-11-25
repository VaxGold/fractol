/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_help.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 18:56:28 by omercade          #+#    #+#             */
/*   Updated: 2021/08/24 17:03:51 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	print_help(int output)
{
	if (!output)
		printf("Error!\n");
	printf("./fractol <type> <float real> <float imaginary>\n");
	printf("./fractol types:\n");
	printf("\t1.- Julia\n");
	printf("\t2.- Mandelbrot\n");
	printf("**Parameters only works with Julia, otherwise will be ignored.");
	printf(" Also surplus parameters will be ignored too.");
	printf(" In case of wrong data default will be used.**\n");
	return (output);
}
