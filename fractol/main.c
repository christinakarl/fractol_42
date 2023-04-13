/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarl <ckarl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 17:51:00 by ckarl             #+#    #+#             */
/*   Updated: 2023/04/13 14:32:06 by ckarl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	upd_mlx_pixel_put(t_img *img, int x, int y, unsigned int color)
{
	char	*dst;

	dst = img->addr + (y * img->size_line + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

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
/*
int	render_all(t_fract *fract)
{
	render_background(fract, fract->color);

	//put image to window
	mlx_put_image_to_window(fract->ptr, fract->window, fract->img.img_ptr, 0, 0);

	return (0);
}*/

int	main(void)
{
	t_fract			fract;
	float			x;
	float			y;

	x = 100;
	y = 100;
	fract.color = 0x000F00F0;

//((red << 16) | (green << 8) | blue);
/*initialize mlx*/
	fract.ptr = mlx_init();
	if (fract.ptr == NULL)
		return (MLXERROR);
/*set up a window*/
	fract.window = mlx_new_window(fract.ptr, WIDTH, HEIGHT, "fractol");
	if (fract.window == NULL)
	{
		free (fract.window);
		return (MLXERROR);
	}

//set up an image;  returned pointer is starting point for memory area where image is stored; image can be > window in size
	fract.img.img_ptr = mlx_new_image(fract.ptr, 800, 800);
	fract.img.addr = mlx_get_data_addr(fract.img.img_ptr, &fract.img.bits_per_pixel, &fract.img.size_line, &fract.img.endian);



/*set up hooks; void mlx_hook(mlx_win_list_t *win_ptr, int x_event, int x_mask, int (*f)(), void *param)*/

	mlx_hook(fract.window, ON_KEYDOWN, 0, ck_keypress, &fract);
//	mlx_hook(fract.window, ON_MOUSEMOVE, 0, &ck_mousemove, &fract);
	mlx_hook(fract.window, ON_DESTROY, 0, ck_exit, &fract);
	mlx_hook(fract.window, ON_MOUSEDOWN, 0, ck_mousedown, &fract);
	mlx_hook(fract.window, ON_KEYUP, 0, ck_keyrelease, &fract);

	while (1)
	{
		mlx_clear_window(fract.ptr, fract.window);
		render_background(&fract, fract.color);
		mlx_put_image_to_window(fract.ptr, fract.window, fract.img.img_ptr, 0, 0);
		mlx_do_sync(fract.ptr);
		fract.color -= 5;
	}

	mlx_loop(fract.ptr);
	
	return (0);
}
	
