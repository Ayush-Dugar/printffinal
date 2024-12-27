/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: adugar <adugar@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/28 18:28:30 by adugar        #+#    #+#                 */
/*   Updated: 2024/12/23 16:23:09 by adugar        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

/*
first function prints single character, usefull for
%c specifier.
ft_formats handles all different formats spcefiers
eg c,s,p,d,i,u,x,X,%

args is a va_list object containing the variable
arguments passed to ft_printf.
format represents the format specifier itself

based on the format given it calls the relevant helper function
it uses va_arg to retrieve the argument corresponding 
to the format specifier from args

the function returns the total number of characters printed
stored in print_length

va_arg is a macro provided in c standad library,
used to retrieve the enxt argument in a list 

ok so create a va_list
initialise it using va_start
then accs each argument va_arg, each time you call it
it advances to the next argument
then end it with va_end
*/

int	ft_printchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_formats(va_list args, const char format)
{
	int	print_length;

	print_length = 0;
	if (format == 'c')
		print_length += ft_printchar(va_arg(args, int));
	else if (format == 's')
		print_length += ft_printstr(va_arg(args, char *));
	else if (format == 'p')
		print_length += ft_print_ptr(va_arg(args, unsigned long));
	else if (format == 'd' || format == 'i')
		print_length += ft_printnbr(va_arg(args, int));
	else if (format == 'u')
		print_length += ft_print_unsigned(va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')
		print_length += ft_print_hex(va_arg(args, unsigned int), format);
	else if (format == '%')
		print_length += ft_printpercent();
	return (print_length);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	args;
	int		print_length;

	i = 0;
	print_length = 0;
	va_start(args, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			print_length += ft_formats(args, str[i + 1]);
			i++;
		}
		else
			print_length += ft_printchar(str[i]);
		i++;
	}
	va_end(args);
	return (print_length);
}
