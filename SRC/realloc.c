/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owmarqui <owmarqui@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 18:43:45 by owmarqui          #+#    #+#             */
/*   Updated: 2024/12/02 16:59:38 by owmarqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../so_long.h"

void	*ft_realloc(void *ptr, size_t old_size, size_t new_size)
{
	void	*new_ptr;
	size_t	copy_size;

	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}
	new_ptr = malloc(new_size);
	if (!new_ptr)
		return (NULL);
	if (ptr)
	{
		if (old_size < new_size)
			copy_size = old_size;
		else
			copy_size = new_size;
		ft_memcpy(new_ptr, ptr, copy_size);
		free(ptr);
	}
	return (new_ptr);
}
/*
#include <stdio.h>
int main(void)
{
    char **map = NULL;
    int rows = 0;

    // Agregar filas dinámicamente
    for (int i = 0; i < 5; i++)
    {
        map = ft_realloc(map, sizeof(char *) * (rows + 1));
        if (!map)
            return (1); // Error de memoria

        map[rows] = malloc(20); // Aloca espacio para una fila
        if (!map[rows])
            return (1); // Error de memoria
        sprintf(map[rows], "Fila %d", i + 1);
        rows++;
    }

    // Imprimir el contenido del mapa
    for (int i = 0; i < rows; i++)
    {
        printf("%s\n", map[i]);
        free(map[i]);
    }
    free(map);

    return 0;
}*/
