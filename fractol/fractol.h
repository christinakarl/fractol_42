/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarl <ckarl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 17:14:41 by ckarl             #+#    #+#             */
/*   Updated: 2023/03/24 17:46:42 by ckarl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx/mlx.h"
//# include "libft.h"
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



#endif
