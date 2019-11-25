/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubartemi <ubartemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 19:38:17 by ubartemi          #+#    #+#             */
/*   Updated: 2019/05/15 15:46:39 by aestella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_check_connect_and_hashs(char *one_str_tetr)
{
	int i;
	int counter_hash;

	i = 0;
	counter_hash = 0;
	while (one_str_tetr[i])
	{
		if (one_str_tetr[i] == '#')
			counter_hash++;
		i++;
	}
	if (counter_hash != 4)
		return (0);
	if ((ft_check_connects(one_str_tetr) < 6))
		return (0);
	return (1);
}

int		ft_check_connects(char *tetraminos)
{
	int i;
	int connect;

	connect = 0;
	i = 0;
	while (tetraminos[i])
	{
		if (tetraminos[i] == '#')
		{
			if (tetraminos[i + 1] && tetraminos[i + 1] == '#')
				connect++;
			if (tetraminos[i - 1] && tetraminos[i - 1] == '#')
				connect++;
			if (i + 5 < 21 && tetraminos[i + 5] && tetraminos[i + 5] == '#')
				connect++;
			if (i - 5 >= 0 && tetraminos[i - 5] && tetraminos[i - 5] == '#')
				connect++;
			if (connect < 1)
				return (0);
		}
		i++;
	}
	return (connect);
}

int		ft_check_square_and_symbols(char *tetramins, int i)
{
	int	k;
	int j;

	j = 20;
	k = 4;
	while (tetramins[++i])
	{
		if (i == k)
		{
			k += 5;
			if (tetramins[i] != '\n')
				return (0);
		}
		if (i == j)
		{
			j += 21;
			if (tetramins[i] != '\n')
				return (0);
			k++;
		}
		if (tetramins[i] != '#' && tetramins[i] != '.' && tetramins[i] != '\n')
			return (0);
	}
	return (1);
}
