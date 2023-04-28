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

/*algo: f(x) = z^2 + c; c is fixed, z has different initial values
 * julia set does not diverge to infinity when iterated from complex nr z
 * wide range of shapes, patterns*/
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
	while ((fract->z.r * fract->z.r + fract->z.i * fract->z.i) < 4 && iter <= MAX_ITER)
	{
		temp = fract->z.r;
		fract->z.r = fract->z.r * fract->z.r - fract->z.i * fract->z.i + fract->c.r;
		fract->z.i = 2 * temp * fract->z.i + fract->c.i;
		// if (fract->z.r == zr_before || fract->z.i == zi_before)
		// 	return (MAX_ITER);
		zi_before = fract->z.i;
		zr_before = fract->z.r;
		iter++;
	}
	return (iter);
}
