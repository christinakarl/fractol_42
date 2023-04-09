/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarl <ckarl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 17:51:00 by ckarl             #+#    #+#             */
/*   Updated: 2023/04/09 13:25:46 by ckarl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	upd_mlx_pixel_put(t_getdata *data, int x, int y, unsigned int color)
{
	char	*dst;

	dst = data->addr + (y * data->size_line + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	ck_exit(t_fract *fract)
{
	mlx_destroy_window(fract->ptr, fract->window);
	free(fract->ptr);
	exit(0);
	return (0);
}

int	ck_keyrelease(int keycode, t_fract *fract)
{
	(void) fract;
	(void) keycode;

	printf("a key was released\n");
	return (0);
}

int	ck_keypress(int keycode, t_fract *fract)
{
	printf("the key with keycode %d was pressed\n", keycode);
	if (keycode == ON_ESC)
		ck_exit(fract);

	return (0);
}

int	ck_mousedown(int mousecode, t_fract *fract)
{
	(void) fract;
	if (mousecode == 1)
		printf("mouse left\n");
	else if (mousecode == 2)
		printf("mouse right\n");
	else if (mousecode == 4)
	   printf("mouse is scrolling up\n");
	else if (mousecode == 5)
		printf("mouse is scrolling down\n");	

	return (0);
}

int	ck_mousemove(int x, int y, t_fract *fract)
{
	(void) fract;
	if (x >= 0 && x <= 1000 && y >= 0 && y <= 800)
		printf("Hello! mouse moved to %d / %d\n", x, y);
	else
		printf("Bye!\n");
	return (0);
}

int	main(void)
{
	t_fract			fract;
//	t_getdata		img;
	float			x;
	float			y;

	x = 100;
	y = 100;

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


/*set up hooks; void mlx_hook(mlx_win_list_t *win_ptr, int x_event, int x_mask, int (*f)(), void *param)*/

	mlx_hook(fract.window, ON_KEYDOWN, 0, ck_keypress, &fract);
//	mlx_hook(fract.window, ON_MOUSEMOVE, 0, &ck_mousemove, &fract);
	mlx_hook(fract.window, ON_DESTROY, 0, ck_exit, &fract);
	mlx_hook(fract.window, ON_MOUSEDOWN, 0, ck_mousedown, &fract);
	mlx_hook(fract.window, ON_KEYUP, 0, ck_keyrelease, &fract);

	mlx_loop(fract.ptr);

}



/*
//set up an image;  returned pointer is starting point for memory area where image is stored; image can be > window in size
	img.img_ptr = mlx_new_image(fract.ptr, 800, 800);
	img.addr = mlx_get_data_addr(img.img_ptr, &img.bits_per_pixel, &img.size_line, &img.endian);
//put pixels to image; 0x00FF0000 = red (T,R,G,B);
	while (x++ < 500 && y++ < 500)
		upd_mlx_pixel_put(&img, x, y, color);
//put image to window
	mlx_put_image_to_window(fract.ptr, fract.window, img.img_ptr, 0, 0);
*/

/*loop & destroy it when exiting the window to avoid pixels being pushed to non-existent window >>>>>>>>>>>> destroy image also??*/
