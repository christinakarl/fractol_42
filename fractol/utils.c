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



