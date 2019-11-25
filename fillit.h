/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubartemi <ubartemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 23:21:38 by aestella          #+#    #+#             */
/*   Updated: 2019/05/15 17:11:59 by aestella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft/libft.h"

typedef struct		s_lst
{
	struct s_lst	*next;
	char			letter;
	int				*coord_x;
	int				*coord_y;
}					t_lst;

void				ft_free_list(t_lst **begin);
void				ft_free_map(char **map);
void				ft_clean_tetramin(char **map, int j, int i,
		t_lst **current_list);
char				**ft_copy_map_plus(int size);
int					ft_move_tetramin(int *arr, char direct);
int					ft_check_and_place(char **map, int j, int i,
		t_lst **current_list);
char				**ft_new_map(int len);
int					ft_listsize(t_lst *begin_list);
int					ft_recursive(t_lst *current_list, char **map, int size);
void				ft_print_result(char **map);
void				ft_add_coordinats2(char *one_str_tetr, int *coordinats_x,
		int *coordinats_y, int k);
int					ft_add_coordinats(t_lst *current, char *one_str_tetr);
t_lst				*ft_create_tetramin(char *one_square_str,
		int counter_letter);
int					ft_validation(char *tetramins, t_lst **begin,
		int counter_letter);
int					ft_make_result(t_lst *begin);
int					ft_check_connect_and_hashs(char *one_str_tetr);
int					ft_check_connects(char *tetraminos);
int					ft_check_square_and_symbols(char *tetramins, int i);

#endif
