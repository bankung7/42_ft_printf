/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnilprap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 12:56:52 by vnilprap          #+#    #+#             */
/*   Updated: 2022/05/04 12:21:04 by vnilprap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include "../includes/ft_printf.h"

int	ft_convertc(va_list list, t_node *block)
{
	int		i;
	char	c;

	i = 0;
	c = va_arg(list, int);
	if (block->width == 0)
		block->width = 1;
	while (block->left == 0 && block->width - i++ > 1)
		ft_putchar(' ');
	if (c != 0)
		ft_putchar(c);
	else
		ft_putchar(0);
	while (block->left == 1 && block->width - i++ > 1)
		ft_putchar(' ');
	return (1);
}

static char	*ft_gets(t_node *block, va_list list)
{
	char	*p;
	char	*s;

	p = 0;
	s = va_arg(list, char *);
	if (s == 0)
		s = ft_strdup("(null)");
	else
		s = ft_strdup(s);
	if ((int)ft_strlen(s) > block->width)
		block->width = (int)ft_strlen(s);
	if (block->width < block->precision && block->precision != -1)
		block->width = block->precision;
	p = ft_substr(s, 0, block->width);
	if (s != 0)
		free(s);
	return (p);
}

int	ft_converts(va_list list, t_node *block)
{
	int		i;
	int		sp;
	char	*s;

	i = 0;
	sp = 0;
	s = ft_gets(block, list);
	if (s != 0 && (int)ft_strlen(s) > block->width)
		block->width = (int)ft_strlen(s);
	if (s != 0 && block->width >= (int)ft_strlen(s))
		sp = block->width - (int)ft_strlen(s);
	else
		sp = block->width - 6;
	while (block->left == 0 && sp-- > 0)
		ft_putchar(' ');
	ft_putstr(s);
	while (block->left == 1 && sp-- > 0)
		ft_putchar(' ');
	if (s != 0)
		free(s);
	return (1);
}