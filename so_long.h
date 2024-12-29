/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owmarqui <owmarqui@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 17:49:03 by owmarqui          #+#    #+#             */
/*   Updated: 2024/12/03 16:15:46 by owmarqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "MLX42/include/MLX42/MLX42.h"
# include "Libft_definitiva/libft.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>

# define TILE_SIZE 64

typedef struct s_game
{
	mlx_t		*mlx;
	mlx_image_t	*player_img;
	mlx_image_t	*collectible_img;
	mlx_image_t	*wall_img;
	mlx_image_t	*floor_img;
	mlx_image_t	*exit_img;
	char		**map;
	int			player_x;
	int			player_y;
	int			map_width;
	int			map_height;
	int			collectibles;
	int			count_c;
	int			total_collectibles;
	int			move_count;
	bool		victory;
}	t_game;

typedef struct s_map_counts
{
	int	collectibles;
	int	exits;
	int	players;
}	t_map_counts;

typedef struct s_valid
{
	int		player_x;
	int		player_y;
	int		collectibles;
	int		height;
	int		width;
	bool	exit_reachable;
}	t_valid;

int		check_xt(char *map);
void	*ft_realloc(void *ptr, size_t old_size, size_t new_size);
char	**load_map(const char *filename, int *width, int *height, t_game *game);
bool	validate_map(char **map, int width, int height);
bool	validate_map2(t_game *game);
bool	load_images(t_game *game);
void	free_images(t_game *game);
void	render_all(void *param);
void	move_player(t_game *game, int dx, int dy);
void	handle_key(mlx_key_data_t keydata, void *param);
void	free_game(t_game *game);
#endif
