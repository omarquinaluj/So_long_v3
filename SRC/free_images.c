/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owmarqui <owmarqui@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 15:16:45 by owmarqui          #+#    #+#             */
/*   Updated: 2024/12/02 16:57:48 by owmarqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	free_images(t_game *game)
{
	if (game->wall_img)
		mlx_delete_image(game->mlx, game->wall_img);
	if (game->floor_img)
		mlx_delete_image(game->mlx, game->floor_img);
	if (game->player_img)
		mlx_delete_image(game->mlx, game->player_img);
	if (game->collectible_img)
		mlx_delete_image(game->mlx, game->collectible_img);
	if (game->exit_img)
		mlx_delete_image(game->mlx, game->exit_img);
}
