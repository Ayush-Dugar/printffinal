/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: adugar <adugar@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/10 12:37:23 by adugar        #+#    #+#                 */
/*   Updated: 2024/10/29 18:16:25 by adugar        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
first occurrence of a specific character in a string. 
returns a pointer to that character in that stirng
the last if stament checks if cc is the null temrinator
the function is char * so the return type also needs to be char *
*/

char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;
	char			cc;

	cc = (char) c;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == cc)
			return ((char *) &s[i]);
		i++;
	}
	if (s[i] == cc)
	{
		return ((char *) &s[i]);
	}
	return (NULL);
}
