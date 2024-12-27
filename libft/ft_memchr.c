/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: adugar <adugar@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/10 14:56:16 by adugar        #+#    #+#                 */
/*   Updated: 2024/11/05 16:57:17 by adugar        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
first occurrence of a specific character in a memory block. 
returns a pointer to that character in that memory block.

const void *s is a pointer to the memory block
int c is the byte value we are looking for
size_t n is the number of btes to searhc within the memory block

the ptr + i moves the ptr in the memory location foward
casting to void * allows to return to a pointer of ant data type

*/

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (ptr[i] == (unsigned char)c)
			return ((void *)(ptr + i));
		i++;
	}
	return (NULL);
}
