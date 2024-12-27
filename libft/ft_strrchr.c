/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: adugar <adugar@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/10 13:25:49 by adugar        #+#    #+#                 */
/*   Updated: 2024/10/25 21:02:20 by adugar        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int ch)
{
	int		length;
	char	*ptr;

	length = ft_strlen(str);
	ptr = (char *)str + length;
	while (ptr >= str)
	{
		if (*ptr == (char)ch)
			return (ptr);
		ptr--;
	}
	return (NULL);
}
