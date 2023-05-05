
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


	// else if (keycode == ON_PLUS)
	// {
	// 	fract->zoom /= 1.8;
	// 	fract->hz_move *= 1.8;
	// 	fract->vt_move *= 1.8;
	// }
	// else if (keycode == ON_MINUS)
	// {
	// 	fract->zoom *= 1.8;
	// 	fract->hz_move /= 1.8;
	// 	fract->vt_move /= 1.8;
	// }


int	ck_keyrelease(int keycode, t_fract *fract)
{
	(void) fract;
	(void) keycode;

	ft_printf("a key was released\n");
	return (0);
}

// void	iteration_palette(t_fract *fract, unsigned int iter)
// {
// 	double	mult;
// 	t_color	color;
// 	double	coef;

// 	color.r = 255;
// 	color.g = 255;
// 	color.b = 255;
// 	mult = log(iter) / log(MAX_ITER);
// 	change_colors(&coef, fract);
// 	if (iter == MAX_ITER)
// 		fract->color = get_trgb(0, coef * color.r, mult * color.g, (1 - mult) * color.b);
// 	else if (iter >= 0 && iter < 3)
// 		fract->color = get_trgb(0, (coef + 0.09) * color.r, (mult) * color.g, (1 - mult) * color.b);
// 	else if (iter % 3 == 1)
// 		fract->color = get_trgb(0, (coef + 0.06) * color.r, (mult + 0.01) * color.g, (1 - mult) * color.b);
// 	else if (iter % 3 == 2)
// 		fract->color = get_trgb(0, (coef + 0.03) * color.r, (mult + 0.03) * color.g, (1 - mult) * color.b);
// 	else if (iter % 3 == 3)
// 		fract->color = get_trgb(0, (coef + 0.01) * color.r, (mult + 0.03) * color.g, (1 - mult) * color.b);
// 	else
// 		fract->color = get_trgb(0, (coef) * color.r, (mult + 0.09) * color.g, (1 - mult) * color.b);
// }

// int	ck_mousemove(int x, int y, t_fract *fract)
// {
// 	(void) fract;

// 	if (x > 0 && x < WIDTH && y > 0 && y < HEIGHT)
// 	{
// 		fract->mouse_x = (double)x;
// 		fract->mouse_y = (double)y;
// 		//  mlx_mouse_get_pos(fract->window, &x, &y);
// 		//  fract->mouse_x = (double)x;
// 		//  fract->mouse_y = (double)y;
// 	}
// 		new_frame(fract);
// 		return (0);
// }
	// if (mousecode == 1)
	// {
	// 	//mlx_mouse_get_pos(fract->window, &(int)fract->mouse_x, &(int)fract->mouse_y);
	// 	fract->mouse_x = x;
	// 	fract->mouse_y = y;
	// }
	// else if (mousecode == 2)
	// 	ft_printf("mouse right\n");


	// 	mlx_string_put(fract.ptr, fract.window, WIDTH / 6, 100, 0x00111111, "Zoom: mouse wheel");
	// mlx_string_put(fract.ptr, fract.window, WIDTH / 6, 115, 0x00111111, "Shifting: arrow keys");
	// if (ft_strcmp(argv[1], "julia") == 0)
	// 	mlx_string_put(fract.ptr, fract.window, WIDTH / 6, 130, 0x00111111, "Julia fractal change: + / -");

					# cd mlx; make clean
				# cd libft; make fclean