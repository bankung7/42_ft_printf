/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convertdiu.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnilprap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 20:55:38 by vnilprap          #+#    #+#             */
/*   Updated: 2022/05/17 21:01:17 by vnilprap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/ft_printf.h"

int	ft_pre(t_node *block, char *s, int sign, int sp)
{
	if ((int)ft_strlen(s) > block->width)
		block->width = (int)ft_strlen(s);
	if (block->precision + sign > block->width)
		block->width = block->precision + sign;
	if (block->precision != -1 && block->width > block->precision + sign)
	{
		block->zero = 0;
		sp = block->width - block->precision - sign;
	}
	if (block->precision != -1 && (int)ft_strlen(s) > block->precision + sign)
		sp -= ((int)ft_strlen(s) - block->precision - sign);
	if (block->precision == -1 && block->width > (int)ft_strlen(s))
		sp = block->width - (int)ft_strlen(s);
	while (block->left == 0 && block->zero == 0 && sp-- > 0)
		ft_putchar(' ');
	if (s[0] == '-' || s[0] == '+' || s[0] == ' ')
		ft_putchar(s[0]);
	if (block->precision > (int)ft_strlen(s) - sign)
	{
		block->zero = 1;
		sp = block->precision - (int)ft_strlen(s) + sign;
	}
	while (block->zero == 1 && sp-- > 0)
		ft_putchar('0');
	return (sp);
}

void	ft_post(t_node *block, char *s, int sign, int sp)
{
	if ((int)ft_strlen(s) < block->precision
		&& block->precision != -1 && block->width > block->precision + sign)
		sp = block->width - block->precision - sign;
	if (block->precision == -1 && block->width > (int)ft_strlen(s)
		&& block->left == 1)
		sp = block->width - (int)ft_strlen(s);
	while (block->left == 1 && sp-- > 0)
		ft_putchar(' ');
}
