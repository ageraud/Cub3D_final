/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_start_main.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agathe <agathe@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 11:57:14 by agathe            #+#    #+#             */
/*   Updated: 2020/09/17 19:07:51 by agathe           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void		check_arguments_next(int ac, char **av)
{
	if ((av[1][ft_strlen(av[1]) - 1] != 'b') ||
	(av[1][ft_strlen(av[1]) - 2] != 'u')
	|| (av[1][ft_strlen(av[1]) - 3] != 'c') ||
	(av[1][ft_strlen(av[1]) - 4] != '.'))
	{
		write(1, "Error\n/!| SECOND ARGUMENT END IS '.cub' /!|\n", 45);
		exit(0);
	}
	if (ac == 3)
	{
		if ((ft_strlen(av[2]) != 6) || av[2][0] != '-' || av[2][1] != '-'
		|| av[2][2] != 's' || av[2][3] != 'a' ||
		av[2][4] != 'v' || av[2][5] != 'e')
		{
			write(1, "Error\n/!| THIRD ARGUMENT IS '--save' /!|\n", 42);
			exit(0);
		}
	}
}

void		check_arguments(int ac, char **av)
{
	if (ac < 2 || ac > 3)
	{
		write(1, "Error\n/!| WRONG NUMBER OF ARGUMENTS /!|\n", 41);
		exit(0);
	}
	if (ac == 2 || ac == 3)
	{
		check_arguments_next(ac, av);
	}
}

int			ft_parsing(int fd, t_a *a, t_parse *parse)
{
	char	*line;

	line = NULL;
	init_parse(parse, a);
	ft_parsing_loop(fd, parse, line);
	check_parsing_elements_error(parse);
	check_first_and_last_line(parse);
	verify_if_global_parse_okay(parse);
	alloc_map(count_line_map(parse), parse);
	compare_lines_difference_in_map(parse);
	check_if_valid_map(parse);
	start_cub3d(a, parse);
	return (0);
}

void		main_loop_hook(t_a *a)
{
	mlx_loop_hook(a->parse.mlx_ptr, raycast_start, a);
	mlx_hook(a->parse.win_ptr, 2, 0, holdinput, a);
	mlx_hook(a->parse.win_ptr, 3, 0, stopinput, a);
	mlx_hook(a->parse.win_ptr, 17, 0, close_window, a);
	mlx_loop(a->parse.mlx_ptr);
}

int			main(int ac, char **av)
{
	int		fd;
	t_a		a;

	check_arguments(ac, av);
	fd = open(av[1], O_RDONLY);
	if (read(fd, 0, 0) < 0)
	{
		write(1, "Error\n/!| FD NOT READ /!|\n", 26);
		close(fd);
		exit(0);
	}
	if (ft_parsing(fd, &a, &a.parse) == -1)
	{
		write(1, "Error\n/!| PARSE ERROR /!|\n", 27);
		close(fd);
		free_tab_map(a.parse.map);
		exit(0);
	}
	raycast_start(&a);
	if (ac == 3)
		save_bmp_screenshot(&a);
	main_loop_hook(&a);
	return (0);
}
