/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvenita <wvenita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/24 21:50:48 by wvenita           #+#    #+#             */
/*   Updated: 2020/04/27 11:58:13 by wvenita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_filler.h"

static int	check(t_map *map, t_cell *point, int i, int j)
{
	int		flag;

	flag = 0;
	while (point)
	{
		if (map->content[i + point->i][j + point->j] != '.')
		{
			if (flag)
				return (0);
			else
				flag = 1;
		}
		point = point->next;
	}
	return (1);
}

static int	calc(t_map *map, t_cell *p, int i, int j)
{
	int		sum;
	int		min;
	int		d;
	t_cell	*tmp;

	sum = 0;
	while (p)
	{
		if (map->content[i + p->i][j + p->j] == '.')
		{
			min = 1000000;
			tmp = map->opp_points;
			while (tmp)
			{
				d = ft_abs(tmp->i - i - p->i) + ft_abs(tmp->j - j - p->j);
				if (d < min)
					min = d;
				tmp = tmp->next;
			}
			sum += min;
		}
		p = p->next;
	}
	return (sum);
}

void		put_piece(t_map *map, t_token *token, int min)
{
	t_cell	*my;
	t_cell	*p;
	int		tmp;

	my = map->my_points;
	while (my)
	{
		p = token->points;
		while (p)
		{
			if (my->i >= p->i && my->j >= p->j
			&& map->lines - my->i >= token->lines - p->i
			&& map->columns - my->j >= token->columns - p->j
			&& check(map, token->points, my->i - p->i, my->j - p->j)
			&& (tmp = calc(map, token->points, my->i - p->i, my->j - p->j)))
				if (tmp < min)
				{
					min = tmp;
					map->answer->i = my->i - p->i;
					map->answer->j = my->j - p->j;
				}
			p = p->next;
		}
		my = my->next;
	}
}
