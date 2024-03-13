/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarl <ckarl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 17:20:25 by ckarl             #+#    #+#             */
/*   Updated: 2023/04/11 17:36:48 by ckarl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//exits programme and frees all allocated pointers
int	ck_exit(t_fract *fract)
{
	mlx_destroy_window(fract->ptr, fract->window);
	mlx_destroy_image(fract->ptr, fract->img.img_ptr);
	exit(0);
	return (0);
}

//controls all key events such as moving around,
//color changes and exit through ESC
int	ck_keypress(int keycode, t_fract *fract)
{
	if (keycode == ON_PLUS)
	{
		fract->c.i *= 1.01;
		fract->c.r /= 1.01;
	}
	else if (keycode == ON_MINUS)
	{
		fract->c.i /= 1.01;
		fract->c.r *= 1.01;
	}
	else if (keycode == ON_ESC)
		ck_exit(fract);
	else if (keycode == ON_SPACE)
	{
		if (fract->space == 1)
			fract->space = 2;
		else if (fract->space == 2)
			fract->space = 3;
		else
			fract->space = 1;
	}
	new_frame(fract);
	return (0);
}

int	ck_arrowpress(int keycode, t_fract *fract)
{
	if (keycode == ON_ARROWRIGHT)
		fract->hz_move += 50;
	else if (keycode == ON_ARROWLEFT)
		fract->hz_move -= 50;
	else if (keycode == ON_ARROWUP)
		fract->vt_move -= 50;
	else if (keycode == ON_ARROWDOWN)
		fract->vt_move += 50;
	new_frame(fract);
	return (0);
}

//controls zoom in & out
int	ck_mousedown(int mousecode, int x, int y, t_fract *fract)
{
	(void) fract;
	(void) x;
	(void) y;
	if (mousecode == ON_MOUSEDOWN)
	{
		fract->zoom *= 1.5;
		fract->hz_move /= 1.5;
		fract->vt_move /= 1.5;
	}
	else if (mousecode == ON_MOUSEUP)
	{
		fract->zoom /= 1.5;
		fract->hz_move *= 1.5;
		fract->vt_move *= 1.5;
	}
	new_frame(fract);
	return (0);
}
