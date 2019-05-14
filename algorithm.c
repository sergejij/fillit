/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubartemi <ubartemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 23:13:05 by ubartemi          #+#    #+#             */
/*   Updated: 2019/05/14 17:25:40 by ubartemi         ###   ########.fr       */
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
}

int		ft_recursive(f_list *current_list, char **map, int size)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (!(current_list))
		return (1);
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (ft_check_and_place(map, j, i, &current_list))
			{
				if (ft_recursive(current_list->next, map, size) > 0)
					return (1);
				else
					ft_clean_tetramin(map, j, i, &current_list);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int		ft_listsize(f_list *begin_list)
{
	int		i;
	f_list	*temp;

	i = 0;
	temp = begin_list;
	if (!begin_list)
		return (0);
	while (temp != 0)
	{
		while (ft_move_tetramin(temp->coord_x, 'b'))
			;
		while (ft_move_tetramin(temp->coord_y, 'b'))
			;
		temp = temp->next;
		i++;
	}
	return (i);
}

int		ft_make_result(f_list *begin)
{
	char	**map;
	f_list	*start;
	int		size;
	int		lst_size;

	size = 2;
	start = begin;
	lst_size = ft_listsize(begin);
	while (lst_size * 4 > size * size)
		size++;
	map = ft_new_map(size);
	while (!(ft_recursive(start, map, size)))
	{
		size++;
		map = ft_copy_map_plus(size);
	}
	ft_print_result(map);
	while (start)
	{
		free(start->coord_x);
		free(start->coord_y);
		start = start->next;
	}
	return (1);
}
