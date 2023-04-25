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
	if (iter >= 0 && iter <= 50)
		fract->color = get_trgb(0, 204, 153, 255) * iter;
	if (iter >= 51 && iter <= 100)
		fract->color = get_trgb(0, 100, 100, 0) * iter;
	else if (iter > 100 && iter <= 200)
		fract->color = get_trgb(0, 10, 100, 80) * iter;
	else if (iter > 200 && iter <= 300)
		fract->color = get_trgb(0, 0, 128, 255) * iter;
	else if (iter > 300 && iter <= 400)
		fract->color = get_trgb(0, 150, 100, 250) * iter;
	else if (iter > 400 && iter <= 500)
		fract->color = get_trgb(0, 153, 153, 255) * iter;
	else if (iter > 500 && iter < 1000)
		fract->color = get_trgb(0, 150, 100, 200) * iter;
	else if (iter == MAX_ITER)
		fract->color = get_trgb(0, 0, 0, 0);

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
