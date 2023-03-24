/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarl <ckarl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 17:51:00 by ckarl             #+#    #+#             */
/*   Updated: 2023/03/24 19:18:35 by ckarl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	upd_mlx_pixel_put(t_getdata *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->size_line + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(void)
{
	t_fract		fract;
	t_getdata	img;
	int			windsize;
	int			x;
	int			y;

	x = 100;
	y = 100;
	windsize = (1080 * img.size_line + 1920 * (img.bits_per_pixel / 8));
	fract.ptr = mlx_init();
	if (fract.ptr == NULL)
		return (0);
	fract.window = mlx_new_window(fract.ptr, 1920, 1080, "fractol");
	img.img_ptr = mlx_new_image(fract.ptr, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img_ptr, &img.bits_per_pixel, &img.size_line, &img.endian);
//0x00FF0000 = hex representation of ARGB(0,255,0,0) = red
//
	while (x < 500 && y < 500)
	{
		upd_mlx_pixel_put(&img, x, y, 0x00FF0000);
		x++;
		y++;
	}
	//check the below again, something's wrong
	x = 1000;
	y = 1000;
	while (x > 100, y > 100)
	{
		upd_mlx_pixel_put(&img, x, y, 0x0000FFFF);
		x--;
		y--;
	}
	mlx_put_image_to_window(fract.ptr, fract.window, img.img_ptr, 0, 0);

	mlx_loop(fract.ptr);

}
