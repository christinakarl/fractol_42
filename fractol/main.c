/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarl <ckarl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 17:51:00 by ckarl             #+#    #+#             */
/*   Updated: 2023/03/28 17:23:26 by ckarl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

#define MLXERROR 1

void	upd_mlx_pixel_put(t_getdata *data, int x, int y, unsigned int color)
{
	char	*dst;

	dst = data->addr + (y * data->size_line + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	ck_close(t_fract *fract)
{
	mlx_destroy_window(fract->ptr, fract->window);
	return (0);
}

int	main(void)
{
	t_fract			fract;
	t_getdata		img;
	float			x;
	float			y;
	unsigned int	color;

	x = 100;
	y = 100;
	color = mlx_get_color_value(fract.ptr, 0x00FFFF00);

//initialize mlx
	fract.ptr = mlx_init();
	if (fract.ptr == NULL)
		return (MLXERROR);
//set up a window
	fract.window = mlx_new_window(fract.ptr, 800, 800, "fractol");
	if (fract.window == NULL)
	{
		free (fract.window);
		return (MLXERROR);
	}
//set up an image;  returned pointer is starting point for memory area where image is stored; image can be > window in size
	img.img_ptr = mlx_new_image(fract.ptr, 800, 800);
	img.addr = mlx_get_data_addr(img.img_ptr, &img.bits_per_pixel, &img.size_line, &img.endian);
//put pixels to image; 0x00FF000 = red (T,R,G,B);
	while (x++ < 500 && y++ < 500)
		upd_mlx_pixel_put(&img, x, y, color);
//put image to window
	mlx_put_image_to_window(fract.ptr, fract.window, img.img_ptr, 0, 0);


//loop & destroy it when exiting the window to avoid pixels being pushed to non-existent window >>>>>>>>>>>> destroy image also??
	mlx_loop(fract.ptr);

//set up hooks; void mlx_hook(mlx_win_list_t *win_ptr, int x_event, int x_mask, int (*f)(), void *param)
	mlx_key_hook(fract.window, 0L, 2, &ck_close, &fract);

	free(fract.ptr);
}

//look into hooks on 42 docs, try to create your own
