/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubartemi <ubartemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 23:13:05 by ubartemi          #+#    #+#             */
/*   Updated: 2019/05/15 17:08:50 by aestella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_free_map(char **map)
{
	int i;

	i = 0;
	while (map[i])
	{
		ft_strdel(&(map[i]));
		i++;
	}
	free(map);
	map = NULL;
}

void	ft_free_list(t_lst **begin)
{
	t_lst *tmp;
	t_lst *tmp1;

	tmp = *begin;
	while (tmp)
	{
		tmp1 = tmp->next;
		free(tmp->coord_x);
		free(tmp->coord_y);
		free(tmp);
		tmp = tmp1;
	}
	*begin = NULL;
}

int		ft_recursive(t_lst *current_list, char **map, int size)
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

int		ft_listsize(t_lst *begin_list)
{
	int		i;
	t_lst	*temp;

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

int		ft_make_result(t_lst *begin)
{
	char	**map;
	char	**tmp;
	t_lst	*start;
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
		tmp = ft_copy_map_plus(size);
		ft_free_map(map);
		map = tmp;
		tmp = NULL;
	}
	ft_print_result(map);
	ft_free_list(&start);
	return (1);
}
