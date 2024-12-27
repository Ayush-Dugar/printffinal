/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: adugar <adugar@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/25 22:09:36 by adugar        #+#    #+#                 */
/*   Updated: 2024/10/29 19:17:53 by adugar        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
wordcount counts the number of words in the string,
while loop inside while loop keeps on going untill its finished
so word increases by everytime str[i] equals to delimter

the string copies string to word and it skips any initial delimitters
and it stops when it encounters another delimtter or end of string

for stralloc length keeps on going up in the second while loop
and k also iterates though the entire loop so you have the length
without any delimtter characters.

then enough space gets allocated based on length
then with strcpy the original str get copied the newly created space

in the main function new variables are there

word count get created using earlier functoin
new string space gets malloc with word_count times size of char
its wor count +1 because we are storking them in array and need
a spot for the null terminator

pos is a pointer to an interger variable pos, tracts current position of string
as ititerates through it

strlcalloc is where copying happens
*/

static int	ft_wordcount(char *str, char delimiter)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] != delimiter)
		{
			count++;
			while (str[i] != delimiter && str[i] != '\0')
				i++;
			if (str[i] == '\0')
				return (count);
		}
		i++;
	}
	return (count);
}

static void	ft_strcpy(char *word, char *str, char c, int j)
{
	int	i;

	i = 0;
	while (str[j] == c)
		j++;
	while (str[j + i] != c && str[j + i] != '\0')
	{
		word[i] = str[j + i];
		i++;
	}
	word[i] = '\0';
}

static char	*ft_stralloc(char *str, char c, int *k)
{
	char	*word;
	int		start;
	int		length;

	start = *k;
	length = 0;
	while (str[*k] != '\0')
	{
		if (str[*k] != c)
		{
			start = *k;
			while (str[*k] != '\0' && str[*k] != c)
			{
				length++;
				*k += 1;
			}
			word = (char *)malloc(length + 1);
			if (word == NULL)
				return (NULL);
			ft_strcpy(word, str, c, start);
			return (word);
		}
		(*k)++;
	}
	return (NULL);
}

static void	free_strings(char **strs, int count)
{
	while (count > 0)
	{
		free(strs[--count]);
	}
	free(strs);
}

char	**ft_split(char const *str, char c)
{
	char	**strs;
	int		i;
	int		word_count;
	int		pos;

	if (str == NULL)
		return (NULL);
	i = 0;
	pos = 0;
	word_count = ft_wordcount((char *)str, c);
	strs = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (strs == NULL)
		return (NULL);
	while (i < word_count)
	{
		strs[i] = ft_stralloc((char *)str, c, &pos);
		if (strs[i] == NULL)
		{
			free_strings(strs, i);
			return (NULL);
		}
		i++;
	}
	strs[i] = NULL;
	return (strs);
}
