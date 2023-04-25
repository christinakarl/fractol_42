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

	iter = 0;
	temp = 0;
	while ((fract->z.r * fract->z.r + fract->z.i * fract->z.i) < 4 && iter < MAX_ITER)
	{
		temp = fract->z.r;
		fract->z.r = fract->z.r * fract->z.r - fract->z.i * fract->z.i + fract->c.r;
		fract->z.i = 2 * temp * fract->z.i + fract->c.i;

		iter++;
	}
	return (iter);
}
