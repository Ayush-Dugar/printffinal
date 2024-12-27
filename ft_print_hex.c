/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_hex.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: adugar <adugar@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/28 18:29:25 by adugar        #+#    #+#                 */
/*   Updated: 2024/12/23 13:33:56 by adugar        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

/*
The first functions helps count the number of digits or the 'len'
of the digits in num

while loop until it's smaller than 16. 16 because
it's hexadecimal. 

then prints number to in its ASCII form '0' so like '5'
the num -10 + 'a' will convert the number and replace it with a letter
there are double recursion calls for the division and modulus
the format is for deciding caps hexadecimal

first function is useful but not necessary

if num less than 16, means its a single digit
otherwise it will divide the number by 16 untill
it reaches a single didgit and then get the modulus

for exmaple 1234 / 16 = 77 and 1234 % 16 = 2
then 77 / 16 = 4 and 77 % 16 = 13
so the result is 4d2

another example is 123
123 / 16 = 7 and 123 % 16 = 11
11 is b in hexadecimal
so the result is 7b

fucntions uses putchar_fd to print the result in ascii
form with + '0'
2 differnt variations of ft_puthcar one for 0-9 
and the other for 10-15 lower and upper case

the ascii vale of 'A' 65 gets added to the asci value
of the number - 10
*/

int	ft_hex_len(unsigned int num)
{
	int	len;

	len = 0;
	if (num == 0)
		return (1);
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

void	ft_put_hex(unsigned int num, const char format)
{
	if (num >= 16)
	{
		ft_put_hex(num / 16, format);
		ft_put_hex(num % 16, format);
	}
	else
	{
		if (num <= 9)
			ft_putchar_fd((num + '0'), 1);
		else
		{
			if (format == 'x')
				ft_putchar_fd((num - 10 + 'a'), 1);
			else if (format == 'X')
				ft_putchar_fd((num - 10 + 'A'), 1);
		}
	}
}

int	ft_print_hex(unsigned int num, const char format)
{
	if (num == 0)
		return (write(1, "0", 1));
	else
		ft_put_hex(num, format);
	return (ft_hex_len(num));
}
