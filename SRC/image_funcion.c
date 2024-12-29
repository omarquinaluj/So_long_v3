/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_funcion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owmarqui <owmarqui@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:20:24 by owmarqui          #+#    #+#             */
/*   Updated: 2024/12/02 17:08:14 by owmarqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	aux_images(t_game *game, char *image_paths[], mlx_image_t **image_ptrs[])
{
	mlx_texture_t	*texture;
	int				i;

	i = 0;
	while (i < 5)
	{
		texture = mlx_load_png(image_paths[i]);
		if (!texture)
		{
			ft_printf("Error\n No se pudo cargar una textura.\n");
			return (0);
		}
		*image_ptrs[i] = mlx_texture_to_image(game->mlx, texture);
		mlx_delete_texture(texture);
		if (!*image_ptrs[i])
		{
			ft_printf("Error\n No se pudo convertir la textura a imagen\n");
			return (0);
		}
		i++;
	}
	return (1);
}

bool	load_images(t_game *game)
{
	char			*image_paths[5];
	mlx_image_t		**image_ptrs[5];

	image_paths[0] = "texture/paredes.png";
	image_paths[1] = "texture/suelo.png";
	image_paths[2] = "texture/personaje.png";
	image_paths[3] = "texture/cristal_de_energia.png";
	image_paths[4] = "texture/portal_cerrado.png";
	image_ptrs[0] = &game->wall_img;
	image_ptrs[1] = &game->floor_img;
	image_ptrs[2] = &game->player_img;
	image_ptrs[3] = &game->collectible_img;
	image_ptrs[4] = &game->exit_img;
	if (!aux_images(game, image_paths, image_ptrs))
		return (false);
	return (true);
}
