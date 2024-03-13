/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarl <ckarl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 20:20:18 by ckarl             #+#    #+#             */
/*   Updated: 2023/04/18 20:20:19 by ckarl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//algo: f(x) = z^2 + c; calculate f(z) for each complex number c
//p is for quicker calculation, main mandelbrot set values return -2
//self-similarity, bounded, characteristic shape
int	mandelbrot(t_fract *fract)
{
	unsigned int	iter;
	double			temp;
	double			p;

	iter = 0;
	fract->z.r = 0;
	fract->z.i = 0;
	temp = 0;
	p = sqrt((fract->c.r - 0.25) * (fract->c.r - 0.25) + \
		fract->c.i * fract->c.i);
	if (fract->c.r < (p - 2.0 * p * p + 0.25))
		return (-2);
	if (((fract->c.r + 1) * (fract->c.r + 1) + fract->c.i * fract->c.i) \
		< 0.0625)
		return (-2);
	while (sqrt(fract->z.r * fract->z.r + fract->z.i * fract->z.i) < 2 \
			&& iter < MAX_ITER)
	{
		temp = fract->z.r;
		fract->z.r = fract->z.r * fract->z.r - fract->z.i * \
					fract->z.i + fract->c.r;
		fract->z.i = 2 * temp * fract->z.i + fract->c.i;
		iter++;
	}
	return (iter);
}

//mandelbrot: x and y are used to calculate the corresponding value of c
// c.r = based on x, center image hor. + scale to desired size
// c.i = based on y, center image vert. + scale to desired size
void	draw_mandelbrot(t_fract *fract)
{
	fract->y = 0;
	while (fract->y < HEIGHT)
	{
		fract->x = 0;
		while (fract->x < WIDTH)
		{
			fract->c.r = ((fract->x + fract->hz_move) - WIDTH / 2.0) \
						* fract->zoom * 4.0 / WIDTH;
			fract->c.i = ((fract->y + fract->vt_move) - HEIGHT / 2.0) \
						* fract->zoom * 4.0 / WIDTH;
			if (mandelbrot(fract) == -2)
				iteration_palette(fract, MAX_ITER);
			else
				iteration_palette(fract, mandelbrot(fract));
			upd_mlx_pixel_put(&fract->img, fract->x, fract->y, fract->color);
			fract->x++;
		}
		fract->y++;
	}
}
