/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owmarqui <owmarqui@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 11:51:15 by owmarqui          #+#    #+#             */
/*   Updated: 2024/09/22 16:11:10 by owmarqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	is_in_set(char c, const char *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*dest;
	size_t	start;
	size_t	i;
	size_t	end;

	if (!s1 || !set)
		return (NULL);
	end = ft_strlen(s1);
	start = 0;
	i = 0;
	while (s1[start] && is_in_set(s1[start], set))
		start++;
	if (start == end)
		return (ft_strdup(""));
	while (end > start && is_in_set(s1[end - 1], set))
		end--;
	dest = (char *)malloc(sizeof(char) * (end - start + 1));
	if (!dest)
		return (NULL);
	while (start < end)
		dest[i++] = s1[start++];
	dest[i] = '\0';
	return (dest);
}
