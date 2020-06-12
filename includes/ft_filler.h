/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filler.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvenita <wvenita@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/29 17:46:16 by wvenita           #+#    #+#             */
/*   Updated: 2020/03/29 17:53:54 by wvenita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FILLER_H
# define FT_FILLER_H

# include "libft.h"

typedef struct		s_cell
{
	int				i;
	int				j;
	struct s_cell	*next;
}					t_cell;

typedef struct		s_map
{
	char			**content;
	int				lines;
	int				columns;
	t_cell			*my_points;
	t_cell			*opp_points;
	t_cell			*answer;
}					t_map;

typedef struct		s_token
{
	char			**content;
	int				lines;
	int				columns;
	t_cell			*points;
}					t_token;

t_map				*get_map(void);
t_token				*get_token(void);
int					define_points(t_map *map, t_token *token, int number);
void				free_all(t_map *map, t_token *token);
void				free_content(char **content, int lines, int offset);
void				put_piece(t_map *map, t_token *token, int min);

#endif
