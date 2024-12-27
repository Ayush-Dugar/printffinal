/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: adugar <adugar@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/09 13:00:36 by adugar        #+#    #+#                 */
/*   Updated: 2024/10/29 18:26:18 by adugar        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
it copies a specified number of bytes from src to dest. unlike memcy is designed
to handle overlapping memory regions
the unsigned char d and s is similar to memcpy there is an extra i and j variable
dest > src refers to the memory pointers not the size, so if dest is bigger
we want

we are using -1 because we are counting from 0
d = d + n -1 becsue we want the memory locatoin of d then shift it all the way
towards the end of 'memory block' then subtract 1
the i is the counters variable and n is the
*/

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (dest < src)
	{
		i = 0;
		while (i < n)
		{
			*((unsigned char *)dest + i) = *((unsigned char *)src + i);
			i++;
		}
	}
	if (dest > src)
	{
		i = n - 1;
		while (i < n)
		{
			*((unsigned char *)dest + i) = *((unsigned char *)src + i);
			i--;
		}
	}
	return (dest);
}
