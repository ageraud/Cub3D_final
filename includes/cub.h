/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agathe <agathe@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 01:15:53 by ageraud           #+#    #+#             */
/*   Updated: 2020/09/17 13:36:16 by agathe           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include "../minilibx/mlx.h"
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <math.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>

# define BUFFER_SIZE 	32
# define NO				0
# define SO				1
# define WE				2
# define EA				3
# define SP				4

typedef struct		s_img
{
	void			*image_ptr;
	int				*data;
	int				bits_per_pixel;
	int				size_line;
	int				endian;
	int				img_width;
	int				img_height;
}					t_img;

typedef struct		s_sp
{
	double			sprite_pos_x;
	double			sprite_pos_y;
	double			sprite_dist;
}					t_sp;

typedef struct		s_parse
{
	int				resx;
	int				resy;
	char			*no;
	char			*so;
	char			*we;
	char			*ea;
	char			*sprite;
	int				floor;
	int				ceiling;
	char			**map;
	char			*joinmap;
	int				playerposx;
	int				playerposy;
	int				width_map;
	int				height_map;
	int				nbr_pixel_width;
	int				nbr_pixel_height;
	int				square_color;
	int				square_pos_x;
	int				square_pos_y;
	char			letter;
	void			*mlx_ptr;
	void			*win_ptr;
	void			*new_img;
	int				*pixel;
	int				bits_per_pixel;
	int				size_line;
	int				endian;
	int				nbr_of_sprite;
	int				error_parsing;
	int				r;
	int				g;
	int				b;
	int				unvalid_nbr;
	int				i;
	int				xtmp;
	int				max_width;
	int				max_height;
	int				first_line;
	int				second_line;
}					t_parse;

typedef struct		s_ray
{
	t_img			img[5];
	double			pos_x;
	double			pos_y;
	double			dir_x;
	double			dir_y;
	double			plane_x;
	double			plane_y;
	double			w;
	double			h;
	double			camera_x;
	double			ray_dir_x;
	double			ray_dir_y;
	int				x;
	int				y;
	int				map_x;
	int				map_y;
	double			side_dist_x;
	double			side_dist_y;
	double			delta_dist_x;
	double			delta_dist_y;
	double			perp_wall_dist;
	int				step_x;
	int				step_y;
	int				hit;
	int				side;
	int				line_height;
	int				draw_start;
	int				draw_end;
	double			frame_time;
	double			move_speed;
	double			rot_speed;
	double			old_dir_x;
	double			old_plane_x;
	double			wall_x;
	int				tex_x;
	int				texture_nb;
	double			step;
	double			tex_pos;
	int				tex_y;
	int				color;
	double			sprite_x;
	double			sprite_y;
	int				sprite_tex;
	double			sp_x;
	double			sp_y;
	double			sp_inv_det;
	double			sp_transform_x;
	double			sp_transform_y;
	int				sp_screen_x;
	int				sp_height;
	int				sp_draw_start_y;
	int				sp_draw_end_y;
	int				sp_width;
	int				sp_draw_start_x;
	int				sp_draw_end_x;
	int				sp_tex_x;
	int				sp_tex_y;
}					t_ray;

typedef struct		s_key
{

	int				w;
	int				a;
	int				s;
	int				d;
	int				right;
	int				left;
	int				shift_l;
	int				space;
	int				ctrl_l;
	int				escape;
	int				key_w;
	int				key_a;
	int				key_s;
	int				key_d;
	int				key_right;
	int				key_left;
	int				key_shift_left;
	int				key_space;
	int				key_ctrl_left;
	int				key_escape;

}					t_key;

typedef struct		s_bmph
{
	unsigned char	header_file_type[2];
	int				header_file_size;
	short			header_reserved1;
	short			header_reserved2;
	unsigned int	header_pixel_data_offset;
}					t_bmph;

typedef struct		s_bmpi
{
	unsigned int	info_header_size;
	unsigned int	info_image_width;
	unsigned int	info_image_height;
	short int		info_planes;
	short int		info_bits_per_pixel;
	unsigned int	info_compression;
	unsigned int	info_image_size;
	unsigned int	info_x_pixels_per_meter;
	unsigned int	info_y_pixels_per_meter;
	unsigned int	info_total_colors;
	unsigned int	info_important_colors;
}					t_bmpi;

typedef struct		s_rgb
{
	unsigned char	red;
	unsigned char	green;
	unsigned char	blue;
}					t_rgb;

typedef struct		s_a
{
	t_parse			parse;
	t_ray			ray;
	t_key			key;
	t_sp			*sp;
	t_bmph			bmph;
	t_bmpi			bmpi;
	t_rgb			rgb;
	double			*buf;

}					t_a;

int					get_next_line(int fd, char **line);
int					backslash_n(char *buf);
char				*ft_strdup_m(const char *s1);
char				*ft_strjoin_m(char *s1, char const *s2);
size_t				ft_strlen_m(const char *s);
char				*ft_substr_m(char const *s, unsigned int start,
					size_t len);
int					next_gnl(char **str_temp, char **line, int fd);
int					free_str_temp(char **str_temp, int fd);
void				*ft_calloc(size_t count, size_t size);
void				ft_bzero(void *s, size_t n);
char				**ft_split(char const *s, char c);
int					ft_isdigit(int c);
char				*ft_strdup(const char *s1);
char				*ft_substr(char const *s, unsigned int start,
					size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
size_t				ft_strlen(const char *s);
int					raycast_start(t_a *a);
void				init_ray(t_ray *ray, t_parse *parse);
void				convert_north_texture(t_ray *ray, t_parse *parse);
void				convert_south_texture(t_ray *ray, t_parse *parse);
void				convert_west_texture(t_ray *ray, t_parse *parse);
void				convert_east_texture(t_ray *ray, t_parse *parse);
void				convert_sprite_texture(t_ray *ray, t_parse *parse);
void				convert_texture_to_img(t_ray *ray, t_parse *parse);
int					close_window(t_a *a);
void				put_bmp_color(int fd, t_parse *parse, t_rgb *rgb);
void				header_bmp(t_a *a);
void				save_bmp_screenshot(t_a *a);
void				free_tab_map(char **map);
void				free_all(t_a *a);
void				ft_atoi_m_next(const char *nptr, int *i, long *result,
					long *sign);
int					ft_atoi_m(const char *nptr, int *i);
void				init_parse_next(t_parse *parse, t_a *a);
void				init_parse(t_parse *parse, t_a *a);
int					is_the_start_of_the_map(char *line);
void				alloc_map(int nbr_of_line_map, t_parse *parse);
int					count_line_map(t_parse *parse);
void				join_map(t_parse *parse, char *line);
int					read_map_and_join(t_parse *parse, char *line, int fd);
void				join_line_map(t_parse *parse, char *line, int fd, int ret);
void				ft_parse_tex_nextbis(char *line, char **textures, int *i,
					int temp);
void				ft_parse_tex_next(char *line, char **textures, int *i);
int					ft_parse_texture(char *line, char **textures,
					t_parse *parse);
void				ft_color_parse_nextbis(char *line, int *color,
					t_parse *parse, int i);
void				ft_color_parse_next(char *line, int *color, t_parse *parse,
					int i);
int					ft_color_parse(char *line, int *color,
					t_parse *parse);
void				resize_screen(t_parse *parse);
void				ft_parse_resolution_next(char *line, t_parse *parse,
					int i);
int					ft_parse_resolution(char *line, t_parse *parse);
int					ft_global_parse(char *line, t_parse *p);
void				check_right_one(int ytmp, int xtmp, t_parse *parse);
void				check_left_one(int ytmp, int xtmp, t_parse *parse);
void				check_top_one(int ytmp, int xtmp, t_parse *parse);
void				check_down_one(int ytmp, int xtmp, t_parse *parse);
void				check_if_char_surronded_by_one(int y, int x,
					t_parse *parse);
void				check_if_valid_caractere(int y, int x, t_parse *parse);
int					check_if_valid_player(int y, int x, int player,
					t_parse *parse);
void				check_if_only_one_player(int player);
void				check_first_and_last_line_next(t_parse *parse, int i);
void				check_first_and_last_line(t_parse *parse);
void				check_if_valid_map(t_parse *parse);
void				verify_if_global_parse_okay(t_parse *parse);
int					count_map_witdh_and_height(t_parse *parse);
int					convert_map_into_resolution(t_parse *parse);
int					holdinput(int key, t_a *a);
int					stopinput(int key, t_a *a);
void				create_new_image(t_parse *parse);
int					start_cub3d(t_a *a, t_parse *parse);
void				check_pipe_joinmap(t_parse *parse);
void				check_parsing_elements_error(t_parse *parse);
void				ft_parsing_loop(int fd, t_parse *parse, char *line);
void				check_arguments_next(int ac, char **av);
void				check_arguments(int ac, char **av);
int					main(int ac, char **av);
void				alloc_player_direction(t_ray *ray, t_parse *parse);
void				alloc_player_plane(t_ray *ray, t_parse *parse);
void				init_data_ray(t_ray *r);
void				calculate_side_dist(t_ray *r);
void				ray_hits_the_wall(t_ray *r, t_parse *parse);
void				dist_ray_to_wall(t_ray *r);
void				draw_vertical_line(t_parse *parse, t_ray *r);
void				print_wall_color_next(t_parse *parse, t_ray *r);
void				print_wall_color(t_parse *parse, t_ray *r);
void				init_key(t_key *k);
void				key_values(t_ray *r, t_key *key);
void				vertical_move(t_a *a);
void				angle_move_right(t_a *a);
void				angle_move_left(t_a *a);
void				angle_move(t_a *a);
void				horizontal_move(t_a *a);
int					close_window(t_a *a);
void				define_move_around(t_a *a);
void				sprite_pos_and_dist_next(t_a *a, int x, int y, int i);
void				find_sprite_pos_and_dist(t_a *a, t_parse *parse);
void				sort_dist_sprite(t_a *a, t_parse *parse);
void				calculate_sprite_next(t_ray *r);
void				calculate_sprite(t_a *a, t_ray *r, int i);
void				draw_sprite_next(t_a *a, int c, int d, int color);
void				draw_sprite(t_a *a, t_ray *r);
void				raycasting_sprite(t_a *a, t_ray *r, t_parse *parse);
void				raycasting(t_a *a, t_ray *r, t_parse *parse, t_key *key);
int					raycast_start(t_a *a);
void				init_ray(t_ray *ray, t_parse *parse);
void				close_exit(int fd, t_a *a);
void				compare_lines_diff_nextbis(t_parse *parse,
					int *x, int *y, int diff);
void				compare_lines_diff_next(t_parse *parse, int x, int y,
					int diff);
void				compare_lines_difference_in_map(t_parse *parse);

#endif
