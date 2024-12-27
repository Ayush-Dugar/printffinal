/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_calloc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: adugar <adugar@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/10 17:33:59 by adugar        #+#    #+#                 */
/*   Updated: 2024/10/29 19:15:20 by adugar        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
it allocates memory but sets it all equal to 0
*/

void	*ft_calloc(size_t num, size_t size)
{
	char	*temp;
	size_t	total_size;
	size_t	i;

	total_size = num * size;
	if (num != 0 && total_size / num != size)
		return (NULL);
	temp = malloc(total_size);
	if (temp == NULL)
		return (NULL);
	i = 0;
	while (i < total_size)
	{
		temp[i] = 0;
		i++;
	}
	return (temp);
}
