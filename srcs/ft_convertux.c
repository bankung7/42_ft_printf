/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convertdiu.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnilprap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 20:55:38 by vnilprap          #+#    #+#             */
/*   Updated: 2022/05/06 17:31:43 by vnilprap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char	*ft_getux(t_node *block, char *s, char type)
{
	char	*p;

	p = 0;
	if (block->precision != -1 && s[0] == '0')
	{
		free(s);
		s = ft_strdup("");
	}
	if ((type == 'x' || type == 'X') && block->prefix != 0 && s[0] != '0')
	{
		p = ft_strjoin("0x", s);
		free(s);
		s = p;
	}
	if (type == 'X')
		ft_toupperx(s);
	return (s);
}

int	ft_convertux(va_list list, t_node *block, int base, char type)
{
	int		prefix;
	int		sp;
	char	*s;

	prefix = 0;
	sp = 0;
	s = ft_itoa_base(va_arg(list, unsigned int), base);
	s = ft_getux(block, s, type);
	if (block->prefix == 1 && (type == 'x' || type == 'X') && s[0] != '0')
		prefix = 2;
	if (block->precision > block->width)
	{
		if (s[0] == '-')
			block->precision += 1;
		block->zero = 1;
		block->width = block->precision;
	}
	sp = ft_pre(block, s, prefix, sp);
	if ((type == 'x' || type == 'X') && block->prefix != 0)
		ft_putstr(s);
	else
		ft_putstr(&s[prefix]);
	ft_post(block, s, prefix, sp);
	free(s);
	return (1);
}
