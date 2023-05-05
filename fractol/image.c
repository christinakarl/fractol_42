/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarl <ckarl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 20:25:16 by ckarl             #+#    #+#             */
/*   Updated: 2023/04/18 20:25:18 by ckarl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	upd_mlx_pixel_put(t_img *img, int x, int y, unsigned int color)
{
	char	*dst;

	dst = img->addr + (y * img->size_line + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	get_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

//create a new image
void	new_frame(t_fract *fract)
{
	mlx_clear_window(fract->ptr, fract->window);
	if (ft_strcmp(fract->fractal_type, "mandelbrot") == 0)
		draw_mandelbrot(fract);
	else if (ft_strcmp(fract->fractal_type, "julia") == 0)
		draw_julia(fract);
	mlx_put_image_to_window(fract->ptr, fract->window, \
	fract->img.img_ptr, 0, 0);
}

//change color coefficent when space button is pressed
void	change_colors(double *coef, t_fract *fract)
{
	if (fract->space == 1)
		*coef = 0.38;
	else if (fract->space == 2)
		*coef = 0.59;
	else if (fract->space == 3)
		*coef = 0.2;
}

//color pixels according to iteration result
void	iteration_palette(t_fract *fract, unsigned int iter)
{
	double	mult;
	double	coef;

	mult = log(iter) / log(MAX_ITER);
	change_colors(&coef, fract);
	if (iter == MAX_ITER)
		fract->color = get_trgb(0, coef * 255, (mult / coef) * 255, mult * 255);
	else if (iter >= 0 && iter < 4)
		fract->color = get_trgb(0, (0.04 + coef) * 255, \
		(mult / coef) * 255, (mult) * 255);
	else if (iter % 4 == 1)
		fract->color = get_trgb(0, (0.08 + coef) * 255, \
		(mult / coef) * 255, (mult) * 255);
	else if (iter % 4 == 2)
		fract->color = get_trgb(0, (0.07 + coef) * 255, \
		(mult / coef) * 255, (mult) * 255);
	else if (iter % 4 == 3)
		fract->color = get_trgb(0, (0.06 + coef) * 255, \
		(mult / coef) * 255, (mult) * 255);
	else if (iter % 4 == 4)
		fract->color = get_trgb(0, (0.05 + coef) * 255, \
		(mult / coef) * 255, (mult) * 255);
	else
		fract->color = get_trgb(0, (0.09 + coef) * 255, \
		(mult / coef) * 255, (mult) * 255);
}
