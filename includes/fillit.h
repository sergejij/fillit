/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubartemi <ubartemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 23:21:38 by aestella          #+#    #+#             */
/*   Updated: 2019/05/13 23:38:47 by ubartemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_FILLIT_H
# define FILLIT_FILLIT_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct		s_list
{
	struct s_list	*next;
	char			letter;
	int				*coord_x;
	int				*coord_y;
}					t_list;

void				ft_putchar(char c);
void				ft_putstr(char const *s);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
size_t				ft_strlen(const char *str);
char				*ft_strdup(const char *str);
void				*ft_memset(void *destination, int c, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
void				ft_clean_tetramin(char **map, int j, int i,
					t_list **current_list);
char				**ft_copy_map_plus(int size);
int					ft_move_tetramin(int *arr, char direct);
int					ft_check_and_place(char **map, int j, int i,
					t_list **current_list);
char				**ft_new_map(int len);
int					ft_listsize(t_list *begin_list);
int					ft_recursive(t_list *current_list, char **map, int size);
void				ft_print_result(char **map);
void				ft_add_coordinats2(char *one_str_tetr, int *coordinats_x,
					int *coordinats_y, int k);
int					ft_add_coordinats(t_list *current, char *one_str_tetr);
t_list				*ft_create_tetramin(char *one_square_str,
					int counter_letter);
int					ft_validation(char *tetramins, t_list **begin,
					int counter_letter);
int					ft_make_result(t_list *begin);
char				*ft_tetramin_sub(char *tetramins);
int					ft_check_connect_and_hashs(char *one_str_tetr);
int					ft_check_connects(char *tetraminos);
int					ft_check_square_and_symbols(char *tetramins, int i);

#endif
