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

/*algo: f(x) = z^2 + c; start with z.x & z.y = 0; need to calculate f(z) for each complex number c in the image
 * mandelbrot set does not diverge to infinity when iterated from z = 0
 * self-similarity, bounded, characteristic shape*/
int	mandelbrot(t_fract *fract)
{
	unsigned int	iter;
	double			temp;
	double			distance;
	double			p;

	iter = 0;
	fract->z.r = 0;
	fract->z.i = 0;
	temp = 0;

	p = sqrt((fract->c.r - 0.25) * (fract->c.r - 0.25) + fract->c.i * fract->c.i);
	if (fract->c.r < (p - 2.0 * p * p + 0.25))
		return (-2);
	if (((fract->c.r + 1) * (fract->c.r + 1) + fract->c.i * fract->c.i) < 0.0625)
		return (-2);
	while (sqrt(fract->z.r * fract->z.r + fract->z.i * fract->z.i) < 2 && iter <= MAX_ITER)
	{
		temp = fract->z.r;
		fract->z.r = fract->z.r * fract->z.r - fract->z.i * fract->z.i + fract->c.r;
		fract->z.i = 2 * temp * fract->z.i + fract->c.i;

		iter++;
	}
	distance = sqrt(fract->z.r * fract->z.r + fract->z.i * fract->z.i);
	if (distance < 2)
		return (-2);
	return (iter);
}


