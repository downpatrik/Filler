/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvenita <wvenita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/14 20:52:58 by wvenita           #+#    #+#             */
/*   Updated: 2020/06/05 22:55:08 by wvenita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_filler.h"

static int	get_dimensions(int *lines, int *columns, size_t offset)
{
	char	*line;

	*lines = 0;
	*columns = 0;
	if (get_next_line(0, &line) > 0)
	{
		if (ft_strlen(line) > offset)
		{
			*lines = ft_atoi(line + offset);
			while (ft_isdigit(*(line + offset)))
				++offset;
			*columns = ft_atoi(line + offset + 1);
			free(line);
			if (*lines && *columns)
				return (1);
		}
	}
	return (0);
}

static char	**get_content(int lines, int columns, size_t offset)
{
	char	**res;
	char	*line;
	int		i;

	if ((res = (char**)malloc(sizeof(char*) * lines)))
	{
		i = 0;
		while (i < lines)
		{
			if (get_next_line(0, &line) > 0)
			{
				if (ft_strlen(line) == columns + offset)
				{
					res[i++] = line + offset;
					continue;
				}
				else
					free(line);
			}
			free_content(res, i, offset);
			return (NULL);
		}
	}
	return (res);
}

t_map		*get_map(void)
{
	t_map	*map;
	char	*line;

	line = NULL;
	if ((map = (t_map*)malloc(sizeof(t_map))))
	{
		if (!get_dimensions(&map->lines, &map->columns, 8)
		|| get_next_line(0, &line) <= 0)
		{
			free(map);
			return (NULL);
		}
		free(line);
		if (!(map->content = get_content(map->lines, map->columns, 4)))
			return (NULL);
		map->my_points = NULL;
		map->opp_points = NULL;
		map->answer = NULL;
	}
	return (map);
}

t_token		*get_token(void)
{
	t_token	*token;

	if ((token = (t_token*)malloc(sizeof(t_token))))
	{
		if (!get_dimensions(&token->lines, &token->columns, 6))
		{
			free(token);
			return (NULL);
		}
		if (!(token->content = get_content(token->lines, token->columns, 0)))
			return (NULL);
		token->points = NULL;
	}
	return (token);
}
