
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