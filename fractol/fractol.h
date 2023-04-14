/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarl <ckarl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 17:14:41 by ckarl             #+#    #+#             */
/*   Updated: 2023/04/14 15:31:42 by ckarl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx/mlx.h"
# include "libft/libft.h"
# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>

# define WIDTH 		1000
# define HEIGHT		800
# define MLXERROR	1

typedef struct s_img
{
	void	*img_ptr;
	char	*addr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
} t_img;

/*r stands for real, i for imaginary*/
typedef struct	s_complex
{
	double	r;
	double	i;
} t_complex;

typedef struct	s_fractol
{
	void			*ptr;
	void			*window;
	t_img			img;
	unsigned int	color;

} t_fract;

enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_MOUSENTER = 7,
	ON_MOUSELEAVE = 8,
	ON_FOCUSIN = 9,
	ON_FOCUSOUT = 10,
	ON_EXPOSE = 12,
	ON_DESTROY = 17,
	ON_RESIZE = 25,
	ON_ESC = 53,
	ON_ARROWUP = 126,
	ON_ARROWDOWN = 125,
	ON_ARROWRIGHT = 124,
	ON_ARROWLEFT = 123,
	ON_CMD = 256,
	ON_PLUS = 69,
	ON_MINUS = 78,
	ON_SPACE = 49,
};

int	ck_exit(t_fract *fract);
int	ck_keyrelease(int keycode, t_fract *fract);
int	ck_keypress(int keycode, t_fract *fract);
int	ck_mousedown(int mousecode, t_fract *fract);
int	ck_mousemove(int x, int y, t_fract *fract);

#endif
