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

	ft_printf("a key was released\n");
	return (0);
}

int	ck_keypress(int keycode, t_fract *fract)
{
	if (keycode == ON_ARROWRIGHT)
		fract->hz_move += 50 * fract->zoom;
	else if (keycode == ON_ARROWLEFT)
		fract->hz_move -= 50 * fract->zoom;
	else if (keycode == ON_ARROWUP)
		fract->vt_move -= 50 * fract->zoom;
	else if (keycode == ON_ARROWDOWN)
		fract->vt_move += 50 * fract->zoom;
	else if (keycode == ON_PLUS)
		fract->zoom /= 1.8;
	else if (keycode == ON_MINUS)
		fract->zoom *= 1.8;
	else if (keycode == ON_ESC)
	{
		ft_printf("you exited the program\n");
		ck_exit(fract);
	}
	ft_printf("the key with keycode %d was pressed\n", keycode);
	new_frame(fract);
	return (0);
}

// //check the variables given to this function
int	ck_mousedown(int mousecode, int x, int y, t_fract *fract)
{
	(void) fract;

	if (mousecode == 1)
	{
		//mlx_mouse_get_pos(fract->window, &(int)fract->mouse_x, &(int)fract->mouse_y);
		fract->mouse_x = x;
		fract->mouse_y = y;
		ft_printf("%f\n", fract->mouse_x);
		ft_printf("%f\n", fract->mouse_y);
	}
	else if (mousecode == 2)
		ft_printf("mouse right\n");
	else if (mousecode == ON_MOUSEDOWN)
	{
		fract->zoom *= 1.5;
		// fract->c.i += 0.1;
		// fract->c.r += 0.1;
		ft_printf("mouse is zooming out\n");
	}
	else if (mousecode == ON_MOUSEUP)
	{
		fract->zoom *= 0.5;
		// fract->c.i -= 0.01;
		// fract->c.r -= 0.01;
		ft_printf("mouse is zooming in\n");
	}

	new_frame(fract);
	return (0);
}

int	ck_mousemove(int x, int y, t_fract *fract)
{
	(void) fract;

	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		fract->mouse_x = (double)x;
		fract->mouse_y = (double)y;
		//  mlx_mouse_get_pos(fract->window, &x, &y);
		//  fract->mouse_x = (double)x;
		//  fract->mouse_y = (double)y;
		// fract->c.i *= 0.1;
		// fract->c.r *= 0.1;

	}
		new_frame(fract);
		return (0);
}
