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

void	iteration_palette(t_fract *fract, unsigned int iter)
{
	double	mult;
	t_color	color;

	color.r = 255 - fract->space;
	color.g = 255 - fract->space;
	color.b = 255 - fract->space;
	mult = log(iter) / log(MAX_ITER);
	if (iter == MAX_ITER)
		fract->color = get_trgb(0, 0, 0, 0) ;
	else if (iter >= 0 && iter < 4)
		fract->color = get_trgb(0, 0.1 * color.r, (1 - mult) * color.g, mult * color.b);
	else if (iter % 4 == 1)
		fract->color = get_trgb(0, 0.2 * color.r, (1 - mult) * color.g, mult * color.b);
	else if (iter % 4 == 2)
		fract->color = get_trgb(0, 0.3 * color.r, (1 - mult) * color.g, mult * color.b);
	else if (iter % 4 == 3)
		fract->color = get_trgb(0, 0.4 * color.r, (1 - mult) * color.g, mult * color.b);
	else
		fract->color = get_trgb(0, 0.5 * color.r, (1 - mult) * color.g, mult * color.b);

}

/*a definir si necessaire*/
void	render_background(t_fract *fract, unsigned int color)
{
	int	x;
	int	y;

	if (fract->window == NULL)
		return ;
	y = 0;
	while (y < 800)
	{
		x = 0;
		while (x < 800)
		{
			upd_mlx_pixel_put(&fract->img, x, y, color);
			x++;
		}
			y++;
	}
}
