/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarl <ckarl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 17:14:41 by ckarl             #+#    #+#             */
/*   Updated: 2023/03/28 16:13:12 by ckarl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx/mlx.h"
//# include "libft.h"
# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct	s_fractol
{
	void	*ptr;
	void	*window;

} t_fract;

typedef struct s_getdata
{
	void	*img_ptr;
	char	*addr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
} t_getdata;

enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY =17
};

#endif
