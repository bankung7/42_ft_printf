/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnilprap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 12:30:13 by vnilprap          #+#    #+#             */
/*   Updated: 2022/05/17 21:00:41 by vnilprap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/ft_printf.h"

t_node	*ft_setnode(void)
{
	t_node	*block;

	block = malloc(sizeof(t_node));
	if (!block)
		return (0);
	block->left = 0;
	block->sign = 0;
	block->space = 0;
	block->prefix = 0;
	block->zero = 0;
	block->width = 0;
	block->precision = -1;
	return (block);
}

char	*ft_itoa_base(unsigned int n, int base)
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

int	ft_putchar(const char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		ft_putchar(s[i++]);
	return (i);
}

void	ft_toupperx(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] >= 'a' && s[i] <= 'z')
			s[i] -= 32;
		i++;
	}
}
