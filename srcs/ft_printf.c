/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnilprap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 10:57:56 by vnilprap          #+#    #+#             */
/*   Updated: 2022/05/22 09:02:25 by vnilprap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/ft_printf.h"

int	ft_printf(const char *str, ...)
{
	int		len;
	va_list	list;
	t_node	*block;

	len = 0;
	va_start(list, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			block = ft_setnode();
			if (block == 0)
				return (0);
			str += (ft_check(str, list, block));
			len += block->width;
			if (block != 0)
				free(block);
		}
		else
			len += ft_putchar(*(str++));
	}
	va_end(list);
	return (len);
}
