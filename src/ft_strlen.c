/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubartemi <ubartemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 19:32:08 by ubartemi          #+#    #+#             */
/*   Updated: 2019/05/14 00:01:16 by ubartemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

size_t	ft_strlen(const char *str)
{
	size_t counter;

	counter = 0;
	while (str[counter] != '\0')
		counter++;
	return (counter);
}
