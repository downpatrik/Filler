/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvenita <wvenita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/24 21:51:00 by wvenita           #+#    #+#             */
/*   Updated: 2020/04/27 11:53:35 by wvenita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_filler.h"

static void	ft_ptint(t_cell *answer)
{
	ft_putnbr(answer->i);
	ft_putchar(' ');
	ft_putnbr(answer->j);
	ft_putchar('\n');
}

static int	get_player(void)
{
	char	*line;

	if (get_next_line(0, &line) > 0)
	{
		if (!ft_strncmp(line, "$$$ exec p", 10))
		{
			if (line[10] == '1')
			{
				free(line);
				return (1);
			}
			else if (line[10] == '2')
			{
				free(line);
				return (2);
			}
		}
		free(line);
	}
	return (0);
}

int			main(void)
{
	t_map	*map;
	t_token	*token;
	int		player_number;

	if (!(player_number = get_player()))
		return (1);
	while (1)
	{
		if (!(map = get_map()))
			return (1);
		if (!(token = get_token()))
		{
			free_all(map, token);
			return (1);
		}
		if (!define_points(map, token, player_number))
			return (1);
		put_piece(map, token, 10000000);
		ft_ptint(map->answer);
		free_all(map, token);
	}
}
