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
	*(unsigned int*)dst = color;
}

int	get_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	iteration_palette(t_fract *fract, unsigned int iter)			//check again if colors are showing correctly
{
	double	mult;
	t_color	color;
	double	coef;

	color.r = 255;
	color.g = 255;
	color.b = 255;
	mult = log(iter) / log(MAX_ITER);
	if (fract->space == 1)
	{
		color.g = 20;
		coef = 0.1;
	}
	else if (fract->space == 2)
		coef = 0.6;
	else if (fract->space == 3)
	{
		color.g = 100;
		coef = 0.9;
	}
	if (iter == MAX_ITER)
		fract->color = get_trgb(0, 0, 0, 0) ;
	else if (iter >= 0 && iter < 3)
		fract->color = get_trgb(0, (coef * 0.3) * color.r, (1 - mult) * color.g, (mult * (1 - coef)) * color.b);
	else if (iter % 3 == 1)
		fract->color = get_trgb(0, (coef * 0.4) * color.r, (1 - mult) * color.g, (mult * (1 - coef)) * color.b);
	else if (iter % 3 == 2)
		fract->color = get_trgb(0, (coef * 0.5) * color.r, (1 - mult) * color.g, (mult * (1 - coef)) * color.b);
	else if (iter % 3 == 3)
		fract->color = get_trgb(0, (coef * 0.6) * color.r, (1 - mult) * color.g, (mult * (1 - coef)) * color.b);
	else
		fract->color = get_trgb(0, (coef * 0.7) * color.r, (1 - mult) * color.g, (mult * (1 - coef)) * color.b);
}
