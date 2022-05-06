/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convertdiu.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnilprap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 20:55:38 by vnilprap          #+#    #+#             */
/*   Updated: 2022/05/06 16:51:26 by vnilprap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_predi(t_node *block, char *s, int sign, int sp)
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

static void	ft_post(t_node *block, char *s, int sign, int sp)
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

int	ft_convertux(va_list list, t_node *block, int base, char type)
{
	int		prefix;
	int		sp;
	char	*s;
	char	*p;

	prefix = 0;
	sp = 0;
	s = ft_itoa_base(va_arg(list, unsigned int), base);
	if (block->precision != -1 && s[0] == '0')
	{
		free(s);
		s = ft_strdup("");
	}
	if (block->prefix == 1 && (type == 'x' || type == 'X') && s[0] != '0')
		prefix = 2;
	if (block->precision > block->width)
	{
		if (s[0] == '-')
			block->precision += 1;
		block->zero = 1;
		block->width = block->precision;
	}
	if ((type == 'x' || type == 'X') && block->prefix != 0 && s[0] != '0')
	{
		p = ft_strjoin("0x", s);
		free(s);
		s = p;
	}
	if (type == 'X')
		ft_toupperx(s);
	sp = ft_predi(block, s, prefix, sp);
	if ((type == 'x' || type == 'X') && block->prefix != 0)
		ft_putstr(s);
	else
		ft_putstr(&s[prefix]);
	ft_post(block, s, prefix, sp);
	free(s);
	return (1);
}

static char	*ft_gets(t_node *block, char *s)
{
	char	*p;

	p = 0;
	if (s[0] != '-' && block->sign == 1)
	{
		p = ft_strjoin("+", s);
		free(s);
		s = p;
	}
	else if (s[0] != '-' && block->sign == 0 && block->space == 1)
	{
		p = ft_strjoin(" ", s);
		free(s);
		s = p;
	}
	return (s);
}

int	ft_convertdi(va_list list, t_node *block)
{
	int		sign;
	int		sp;
	char	*s;

	sign = 0;
	sp = 0;
	s = ft_itoa(va_arg(list, int));
	if (s[0] == '0' && block->precision == 0)
	{
		free(s);
		s = ft_strdup("");
		block->zero = 0;
	}
	s = ft_gets(block, s);
	if (s[0] == '-' || block->space == 1 || block->sign == 1)
		sign = 1;
	sp = ft_predi(block, s, sign, sp);
	ft_putstr(&s[sign]);
	ft_post(block, s, sign, sp);
	free(s);
	return (1);
}
