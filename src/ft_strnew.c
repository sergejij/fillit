/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubartemi <ubartemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 17:03:40 by ubartemi          #+#    #+#             */
/*   Updated: 2019/05/14 00:05:35 by ubartemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

char	*ft_strnew(size_t size)
{
	char	*str;
	size_t	counter;

	counter = 0;
	if (size == (size_t)-1)
		return (NULL);
	str = (char*)malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	while (size < counter)
	{
		str[counter] = '\0';
		counter++;
	}
	return (str);
}
