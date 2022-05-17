/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnilprap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 12:00:50 by vnilprap          #+#    #+#             */
/*   Updated: 2022/05/17 20:58:15 by vnilprap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/ft_printf.h"

static int	ft_gettype(const char *str, va_list list, t_node *block)
{
	if (*str == 'c')
		ft_convertc(list, block);
	else if (*str == 's')
		ft_converts(list, block);
	else if (*str == 'p')
		ft_convertp(list, block);
	else if (*str == 'd' || *str == 'i')
		ft_convertdi(list, block);
	else if (*str == 'u')
		ft_convertux(list, block, 10, 'u');
	else if (*str == 'x')
		ft_convertux(list, block, 16, 'x');
	else if (*str == 'X')
		ft_convertux(list, block, 16, 'X');
	else
	{
		block->width = 1;
		ft_putchar('%');
	}
	return (1);
}

static int	ft_getflag(const char *str, t_node *block)
{
	int	i;

	i = 0;
	while (ft_strchr("-+ 0#", str[i]) != 0)
	{
		if (str[i] == '-')
			block->left = 1;
		else if (str[i] == '+')
			block->sign = 1;
		else if (str[i] == ' ')
			block->space = 1;
		else if (str[i] == '0')
			block->zero = 1;
		else if (str[i] == '#')
			block->prefix = 1;
		i++;
	}
	return (i);
}

static int	ft_getnum(const char *str, t_node *block, const char type)
{
	int	i;
	int	num;

	i = 0;
	num = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = (num * 10) + (str[i++] - '0');
	}
	if (type == 'w')
		block->width = num;
	else
		block->precision = num;
	return (i);
}

int	ft_check(const char *str, va_list list, t_node *block)
{
	int	i;

	i = 0;
	if (ft_strchr("-+ 0#", str[i]) != 0)
		i += ft_getflag(&str[i], block);
	if (str[i] >= '1' && str[i] <= '9')
		i += ft_getnum(&str[i], block, 'w');
	if (str[i] == '.')
		i += ft_getnum(&str[i + 1], block, 'p') + 1;
	i += ft_gettype(&str[i], list, block);
	return (i);
}
