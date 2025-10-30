/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noakebli <noakebli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:03:32 by noakebli          #+#    #+#             */
/*   Updated: 2024/12/12 20:38:16 by noakebli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	process_specifier(const char *format, va_list args, int *i)
{
	int	count;

	count = 0;
	if (format[*i + 1] == '%')
		count += ft_putchar('%');
	else if (format[*i + 1] == 'c')
		count += ft_putchar(va_arg(args, int));
	else if (format[*i + 1] == 's')
		count += ft_putstr(va_arg(args, char *));
	else if (format[*i + 1] == 'd' || format[*i + 1] == 'i')
		count += ft_putnbr(va_arg(args, int));
	else if (format[*i + 1] == 'X')
		count += hexadecimal_1(va_arg(args, unsigned int));
	else if (format[*i + 1] == 'x')
		count += hexadecimal_x(va_arg(args, unsigned int));
	else if (format[*i + 1] == 'p')
		count += handle_pointer(va_arg(args, void *));
	else if (format[*i + 1] == 'u')
		count += ft_putnbr_unsigned(va_arg(args, unsigned int));
	else
		count += ft_putchar(format[*i]);
	*i += 2;
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		count;

	if (!format)
		return (-1);
	va_start(args, format);
	i = 0;
	count = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%' && format[i + 1] != '\0')
			count += process_specifier(format, args, &i);
		else
		{
			count += ft_putchar(format[i]);
			i++;
		}
	}
	va_end(args);
	return (count);
}
