/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_unsigned.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: adugar <adugar@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/13 15:18:44 by adugar        #+#    #+#                 */
/*   Updated: 2024/12/23 15:08:56 by adugar        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>
#include "libft/libft.h"

/*

first function calculates length of the number 
using a while loop and dividing the number by 10
until it reaches 0

then it returns the length

Second function converts the number to a string
legth is determined by calling the first function

next, it allocates 
memory for the character array str using malloc, the size of the memory
is len + 1 to acommadate for the null terminator
there is a null check if memory allocatoin fails.
the null terminator is added to the end of the string
the index i is initislized to len - 1, 
meanng the index i start count at the last character

the function the neters a while loop that runs until n is greater or equal to 10

uitoa covnerst strings to digits

inside the loop,
the least significant digit is extracted by taking the modulus of n by 10 
its converted to its ascii value by adding '0' to it
the its stored instead of str[i], the value of n is then divided by 10 
to remove that last number
then the i decrements and this repeats until n is less than 10

Finally, the function returns the pointer str, whihc now contains 
the string representation of the number n
*/

int	ft_num_len(unsigned int num)
{
	int	len ;

	len = 0;
	if (num == 0)
		return (1);
	while (num != 0)
	{
		len++;
		num = num / 10;
	}
	return (len);
}

char	*ft_uitoa(unsigned int n)
{
	char	*str;
	int		len;
	int		i;

	len = ft_num_len(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	i = len - 1;
	while (n >= 10)
	{
		str[i] = (n % 10) + '0';
		n = n / 10;
		i--;
	}
	str[i] = n + '0';
	return (str);
}

int	ft_print_unsigned(unsigned int num)
{
	char	*str;
	int		print_length;

	print_length = 0;
	str = ft_uitoa(num);
	if (!str)
		return (0);
	print_length += write(1, str, ft_strlen(str));
	free(str);
	return (print_length);
}
