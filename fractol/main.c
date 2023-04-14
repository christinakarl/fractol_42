/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarl <ckarl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 17:51:00 by ckarl             #+#    #+#             */
/*   Updated: 2023/04/14 12:46:39 by ckarl            ###   ########.fr       */
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


void	iteration_palette(t_fract *fract, unsigned int iter)
{
	if (iter >= 0 && iter <= 100)
		fract->color = 0x0000FF00 * iter;
	else if (iter > 100 && iter <= 200)
		fract->color = 0x000FF000 * iter;
	else if (iter > 200 && iter <= 300)
		fract->color = 0x000000FF * iter;
	else if (iter > 300 && iter <= 400)
		fract->color = 0x00FF0000 * iter;
	else if (iter > 400 && iter <= 500)
		fract->color = 0x00010101 * iter;

}
/*algo: f(x) = z^2 + c; start with z.x & z.y = 0; need to calculate f(z) for each complex number c in the image*/
int	mandelbrot(t_complex c)
{
	unsigned int	iter;
	t_complex		z;
	double			temp;

	iter = 0;
	z.r = 0;
	z.i = 0;
	temp = 0;
	while ((z.r * z.r + z.i * z.i) < 4 && iter < 1000)
	{
		temp = z.r;
		z.r = z.r * z.r - z.i * z.i + c.r;
		z.i = 2 * temp * z.i + c.i;

		iter++;
	}

	return (iter);
}

/*x and y are used to calculate the corresponding value of c
c.r = based on x, 'WIDTH / 2' is to center image horizontally, '4 / WIDTH' is to scale it to desired size, 4 so that fractal fills entire image area
c.i = based on y, 'HEIGHT / 2' is to center image vertically, '4 / WIDTH' is to scale it to desired size, 4 so that fractal fills entire image area*/
void	draw_fractal(t_fract *fract)
{
	double				x;
	double				y;
//	unsigned int	iter;
	t_complex		c;

	fract->color = 0x00010101;
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		 {	
			c.r = (x - WIDTH / 2.0) * 4.0 / WIDTH;
			c.i = (y - HEIGHT / 2.0) * 4.0 / WIDTH;
		//	iteration_palette(fract, mandelbrot(c));
			fract->color = mandelbrot(c) * 0x00010101;	
			upd_mlx_pixel_put(&fract->img, x, y, fract->color);
			x++;
		}
		y++;
	}
}

int	main(void)
{
	t_fract			fract;
	float			x;
	float			y;

	x = 0;
	y = 0;
	fract.color = 0x000F00F0;

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
	fract.img.img_ptr = mlx_new_image(fract.ptr, WIDTH, HEIGHT);
	fract.img.addr = mlx_get_data_addr(fract.img.img_ptr, &fract.img.bits_per_pixel, &fract.img.size_line, &fract.img.endian);



/*set up hooks; void mlx_hook(mlx_win_list_t *win_ptr, int x_event, int x_mask, int (*f)(), void *param)*/

	mlx_hook(fract.window, ON_KEYDOWN, 0, ck_keypress, &fract);
//	mlx_hook(fract.window, ON_MOUSEMOVE, 0, &ck_mousemove, &fract);
	mlx_hook(fract.window, ON_DESTROY, 0, ck_exit, &fract);
	mlx_hook(fract.window, ON_MOUSEDOWN, 0, ck_mousedown, &fract);
	mlx_hook(fract.window, ON_KEYUP, 0, ck_keyrelease, &fract);

/*draw fractal with designated set*/
	draw_fractal(&fract);
	mlx_put_image_to_window(fract.ptr, fract.window, fract.img.img_ptr, 0, 0);

	mlx_loop(fract.ptr);
	
	return (0);
}


/*
int	render_all(t_fract *fract)
{
	render_background(fract, fract->color);

	//put image to window
	mlx_put_image_to_window(fract->ptr, fract->window, fract->img.img_ptr, 0, 0);

	return (0);
}*/

/*
	while (1)
	{
		mlx_clear_window(fract.ptr, fract.window);
		render_background(&fract, fract.color);
		mlx_put_image_to_window(fract.ptr, fract.window, fract.img.img_ptr, 0, 0);
		mlx_do_sync(fract.ptr);
		fract.color -= 5;
	}
*/
