/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_funcion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owmarqui <owmarqui@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 15:26:30 by owmarqui          #+#    #+#             */
/*   Updated: 2024/12/03 16:27:51 by owmarqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	auxiliar_render(char tile, t_game *game, int x, int y)
{
	if (tile == '0' || tile == 'P' || tile == 'C' || tile == 'E')
		mlx_image_to_window(game->mlx, game->floor_img, x
			* TILE_SIZE, y * TILE_SIZE);
	if (tile == '1')
		mlx_image_to_window(game->mlx, game->wall_img, x
			* TILE_SIZE, y * TILE_SIZE);
	else if (tile == 'C')
		mlx_image_to_window(game->mlx, game->collectible_img, x
			* TILE_SIZE, y * TILE_SIZE);
	else if (tile == 'E')
		mlx_image_to_window(game->mlx, game->exit_img, x
			* TILE_SIZE, y * TILE_SIZE);
	else if (tile == 'P')
	{
		mlx_image_to_window(game->mlx, game->player_img, x
			* TILE_SIZE, y * TILE_SIZE);
		game->player_x = x;
		game->player_y = y;
	}
}

void	render_all(void *param)
{
	t_game	*game;
	int		y;
	int		x;
	char	tile;

	game = (t_game *)param;
	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			tile = game->map[y][x];
			auxiliar_render(tile, game, x, y);
			x++;
		}
		y++;
	}
	mlx_image_to_window(game->mlx, game->player_img, game->player_x
		* TILE_SIZE, game->player_y * TILE_SIZE);
}
