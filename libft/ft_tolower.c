/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_tolower.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: adugar <adugar@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/10 12:32:25 by adugar        #+#    #+#                 */
/*   Updated: 2024/10/29 19:20:16 by adugar        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int ch)
{
	if (!(ch >= 65 && ch <= 90))
		return (ch);
	else
		ch = ch + 32;
	return (ch);
}
