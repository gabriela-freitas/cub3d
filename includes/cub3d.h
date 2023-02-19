/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratinhosujo <ratinhosujo@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 19:28:17 by gafreita          #+#    #+#             */
/*   Updated: 2023/02/19 18:23:56 by ratinhosujo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include "libft.h"
# include "../get_next_line/get_next_line.h"
# include "mlx.h"

#define WIN_H 540
#define WIN_W 960
# define TRUE 1
# define FALSE 0
# define INF 100000
/* INFINITY is supported */


typedef struct	s_mlx {
	void	*img;
	//imagem auxiliar, como isso funcionaria?
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	void	*p_mlx;
	void	*p_mlx_win;
}				t_mlx;


enum e_keys{
	key_W = 119,
	key_S = 115,
	key_A = 97,
	key_D = 100,
	key_ESC = 65307,
	LEFT_ARROW = 65361,
	RIGHT_ARROW = 65363,
};

enum e_events
{
	KEY_PRESS = 2,
	KeyPressMask = 1L << 0,
	DESTROY_NOTIFY = 17,
	ButtonPressMask = 1L << 2
};

enum e_prefix{
	NO,
	SO,
	WE,
	EA,
	F,
	C
};

typedef struct s_difus
{
	int	i;
	int	j;
	int	flag;
}	t_difus;

typedef struct s_draw
{
	int		n;
	int		s;
	int		w;
	int		e;
	char	*n_texture;
	char	*s_texture;
	char	*w_texture;
	char	*e_texture;
}	t_draw;

typedef struct s_raycast
{
	int		hit;
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	int		side_hit;
	int		line_height;	// comprimento da linha vertical
	int		wall_height;	// altura fixa
	int		draw_start;		// pixel from bottom to top that starts wall
	int		draw_end;		// pixel that ends
	double	d_x;
	double	d_y;
	double	cam_x;
	double	ray_x;
	double	ray_y;
	double	fov_x;
	double	fov_y;
	double	dist_x;			// actualiza quando rodas a imagem
	double	dist_y;			// actualiza quando rodas a imagem
	double	p_dir_x;
	double	p_dir_y;
	double	cam_plane_dist;
}	t_raycast;

typedef struct s_player
{
	int			player_i;
	int			player_j;
	double		p_x;		// posicao x do player (actualizar) mas incrementa 0.1
	double		p_y;		// posicao y do player (actualizar) mas incrementa 0.1
	t_raycast	rcast;

}	t_player;

typedef struct s_map
{
	char	**map;
	int		map_height;
}	t_map;

typedef struct s_timers
{
	int	time;
	int	old_time;
}	t_timers;

typedef struct s_parsing
{
	char	**file;
}	t_parse;

typedef struct s_data
{
	int			fd[6];
	t_player	p;
	t_map		map;
	t_difus		difus;
	t_parse		parse;
	t_timers	timers;
	t_draw		draw;
	t_mlx		*mlx;
}	t_data;

int		compare(const char *s1, const char *s2);

// MAP CHECKER - BURNING METHOD
int		burn_map(t_data *data);
int		adjacent_burned(t_data *data, int i, int j);
int		map_test(t_data *data);

void	exit_message(char *message, t_data *data);
void	read_file(char *file_name, t_data *data); //gabi
void	get_file_info(t_data *data);
void	print_map(t_data *data);

// MATHEMATICS
void	init_direction(t_data *data);
void	start_vars(t_data *data, int x, int nbr_rays);
void	calc_vars(t_data *data);
void	calc_draw_vars(t_data *data);
void	calc_steps(t_data *data);
void	mathematics(t_data *data);


//WINDOW MANAGEMENT
void	my_mlx_pixel_put(t_mlx *data, int x, int y, int color);
int		key_code(int keycode);
int		close_win(void);
void	print_square(t_mlx *mlx, int x, int y, int size, int color);
t_mlx 	*config_mlx(void);
void	draw_ray(t_data *data, int nbr_rays, int x);

#endif
