/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owmarqui <owmarqui@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 10:50:53 by owmarqui          #+#    #+#             */
/*   Updated: 2024/12/03 16:17:18 by owmarqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_game	*init_game(void)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!game)
		return (NULL);
	game->player_x = 0;
	game->player_y = 0;
	game->collectibles = 0;
	game->count_c = 0;
	game->total_collectibles = 0;
	game->move_count = 0;
	game->victory = false;
	game->mlx = NULL;
	game->map = NULL;
	game->map_width = 0;
	game->map_height = 0;
	return (game);
}

void	free_game(t_game *game)
{
	int	i;

	i = 0;
	if (game->map)
	{
		while (i < game->map_height)
		{
			free(game->map[i]);
			i++;
		}
		free(game->map);
	}
	if (game->mlx)
	{
		free_images(game);
		mlx_terminate(game->mlx);
	}
	free(game);
}

void	game_loop(t_game *game)
{
	mlx_loop_hook(game->mlx, &render_all, game);
	mlx_key_hook(game->mlx, &handle_key, game);
	mlx_loop(game->mlx);
}

int	initialize_and_validate_game(t_game **game, char *map_file)
{
	*game = init_game();
	if (!(*game))
		return (0);
	(*game)->map = load_map(map_file, &(*game)->map_width,
			&(*game)->map_height, *game);
	if (!(*game)->map || (*game)->map_width <= 0 || (*game)->map_height <= 0)
	{
		ft_printf("Error\nAl cargar el mapa.\n");
		free_game(*game);
		return (0);
	}
	if (!validate_map((*game)->map, (*game)->map_width, (*game)->map_height))
	{
		free_game(*game);
		return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
	{
		ft_printf("Error\n./so_long <map_file>\n");
		return (1);
	}
	if (!check_xt(argv[1]))
		return (1);
	if (!initialize_and_validate_game(&game, argv[1]))
		return (1);
	if (!validate_map2(game))
	{
		ft_printf("Error\nEl mapa no es jugable\n");
		free_game(game);
		return (1);
	}
	game->mlx = mlx_init(game->map_width
			* 64, game->map_height * 64, "So_long", false);
	if (!load_images(game))
		return (1);
	game_loop(game);
	free_game(game);
	return (0);
}
