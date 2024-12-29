/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_validate_map.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owmarqui <owmarqui@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 15:02:04 by owmarqui          #+#    #+#             */
/*   Updated: 2024/11/28 12:10:11 by owmarqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	flood_fill(char **map, int x, int y, t_valid *validation)
{
	if (x < 0 || y < 0 || x >= validation->width || y >= validation->height
		|| map[y][x] == '1' || map[y][x] == 'F')
		return ;
	if (map[y][x] == 'C')
		validation->collectibles--;
	if (map[y][x] == 'E')
		validation->exit_reachable = true;
	map[y][x] = 'F';
	flood_fill(map, x + 1, y, validation);
	flood_fill(map, x - 1, y, validation);
	flood_fill(map, x, y + 1, validation);
	flood_fill(map, x, y - 1, validation);
}

bool	auxiliar_free_map_copy(char **map_copy, int i)
{
	int	j;

	j = 0;
	while (j < i)
	{
		free(map_copy[j]);
		j++;
	}
	free(map_copy);
	return (false);
}

void	store_map(char **map_copy, int i, t_valid validation, t_game *game)
{
	int	j;

	j = 0;
	while (j <= validation.width)
	{
		map_copy[i][j] = game->map[i][j];
		j++;
	}
}

void	init_validate_map(t_game *game, t_valid *validation)
{
	validation->player_x = game->player_x;
	validation->player_y = game->player_y;
	validation->collectibles = game->total_collectibles;
	validation->width = game->map_width;
	validation->height = game->map_height;
	validation->exit_reachable = false;
}

bool	validate_map2(t_game *game)
{
	t_valid	validation;
	char	**map_copy;
	int		i;

	init_validate_map(game, &validation);
	map_copy = malloc(sizeof(char *) * validation.height);
	if (!map_copy)
		return (false);
	i = 0;
	while (i < validation.height)
	{
		if (!game->map[i])
			return (auxiliar_free_map_copy(map_copy, i));
		map_copy[i] = malloc(sizeof(char) * (validation.width + 1));
		if (!map_copy[i])
			return (auxiliar_free_map_copy(map_copy, i));
		store_map(map_copy, i, validation, game);
		i++;
	}
	flood_fill(map_copy, validation.player_x, validation.player_y, &validation);
	i = -1;
	while (++i < validation.height)
		free(map_copy[i]);
	free(map_copy);
	return (validation.collectibles == 0 && validation.exit_reachable);
}
