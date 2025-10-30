/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexadecimal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noakebli <noakebli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 22:49:27 by noakebli          #+#    #+#             */
/*   Updated: 2024/11/24 17:32:10 by noakebli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	hexadecimal_1(unsigned long nb)
{
	char	hex[20];
	int		i;
	int		rest;
	int		count;

	i = 0;
	count = 0;
	if (nb == 0)
		return (ft_putchar('0'));
	while (nb > 0)
	{
		rest = nb % 16;
		if (rest < 10)
			hex[i] = rest + '0';
		else
			hex[i] = rest - 10 + 'A';
		i++;
		nb /= 16;
	}
	i--;
	while (i >= 0)
		count += write(1, &hex[i--], 1);
	return (count);
}

int	hexadecimal_x(unsigned long nb)
{
	char	hex[20];
	int		i;
	int		rest;
	int		count;

	i = 0;
	count = 0;
	if (nb == 0)
		return (ft_putchar('0'));
	while (nb > 0)
	{
		rest = nb % 16;
		if (rest < 10)
			hex[i] = rest + '0';
		else
			hex[i] = rest - 10 + 'a';
		i++;
		nb /= 16;
	}
	i--;
	while (i >= 0)
		count += write(1, &hex[i--], 1);
	return (count);
}

int	handle_pointer(void *ptr)
{
	int	count;

	count = 0;
	if (ptr == 0)
		count += write(1, "(nil)", 5);
	else
	{
		count += write(1, "0x", 2);
		count += hexadecimal_x((unsigned long)ptr);
	}
	return (count);
}
