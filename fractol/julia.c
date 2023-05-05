/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarl <ckarl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 12:14:16 by ckarl             #+#    #+#             */
/*   Updated: 2023/03/23 12:14:18 by ckarl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//algo: f(x) = z^2 + c; c is fixed, z has different initial values
//wide range of shapes, patterns
int	julia(t_fract *fract)
{
	unsigned int	iter;
	double			temp;
	double			zr_before;
	double			zi_before;

	iter = 0;
	temp = 0;
	zi_before = 0;
	zr_before = 0;
	while ((fract->z.r * fract->z.r + fract->z.i * fract->z.i) < 4 \
			&& iter < MAX_ITER)
	{
		temp = fract->z.r;
		fract->z.r = fract->z.r * fract->z.r - fract->z.i * fract->z.i \
					+ fract->c.r;
		fract->z.i = 2 * temp * fract->z.i + fract->c.i;
		if (fract->z.r == zr_before || fract->z.i == zi_before)
			return (MAX_ITER);
		zi_before = fract->z.i;
		zr_before = fract->z.r;
		iter++;
	}
	return (iter);
}

void	draw_julia(t_fract *fract)
{
	fract->y = 0;
	while (fract->y < HEIGHT)
	{
		fract->x = 0;
		while (fract->x < WIDTH)
		{
			fract->z.r = ((fract->x + fract->hz_move) - WIDTH / 2.0) * \
						fract->zoom * 4.0 / WIDTH ;
			fract->z.i = ((fract->y + fract->vt_move) - HEIGHT / 2.0) * \
						fract->zoom * 4.0 / WIDTH;
			iteration_palette(fract, julia(fract));
			upd_mlx_pixel_put(&fract->img, fract->x, fract->y, fract->color);
			fract->x++;
		}
		fract->y++;
	}
}
