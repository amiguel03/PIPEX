/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 12:25:09 by sergio            #+#    #+#             */
/*   Updated: 2024/01/23 14:19:10 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_decimal_to_hexa(const char *str, unsigned long long num)
{
	char	*hexa_base;
	int		i;

	i = 0;
	if (*str == 'x' || *str == 'p')
		hexa_base = HEXA_LOWER;
	else
		hexa_base = HEXA_UPPER;
	if (num < 0)
	{
		ft_putchar_fd('-', 1);
		i = 1;
		num = -num;
	}
	if (num < 16)
	{
		ft_putchar_fd(hexa_base[num], 1);
		return (i + 1);
	}
	else
	{
		i += ft_decimal_to_hexa(str, num / 16);
		write (1, &hexa_base[num % 16], 1);
	}
	return (i + 1);
}

static int	ft_evaluate(char const *str, va_list arg)
{
	char	*aux;

	if (*str == 'c')
		return ((ft_putchar_fd(va_arg(arg, int), 1)), 1);
	if (*str == 's')
	{
		aux = va_arg(arg, char *);
		if (aux == NULL)
			return ((ft_putstr_fd("(null)", 1)), 6);
		return ((ft_putstr_fd(aux, 1)), ft_strlen(aux));
	}
	if (*str == 'd' || *str == 'i')
		return (ft_putnbr_fd(va_arg(arg, int), 1), ft_intlen(va_arg(arg, int)));
	if (*str == 'u')
		return (ft_putnbr_fd(va_arg(arg, unsigned int), 1),
			ft_intlen(va_arg(arg, unsigned int)));
	if (*str == 'x' || *str == 'X')
		return (ft_decimal_to_hexa(str, va_arg(arg, unsigned int)));
	if (*str == 'p')
		return ((ft_putstr_fd("0x", 1)),
			(ft_decimal_to_hexa(str, va_arg(arg, unsigned long long)) + 2));
	if (*str == '%')
		return ((ft_putchar_fd('%', 1)), 1);
	return (0);
}

int	ft_printf(char const *str, ...)
{
	va_list	args;
	int		i;

	i = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			i = ft_evaluate(str, args);
		}
		else
		{
			ft_putchar_fd(*str, 1);
			i++;
		}
		str++;
	}
	va_end(args);
	return (i);
}
