/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubartemi <ubartemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 23:09:53 by aestella          #+#    #+#             */
/*   Updated: 2019/05/15 15:51:04 by aestella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_new_map(int len)
{
	int		i;
	char	**map;

	i = 0;
	if (!(map = (char**)malloc(sizeof(char*) * (len + 1))))
		return (NULL);
	while (i < len)
	{
		map[i] = ft_strnew(len);
		ft_memset(map[i], '.', len);
		i++;
	}
	map[i] = NULL;
	return (map);
}

int		ft_check_and_place(char **map, int j, int i, f_list **current_list)
{
	int count;
	int *x;
	int *y;
	int size;

	size = ft_strlen(map[0]);
	count = 0;
	x = (*current_list)->coord_x;
	y = (*current_list)->coord_y;
	while (count < 4)
	{
		if (i + y[count] >= size || i + y[count] >= size)
			return (0);
		if ((map[i + y[count]] != NULL || map[i + y[count]][j +
			x[count]] != '\0') && map[i + y[count]][j + x[count]] != '.')
			return (0);
		count++;
	}
	count = 0;
	while (count < 4)
	{
		map[i + y[count]][j + x[count]] = (*current_list)->letter;
		count++;
	}
	return (1);
}

int		ft_move_tetramin(int *arr, char direct)
{
	int i;

	i = -1;
	if (direct == 'b')
	{
		if ((arr[0] - 1 < 0) || (arr[1] - 1 < 0)
				|| (arr[2] - 1 < 0) || (arr[3] - 1 < 0))
			return (0);
		while (i++ < 3)
			if (arr[i] - 1 >= 0)
				arr[i] -= 1;
	}
	return (1);
}

char	**ft_copy_map_plus(int size)
{
	char	**new_map;
	int		i;

	i = 0;
	new_map = ft_new_map(size);
	return (new_map);
}

void	ft_clean_tetramin(char **map, int j, int i, f_list **current_list)
{
	int count;
	int *x;
	int *y;

	count = 0;
	x = (*current_list)->coord_x;
	y = (*current_list)->coord_y;
	while (count < 4)
	{
		map[i + y[count]][j + x[count]] = '.';
		count++;
	}
}
