/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owmarqui <owmarqui@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 19:38:15 by owmarqui          #+#    #+#             */
/*   Updated: 2024/12/02 14:37:18 by owmarqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

bool	is_rectangular(char **map, int height)
{
	int	width;
	int	i;

	i = 1;
	width = ft_strlen(map[0]);
	while (i < height)
	{
		if ((int)ft_strlen(map[i]) != width)
			return (false);
		i++;
	}
	return (true);
}

bool	is_closed(char **map, int width, int height)
{
	int	i;

	i = 0;
	while (i < width)
	{
		if (map[0][i] != '1' || map[height - 1][i] != '1')
			return (false);
		i++;
	}
	i = 0;
	while (i < height)
	{
		if (map[i][0] != '1' || map[i][width - 1] != '1')
			return (false);
		i++;
	}
	return (true);
}

void	init_map_counts(t_map_counts *counts)
{
	if (counts == NULL)
		return ;
	counts->collectibles = 0;
	counts->exits = 0;
	counts->players = 0;
}

bool	calculator_char(char *fila, t_map_counts *counts, int width)
{
	int	j;

	j = 0;
	while (j < width)
	{
		if (!ft_strchr("01CEP", fila[j]))
			return (ft_printf("Error\nCarácter invalido\n"), false);
		if (fila[j] == 'P')
			counts->players++;
		else if (fila[j] == 'E')
			counts->exits++;
		else if (fila[j] == 'C')
			counts->collectibles++;
		j++;
	}
	return (true);
}

bool	validate_map(char **map, int width, int height)
{
	t_map_counts	counts;
	int				i;

	init_map_counts(&counts);
	i = 0;
	while (i < height)
	{
		if (!calculator_char(map[i], &counts, width))
			return (false);
		i++;
	}
	if (counts.players != 1 || counts.exits != 1 || counts.collectibles < 1)
		return (ft_printf("Error\nComponentes insuficientes\n"), false);
	if (!is_rectangular(map, height))
		return (ft_printf("Error\nEl mapa no es rectangular.\n"), false);
	if (!is_closed(map, width, height))
		return (ft_printf("Error\nEl mapa no está cerrado.\n"), false);
	return (true);
}
