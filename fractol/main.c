/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarl <ckarl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 17:51:00 by ckarl             #+#    #+#             */
/*   Updated: 2023/04/18 20:16:48 by ckarl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	new_frame(t_fract *fract)
{
		mlx_clear_window(fract->ptr, fract->window);
		draw_fractal(fract);
}

/*julia:scaling z.i & z.r to the range [-1,5 , 1,5] = commonly used range for julia set
mandelbrot: x and y are used to calculate the corresponding value of c
c.r = based on x, 'WIDTH / 2' is to center image horizontally, '4 / WIDTH' is to scale it to desired size, 4 so that fractal fills entire image area
c.i = based on y, 'HEIGHT / 2' is to center image vertically, '4 / WIDTH' is to scale it to desired size, 4 so that fractal fills entire image area*/
void	draw_fractal(t_fract *fract)
{
	fract->y = 0;
	double	temp_x = 0;
	double	temp_y = 0;

	while (fract->y < HEIGHT)
	{
		fract->x = 0;
		while (fract->x < WIDTH)
		{	if (ft_strcmp(fract->fractal_type, "mandelbrot") == 0)
			{
				fract->c.r = ((fract->x + fract->hz_move) - WIDTH / 2.0) * fract->zoom * 4.0 / WIDTH ;
				fract->c.i = ((fract->y + fract->vt_move) - HEIGHT / 2.0) * fract->zoom * 4.0 / WIDTH ;
				temp_x = fract->mouse_x;
				temp_y = fract->mouse_y;

				if (mandelbrot(fract) == -2)
					fract->color = 255 / MAX_ITER * 0x00000101;
				else
				{
					//fract->color = mandelbrot(fract)  * get_trgb(0, 0, 50, 50) * 255 / MAX_ITER;
					iteration_palette(fract, mandelbrot(fract));
				}
			}
			else if (ft_strcmp(fract->fractal_type, "julia") == 0)
			{
				fract->z.r = ((fract->x + fract->hz_move) - WIDTH / 2.0) * fract->zoom * 4.0 / WIDTH ;
				fract->z.i = ((fract->y + fract->vt_move) - HEIGHT / 2.0) * fract->zoom * 4.0 / WIDTH;
				iteration_palette(fract, julia(fract));
				//fract->color = julia(fract) * get_trgb(0, 0, 50, 50);
			}
			upd_mlx_pixel_put(&fract->img, fract->x, fract->y, fract->color);
			fract->x++;
		}
		fract->y++;
	}

	mlx_put_image_to_window(fract->ptr, fract->window, fract->img.img_ptr, 0, 0);
}

void	init_julia(t_fract *fract, char c)
{
	if (c == '1')
	{
		fract->c.r = -0.8;
		fract->c.i = 0.156;
	}
	else if (c == '2')
	{
		fract->c.r = -0.4;
		fract->c.i = 0.6;
	}
	else if (c == '3')
	{
		fract->c.r = -0.7269;
		fract->c.i = 0.1889;
	}
}

void	init_all(t_fract *fract, char **argv, int argc)
{
	/*initialize mlx --- CHECK LEAKS*/
	fract->ptr = mlx_init();
	/*set up a window --- CHECK LEAKS*/
	fract->window = mlx_new_window(fract->ptr, WIDTH, HEIGHT, "fractol");
	//set up an image;  returned pointer is starting point for memory area where image is stored; image can be > window in size
	fract->img.img_ptr = mlx_new_image(fract->ptr, WIDTH, HEIGHT);
	fract->img.addr = mlx_get_data_addr(fract->img.img_ptr, &fract->img.bits_per_pixel, &fract->img.size_line, &fract->img.endian);
	fract->fractal_type = argv[1];
	fract->hz_move = 1;
	fract->vt_move = 1;
	fract->zoom = 1;
	fract->space = 1;
	if (argc == 3)
		init_julia(fract, argv[2][0]);
	else
	{
		fract->c.r = 0.285 ;
		fract->c.i = 0.01;
	}
}

int	main(int argc, char **argv)
{
	t_fract		fract;

	if (argc < 2 || argc > 3 || (ft_strcmp(argv[1], "mandelbrot") != 0 && ft_strcmp(argv[1], "julia") != 0))
	{
		ft_printf("\nplease choose one of the following fractal types:\n\n- mandelbrot\n- julia (indicate 1, 2 or 3 for different fractals)\n\n");
		return (MLXERROR);
	}
	init_all(&fract, argv, argc);
	if (fract.window == NULL)
		return (MLXERROR);
	if (fract.ptr == NULL)
		return (MLXERROR);

/*set up hooks; void mlx_hook(mlx_win_list_t *win_ptr, int x_event, int x_mask, int (*f)(), void *param)*/

	mlx_hook(fract.window, ON_KEYDOWN, 0, ck_keypress, &fract);
	mlx_hook(fract.window, ON_MOUSEMOVE, 0, ck_mousemove, &fract);
	mlx_hook(fract.window, ON_MOUSEDOWN, 0, ck_mousedown, &fract);
	mlx_hook(fract.window, ON_DESTROY, 0, ck_exit, &fract);
	// mlx_hook(fract.window, ON_KEYUP, 0, ck_keyrelease, &fract);

/*draw fractal with designated set*/

	new_frame(&fract);
	mlx_loop(fract.ptr);


	mlx_string_put(fract.ptr, fract.window, WIDTH / 6, 100, 0x00111111, "Zoom: mouse wheel");
	mlx_string_put(fract.ptr, fract.window, WIDTH / 6, 115, 0x00111111, "Shifting: arrow keys");
	if (ft_strcmp(argv[1], "julia") == 0)
		mlx_string_put(fract.ptr, fract.window, WIDTH / 6, 130, 0x00111111, "Julia fractal change: + / -");


	return (0);
}
