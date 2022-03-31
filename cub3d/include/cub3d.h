/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzona <hzona@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 19:34:29 by cdarrell          #+#    #+#             */
/*   Updated: 2021/12/28 13:31:01 by hzona            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../mlx_linux/mlx.h"
# include "../libft/include/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <errno.h>
# include <math.h>

//# define LINUX
# define PI 3.14159265 

typedef struct s_draw
{
	int		x;
	int		y;
	double	angle;
	double	angle_start;
	double	angle_end;
	double	angle_step;
	double	cos;
	double	sin;
	double	deltadistx;
	double	deltadisty;
	double	sidedistx;
	double	sidedisty;
	int		stepx;
	int		stepy;
	int		mapx;
	int		mapy;
	int		hit;
	int		door;
	int		side;
	double	perpwalldist;
	int		lineheight;
	double	wallx;
	int		drawstart;
	int		drawend;
	int		texx;
	double	step;
	double	texpos;
	int		texy;
	int		tn;
}	t_draw;

typedef struct s_sprite
{
	int		x;
	int		y;
	int		drawstartx;
	int		drawendx;
	int		spr_tex;
	double	dx;
	double	dy;
	double	spritex;
	double	spritey;
	double	angle;
	double	perpwalldist;
	int		lineheight;
	int		lineheightend;
	int		drawstarty;
	int		drawendy;
	int		center;
	int		x_start;
	int		xx_start;
	int		x_end;	
	int		texx;
	int		color;
	int		yy;
	int		texy;
}t_sprite;

typedef struct s_tex
{
	char	*path;
	void	*ptr;
	int		*data;
	int		width;
	int		height;
	int		bpp;
	int		size_l;
	int		endian;
	int		count_width;
}t_tex;

typedef struct s_player
{
	double		x;
	double		y;
	double		angle;
	double		view;
	double		movespeed;
	double		rotspeed;
	double		*zbuffer;
	int			mouse_x;
	t_list		*spr;
	t_list		*door;
}t_player;

typedef struct s_map
{
	int				row;
	int				col;	
	int				f_colour;
	int				c_colour;
	char			*wall_texture_path[4];
	char			*door_texture_path;
	char			*sprites_texture_path[8];
	int				sprite_tex_num;
	int				player_x;
	int				player_y;
	char			player_z;
	int				sprites_num;
	int				doors_num;
	char			**arr;
	t_tex			*tex;
	t_tex			*spr;
	t_tex			*door;
}t_map;

typedef struct s_data {
	void	*img;
	int		*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;	
}t_data;

typedef struct s_cub3d
{
	t_map			*map;
	t_player		*player;
	int				mlx_width;
	int				mlx_height;	
	void			*mlx;
	void			*mlx_win;
	char			active_key[2560];
	int				mouse;
	t_data			img;
}t_cub3d;

//init
t_cub3d	*cub_init(char *map_file);

//parsing
t_map	*parsing_map(char *map_file);
t_list	*parsing_read_map(char *map_file, t_map *map);
void	parsing_read_line(int rd, char *line, t_map *map, t_list **head_map);
int		parsing_texture(char *s, t_map *map);
void	parsing_texture_main(char **split_line, t_map *map);
void	parsing_texture_sprite(char **split_line, t_map *map);
void	parsing_list_to_array(t_list *head, t_map *map);
void	parsing_check_map_circuit(t_map *map);

//mlx
int		cub_draw(t_cub3d *cub, int move);
void	cub_hook(t_cub3d *cub);
int		cub_close(void);

//update_move
void	open_door(t_cub3d *cub, int frame, int i);
void	update_move(t_cub3d	*cub);

void	cub_draw_wall(t_cub3d *cub);
void	cub_draw_wall2(t_cub3d *cub, t_draw *draw);
void	cub_check_sprite(t_cub3d *cub, t_map *map,
			t_draw *draw, t_player *player);

void	cub_draw_sprite(t_cub3d *cub, int move);

void	cub_check_door(t_cub3d *cub,
			t_draw *draw, t_player *player);

//utils
void	cub_error(char *error);

//print
void	tttt_print_parsing(t_map *map);
void	tttt_print_map(t_map *map);

//lst
void	cub_draw_texture2(t_cub3d *cub, t_sprite *spr, int move);

void	cub_draw_minimap(t_cub3d *cub);
#endif
