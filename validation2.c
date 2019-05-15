/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubartemi <ubartemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 20:45:22 by ubartemi          #+#    #+#             */
/*   Updated: 2019/05/15 14:47:29 by aestella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_add_coordinats2(char *one_str_tetr,
		int *coordinats_x, int *coordinats_y, int k)
{
	int i;
	int y;
	int x;

	i = 0;
	y = 0;
	x = 0;
	while (one_str_tetr[i])
	{
		if (one_str_tetr[i] == '\n')
		{
			y++;
			i++;
			x = 0;
			continue;
		}
		if (one_str_tetr[i] == '#')
		{
			coordinats_x[k] = x;
			coordinats_y[k++] = y;
		}
		i++;
		x++;
	}
}

int		ft_add_coordinats(f_list *current, char *one_str_tetr)
{
	int *coordinats_x;
	int *coordinats_y;
	int k;

	k = 0;
	if (!(coordinats_x = (int*)malloc(sizeof(int) * (4)))
			|| !(coordinats_y = (int*)malloc(sizeof(int) * (4))))
		return (0);
	ft_add_coordinats2(one_str_tetr, coordinats_x, coordinats_y, k);
	current->coord_x = coordinats_x;
	current->coord_y = coordinats_y;
	return (1);
}

f_list	*ft_create_tetramin(char *one_square_str, int counter_letter)
{
	int		i;
	int		j;
	f_list	*new_elem;

	i = 0;
	j = 0;
	if (!(ft_check_connect_and_hashs(one_square_str)))
		return (NULL);
	if (!(new_elem = (f_list*)malloc(sizeof(f_list))))
		return (NULL);
	new_elem->letter = 'A' + counter_letter;
	new_elem->next = NULL;
	if (!(ft_add_coordinats(new_elem, one_square_str)))
		return (NULL);
	ft_strdel(&one_square_str);
	return (new_elem);
}

int		ft_validation(char *tetramins, f_list **begin, int counter_letter)
{
	int		i;
	char	*one_square_str;
	f_list	*tmp;
	f_list	*new_tetramin;
	char	*all_tetramin_cpy;

	i = 21;
	all_tetramin_cpy = ft_strdup(tetramins);
	one_square_str = ft_tetramin_sub(all_tetramin_cpy);
	if (!(new_tetramin = ft_create_tetramin(one_square_str, counter_letter++)))
		return (0);
	*begin = new_tetramin;
	while (tetramins[i])
	{
		one_square_str = ft_tetramin_sub(all_tetramin_cpy + i);
		if (!(tmp = ft_create_tetramin(one_square_str, counter_letter++)))
			return (0);
		new_tetramin->next = tmp;
		new_tetramin = tmp;
		tmp = NULL;
		i += 21;
	}
//	ft_strdel(&all_tetramin_cpy);
	return (1);
}
