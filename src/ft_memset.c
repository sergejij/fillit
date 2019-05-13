/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubartemi <ubartemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 13:55:00 by ubartemi          #+#    #+#             */
/*   Updated: 2019/05/14 00:01:37 by ubartemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

void	*ft_memset(void *destination, int c, size_t n)
{
	size_t			counter;
	unsigned char	*arr;

	arr = (unsigned char*)destination;
	counter = 0;
	while (counter < n)
	{
		arr[counter] = c;
		counter++;
	}
	return (destination);
}
