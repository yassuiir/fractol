/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-nas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 16:00:43 by yait-nas          #+#    #+#             */
/*   Updated: 2024/05/03 15:47:48 by yait-nas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>

# define BLACK 0x000000
# define WHITE 0xFFFFFF
# define RED 0xFF0000
# define GREEN 0x00FF00
# define BLUE 0x0000FF
# define YELLOW 0xFFFF00
# define GRAY 0x808080
# define PINK 0xFFC0CB
# define TEAL 0x008080

typedef struct s_complex
{
	double	real;
	double	im;
}	t_complex;

typedef struct s_fractol
{
	void	*mlx_ptr;
	void	*win;
	void	*img;
	int		bpp;
	int		line_len;
	char	*address;
	int		iterations;
	char	**argv;
	double	ratio;
}	t_fractol;

int			ft_strcmp(const char *s1, const char *s2);
void		initialize(t_fractol *mlx_data, char **argv);
void		fractol(t_fractol *mlx_data);
void		handle_pixel(t_fractol *mlx_data, int i, int j);
void		my_mlx_pixel_put(t_fractol *mlx_data, int color, int i, int j);
t_complex	square_complex(t_complex z);
t_complex	sum_complex(t_complex z1, t_complex z2);
double		scale(double x, double a, double b, double max);
double		ft_atod(char *str);
int			ft_atoi(char *str, int *i, int *sign);
void		mandel_vs_julia(t_complex *z, t_complex *c, t_fractol *mlx_data);
int			ft_isdigit(int c);
int			check(char **argv);
int			check_argument(char *str, int points);
int			keyboard_handler(int keycode, t_fractol *mlx_data);
int			destroy(t_fractol *mlx_data);
int			mouse_handler(int botton, int x, int y, t_fractol *mlx_data);
void		in_de_crease_display_iterations(t_fractol *mlx_data, char c);
void		ft_putnbr(int nbr);
void		ft_putchar(char c);

#endif
