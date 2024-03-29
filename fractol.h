/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarl <ckarl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 17:14:41 by ckarl             #+#    #+#             */
/*   Updated: 2023/04/18 20:06:56 by ckarl            ###   ########.fr       */
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

# define WIDTH 		600
# define HEIGHT		600
# define MLXERROR	1
# define MAX_ITER	500

typedef struct s_img
{
	void	*img_ptr;
	char	*addr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;

}	t_img;

/*r stands for real, i for imaginary*/
typedef struct s_complex
{
	double	r;
	double	i;
}	t_complex;

typedef struct s_fractol
{
	void		*ptr;
	void		*window;
	t_img		img;
	char		*fractal_type;
	int			color;
	t_complex	c;
	t_complex	z;
	double		x;
	double		y;
	double		mouse_x;
	double		mouse_y;
	double		hz_move;
	double		vt_move;
	double		zoom;
	float		space;
}	t_fract;

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
	ON_DESTROY = 17,
	ON_ESC = 53,
	ON_ARROWUP = 126,
	ON_ARROWDOWN = 125,
	ON_ARROWRIGHT = 124,
	ON_ARROWLEFT = 123,
	ON_PLUS = 69,
	ON_MINUS = 78,
	ON_SPACE = 49,
};

int		ft_strcmp(const char *s1, const char *s2);
void	init_all(t_fract *fract, char **argv, int argc);
void	init_julia(t_fract *fract, char c);
int		julia(t_fract *fract);
void	draw_julia(t_fract *fract);
int		mandelbrot(t_fract *fract);
void	draw_mandelbrot(t_fract *fract);
void	iteration_palette(t_fract *fract, unsigned int iter);
void	new_frame(t_fract *fract);
void	upd_mlx_pixel_put(t_img *img, int x, int y, unsigned int color);
int		get_trgb(int t, int r, int g, int b);
int		ck_keypress(int keycode, t_fract *fract);
int		ck_arrowpress(int keycode, t_fract *fract);
int		ck_mousedown(int mousecode, int x, int y, t_fract *fract);
int		ck_exit(t_fract *fract);

#endif
