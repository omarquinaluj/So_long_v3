/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owmarqui <owmarqui@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 10:44:24 by owmarqui          #+#    #+#             */
/*   Updated: 2024/12/02 14:30:14 by owmarqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t num)
{
	unsigned const char	*s;
	unsigned char		*d;
	size_t				i;

	s = (unsigned const char *)src;
	d = (unsigned char *)dest;
	i = 0;
	if (dest == src || !num)
	{
		return (dest);
	}
	while (i < num)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}
