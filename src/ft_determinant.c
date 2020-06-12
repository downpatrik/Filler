/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_determinant.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvenita <wvenita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/22 21:34:54 by wvenita           #+#    #+#             */
/*   Updated: 2020/04/27 11:57:55 by wvenita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_filler.h"

static int	add_point(t_cell **point, int i, int j)
{
	t_cell	*tmp;

	if (*point)
	{
		if (!(tmp = (t_cell*)malloc(sizeof(t_cell))))
			return (0);
		tmp->next = *point;
		*point = tmp;
	}
	else
	{
		if (!(*point = (t_cell*)malloc(sizeof(t_cell))))
			return (0);
		(*point)->next = NULL;
	}
	(*point)->i = i;
	(*point)->j = j;
	return (1);
}

static int	map_points(t_map *map, char my_sign, char opp_sign)
{
	int		i;
	int		j;

	i = map->lines;
	while (i--)
	{
		j = map->columns;
		while (j--)
			if (map->content[i][j] == my_sign
			|| map->content[i][j] == my_sign + 32)
			{
				if (!add_point(&map->my_points, i, j))
					return (0);
			}
			else if (map->content[i][j] == opp_sign
			|| map->content[i][j] == opp_sign + 32)
			{
				if (!add_point(&map->opp_points, i, j))
					return (0);
			}
			else if (map->content[i][j] != '.')
				return (0);
	}
	add_point(&map->answer, 0, 0);
	return (1);
}

static int	token_points(t_token *token)
{
	int		i;
	int		j;

	i = token->lines;
	while (i--)
	{
		j = token->columns;
		while (j--)
		{
			if (token->content[i][j] == '*')
			{
				if (!add_point(&token->points, i, j))
					return (0);
			}
			else if (token->content[i][j] != '.')
				return (0);
		}
	}
	return (1);
}

int			define_points(t_map *map, t_token *token, int number)
{
	char		my_sign;
	char		opp_sign;

	if (number == 1)
	{
		my_sign = 'O';
		opp_sign = 'X';
	}
	else
	{
		my_sign = 'X';
		opp_sign = 'O';
	}
	if (!map_points(map, my_sign, opp_sign) || !token_points(token))
	{
		free_all(map, token);
		return (0);
	}
	return (1);
}
