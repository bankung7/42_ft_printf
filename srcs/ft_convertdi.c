/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convertdiu.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnilprap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 20:55:38 by vnilprap          #+#    #+#             */
/*   Updated: 2022/05/17 20:58:55 by vnilprap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/ft_printf.h"

static char	*ft_getdi(t_node *block, char *s)
{
	char	*p;

	p = 0;
	if (s[0] != '-' && block->sign == 1)
		p = ft_strjoin("+", s);
	else if (s[0] != '-' && block->sign == 0 && block->space == 1)
		p = ft_strjoin(" ", s);
	else
		p = ft_strdup(s);
	free(s);
	return (p);
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
	s = ft_getdi(block, s);
	if (s[0] == '-' || block->space == 1 || block->sign == 1)
		sign = 1;
	sp = ft_pre(block, s, sign, sp);
	ft_putstr(&s[sign]);
	ft_post(block, s, sign, sp);
	free(s);
	return (1);
}
