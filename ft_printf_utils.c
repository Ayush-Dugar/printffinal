/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_utils.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: adugar <adugar@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/13 14:58:45 by adugar        #+#    #+#                 */
/*   Updated: 2024/12/23 15:15:09 by adugar        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdlib.h>

/*
the first function just prints a string using putchar_fd
dont fully understand why we need first function, and how does 
the computer know to use the first one instead of the second one

second one does the same as first but also returns the length of the string

the trid sfunction just writes  a % sign when called

the 4th function prints  a number
str is a pinter to character array tat will
 hold the string representation of the integer

the functoin calls ft_itoa that converts interger num to string representation

itoa converts num to string

it uses write the string in standard output,
the number of bytes depending on strlen of str
then frees the memory allocated for str
*/

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar_fd(str[i], 1);
		i++;
	}
}

int	ft_printstr(char *str)
{
	int	print_length;

	print_length = 0;
	if (!str)
	{
		ft_putstr("(null)");
		return (6);
	}
	while (*str != '\0')
	{
		ft_putchar_fd(*str, 1);
		str++;
		print_length++;
	}
	return (print_length);
}

int	ft_printpercent(void)
{
	ft_putchar_fd('%', 1);
	return (1);
}

int	ft_printnbr(int num)
{
	int		print_length;
	char	*str;

	print_length = 0;
	str = ft_itoa(num);
	print_length += write(1, str, ft_strlen(str));
	free(str);
	return (print_length);
}
