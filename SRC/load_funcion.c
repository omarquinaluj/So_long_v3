/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_funcion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owmarqui <owmarqui@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 13:57:06 by owmarqui          #+#    #+#             */
/*   Updated: 2024/12/09 16:17:12 by owmarqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	count_collectibles(char *line, int width, t_game *game, int row)
{
	int	i;

	i = 0;
	while (i < width)
	{
		if (line[i] == 'C')
			game->total_collectibles++;
		else if (line[i] == 'P')
		{
			game->player_x = i;
			game->player_y = row;
		}
		i++;
	}
}

void	auxiliar_free_map(char *line, int *row, char **map)
{
	int	j;

	ft_printf("Erro\nEn el load_map\n");
	if (line)
		free(line);
	j = 0;
	if (map)
	{
		while (j < *row && map[j])
		{
			free(map[j]);
			j++;
		}
		free(map);
	}
}

static char	**read_map(int fd, int *row, int *width, t_game *game)
{
	char	*line;
	char	**map;
	char	**temp;

	map = NULL;
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (*row == 0)
			*width = ft_strlen(line) - 1;
		temp = ft_realloc(map, sizeof(char *) * (*row),
				sizeof(char *) * (*row + 1));
		if (!temp)
		{
			auxiliar_free_map(line, row, map);
			return (NULL);
		}
		map = temp;
		map[*row] = line;
		count_collectibles(line, *width, game, *row);
		(*row)++;
		line = get_next_line(fd);
	}
	free(line);
	return (map);
}

char	**load_map(const char *filename, int *width, int *height, t_game *game)
{
	int		fd;
	char	**map;
	int		row;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error\nAl abrir el archivo\n");
		return (NULL);
	}
	row = 0;
	map = read_map(fd, &row, width, game);
	close(fd);
	if (!map)
		return (NULL);
	if (row == 0)
	{
		ft_printf("Error\nMapa vacío\n");
		return (NULL);
	}
	*height = row;
	return (map);
}
