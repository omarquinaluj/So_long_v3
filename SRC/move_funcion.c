/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_funcion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owmarqui <owmarqui@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 17:08:49 by owmarqui          #+#    #+#             */
/*   Updated: 2024/12/03 16:16:55 by owmarqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	auxiliar_move_player(t_game *game, int new_x, int new_y)
{
	if (game->map[new_y][new_x] == 'C')
	{
		game->collectibles++;
		ft_printf("Coleccionables recogidos: %d de %d\n", game->collectibles,
			game->total_collectibles);
	}
	if (game->map[game->player_y][game->player_x] != 'E')
		game->map[game->player_y][game->player_x] = '0';
}

void	move_player(t_game *game, int dx, int dy)
{
	int	new_x;
	int	new_y;

	new_x = game->player_x + dx;
	new_y = game->player_y + dy;
	if (new_x < 0 || new_x >= game->map_width || new_y < 0
		|| new_y >= game->map_height)
		return ;
	if (game->map[new_y][new_x] == '1')
		return ;
	auxiliar_move_player(game, new_x, new_y);
	game->player_x = new_x;
	game->player_y = new_y;
	game->move_count++;
	ft_printf("Movimientos: %d\n", game->move_count);
	if (game->map[game->player_y][game->player_x] != 'E')
		game->map[game->player_y][game->player_x] = 'P';
	if (game->map[game->player_y][game->player_x] == 'E'
		&& game->collectibles == game->total_collectibles)
	{
		ft_printf("¡Nivel completado!.\n");
		game->victory = true;
		mlx_close_window(game->mlx);
	}
}

void	handle_key(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)
	{
		if (keydata.key == MLX_KEY_ESCAPE)
			mlx_close_window(game->mlx);
		else if (!game->victory)
		{
			if (keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP)
				move_player(game, 0, -1);
			else if (keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT)
				move_player(game, -1, 0);
			else if (keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN)
				move_player(game, 0, 1);
			else if (keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT)
				move_player(game, 1, 0);
		}
	}
}
