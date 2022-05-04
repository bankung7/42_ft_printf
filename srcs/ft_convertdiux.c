/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convertdiu.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnilprap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 20:55:38 by vnilprap          #+#    #+#             */
/*   Updated: 2022/05/04 12:12:23 by vnilprap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

static	char	*ft_itoa_base(unsigned int n, int base)
{
	int		i;
	char	*s;

	i = ft_geti(n, base);
	s = ft_calloc(sizeof(char), i + 1);
	if (n == 0)
		s[0] = '0';
	else
	{
		while (n > 0)
		{
			s[--i] = "0123456789abcdef"[n % base];
			n /= base;
		}
	}
	return (s);
}

static void	ft_pre(t_node *block, char *s, int sp, char type)
{
	if (type == 'X')
		ft_toupperx(s);
	if (s[0] == '-' && block->zero == 1)
		ft_putchar('-');
	if (block->sign == 1 && s[0] != '-' && type == 'd')
		ft_putchar('+');
	if (block->space == 1 && block->sign == 0 && s[0] != '-' && type == 'd')
		ft_putchar(' ');
	while (block->left == 0 && block->zero == 0 && sp-- > 0)
		ft_putchar(' ');
	if (block->prefix == 1 && type == 'x' && s[0] != '0')
		ft_putstr("0x");
	else if (block->prefix == 1 && type == 'X' && s[0] != '0')
		ft_putstr("0X");
	while (block->left == 0 && block->zero == 1 && sp-- > 0)
		ft_putchar('0');
	if (s[0] == '-' && block->zero == 1)
		ft_putstr(&s[1]);
	else
		ft_putstr(s);
	while (block->left == 1 && sp-- > 0)
		ft_putchar(' ');
}

int	ft_convertux(va_list list, t_node *block, int base, char type)
{
	int		prefix;
	int		sp;
	char	*s;

	prefix = 0;
	s = ft_itoa_base(va_arg(list, unsigned int), base);
	if (block->prefix == 1 && (type == 'x' || type == 'X') && s[0] != '0')
		prefix = 2;
	if (block->precision > block->width)
	{
		if (s[0] == '-')
			block->precision += 1;
		block->zero = 1;
		block->width = block->precision;
	}
	if ((int)ft_strlen(s) + prefix > block->width)
		block->width = (int)ft_strlen(s) + prefix;
	sp = block->width - (int)ft_strlen(s) - prefix;
	if (block->precision == 0 && s[0] == '0')
		block->width = 0;
	else
		ft_pre(block, s, sp, type);
	free(s);
	return (1);
}

int	ft_convertdi(va_list list, t_node *block)
{
	int		sign;
	int		sp;
	char	*s;

	sign = 0;
	s = ft_itoa(va_arg(list, int));
	if ((block->sign == 1 || block->space == 1) && s[0] != '-')
		sign = 1;
	if (block->precision > block->width)
	{
		if (s[0] == '-')
			block->precision += 1;
		block->left = 0;
		block->zero = 1;
		block->width = block->precision;
	}
	if ((int)ft_strlen(s) + sign > block->width)
		block->width = (int)ft_strlen(s) + sign;
	sp = block->width - (int)ft_strlen(s) - sign;
	if (block->precision == 0 && s[0] == '0')
		block->width = 0;
	else
		ft_pre(block, s, sp, 'd');
	free(s);
	return (1);
}
