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

//compare two strings
int	ft_strcmp(const char *s1, const char *s2)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	while (s1[i] || s2[i])
	{
		if (str1[i] - str2[i] > 0)
			return (1);
		else if (str1[i] - str2[i] < 0)
			return (-1);
		i++;
	}
	return (0);
}

//set up complex nr for julia fractal
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

//set up t_fract structure with initial data
void	init_all(t_fract *fract, char **argv, int argc)
{
	fract->ptr = mlx_init();
	fract->window = mlx_new_window(fract->ptr, WIDTH, HEIGHT, "fractol");
	fract->img.img_ptr = mlx_new_image(fract->ptr, WIDTH, HEIGHT);
	fract->img.addr = mlx_get_data_addr(fract->img.img_ptr, \
		&fract->img.bits_per_pixel, &fract->img.size_line, &fract->img.endian);
	fract->fractal_type = argv[1];
	fract->hz_move = 1;
	fract->vt_move = 1;
	fract->zoom = 1;
	fract->space = 1;
	fract->y = 0;
	fract->x = 0;
	if (argc == 3)
		init_julia(fract, argv[2][0]);
	else
	{
		fract->c.r = 0.285;
		fract->c.i = 0.01;
	}
}

int	main(int argc, char **argv)
{
	t_fract		fract;

	if (argc < 2 || argc > 3 || (ft_strcmp(argv[1], "mandelbrot") != 0 \
	&& ft_strcmp(argv[1], "julia") != 0))
	{
		ft_printf("\nplease choose one of the following fractal types:\n");
		ft_printf("- mandelbrot\n\
- julia (add 1, 2 or 3 for different fractals)\n\n");
		return (MLXERROR);
	}
	init_all(&fract, argv, argc);
	if (fract.window == NULL)
		return (MLXERROR);
	if (fract.ptr == NULL)
		return (MLXERROR);
	mlx_hook(fract.window, ON_KEYDOWN, 0, ck_keypress, &fract);
	mlx_key_hook(fract.window, ck_arrowpress, &fract);
	mlx_mouse_hook(fract.window, ck_mousedown, &fract);
	mlx_hook(fract.window, ON_DESTROY, 0, ck_exit, &fract);
	new_frame(&fract);
	mlx_loop(fract.ptr);
	return (0);
}
