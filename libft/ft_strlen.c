/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlen.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: adugar <adugar@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/07 14:47:14 by adugar        #+#    #+#                 */
/*   Updated: 2024/11/05 16:56:20 by adugar        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
calculate the length of string
*/
size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}
