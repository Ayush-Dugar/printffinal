/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: adugar <adugar@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/25 15:20:21 by adugar        #+#    #+#                 */
/*   Updated: 2024/10/29 19:11:12 by adugar        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
copies bytes from syrc to dest untill n bytes.

the d++ and s++ is the same in a string
where i iterates through untill the null terminator
here it happens untill the number of bytes
*d means points to the first point of the mmeory location of d
checks added to make functions more robust
does not allocate memory
*/

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)

{
	unsigned char		*d;
	const unsigned char	*s;

	if (n == 0 || dest == src)
		return (dest);
	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	while (n > 0)
	{
		*d = *s;
		s++;
		d++;
		n--;
	}
	return (dest);
}
