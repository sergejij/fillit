/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubartemi <ubartemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 19:42:07 by ubartemi          #+#    #+#             */
/*   Updated: 2019/05/15 17:08:50 by aestella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_print_result(char **map)
{
	int k;

	k = 0;
	while (map[k])
	{
		ft_putstr(map[k]);
		ft_putchar('\n');
		k++;
	}
	ft_free_map(map);
}

int		ft_printf_mistake(char *tetramins, t_lst **begin)
{
	int		i;

	i = 0;
	if (!ft_check_square_and_symbols(tetramins, -1))
	{
		ft_putstr("error\n");
		return (0);
	}
	if (!(ft_validation(tetramins, begin, i)))
	{
		ft_putstr("error\n");
		return (0);
	}
	return (1);
}

char	*ft_opening(char **argv)
{
	int		fd;
	int		ret;
	char	*tetramins;

	ret = 0;
	tetramins = NULL;
	fd = open(argv[1], O_RDONLY);
	if (read(fd, NULL, 0)
			|| !(tetramins = (char*)malloc(sizeof(char) * ((26 * 21)))))
	{
		ft_putstr("error\n");
		return (NULL);
	}
	ret = read(fd, tetramins, 546);
	tetramins[ret] = '\0';
	if (ret > 545 || (ret + 1) % 21 != 0)
	{
		ft_putstr("error\n");
		return (NULL);
	}
	close(fd);
	return (tetramins);
}

int		main(int argc, char **argv)
{
	char	*tetramins;
	t_lst	*begin;

	begin = NULL;
	if (argc == 1)
	{
		ft_putstr("usage: fillit input_file\n");
		return (0);
	}
	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	if (!(tetramins = ft_opening(argv)))
		return (0);
	if (!(ft_printf_mistake(tetramins, &begin)))
		return (0);
	ft_strdel(&tetramins);
	ft_make_result(begin);
	return (0);
}
