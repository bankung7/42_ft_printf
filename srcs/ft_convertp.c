/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convertp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnilprap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 20:22:03 by vnilprap          #+#    #+#             */
/*   Updated: 2022/05/18 21:58:42 by vnilprap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/ft_printf.h"
#include "../libft/libft.h"

int	ft_geti(size_t n, int base)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	else
	{
		while (n > 0)
		{
			n /= base;
			i++;
		}
	}
	return (i);
}

static char	*ft_ptoa(size_t n, t_node *block)
{
	int		i;
	char	*s;

	i = ft_geti(n, 16);
	s = ft_calloc(sizeof(char), i + 1);
	if (block->width < i + 2)
		block->width = i + 2;
	if (n == 0)
		s[0] = '0';
	else
	{
		while (n > 0)
		{
			s[--i] = "0123456789abcdef"[n % 16];
			n /= 16;
		}
	}
	return (s);
}

int	ft_convertp(va_list list, t_node *block)
{
	int		sp;
	char	*s;
	size_t	n;

	n = va_arg(list, size_t);
	s = ft_ptoa(n, block);
	if ((int)ft_strlen(s) + 2 > block->width)
		block->width = (int)ft_strlen(s) + 2;
	sp = block->width - (int)ft_strlen(s) - 2;
	while (block->left == 0 && block->zero == 0 && sp > 0)
	{
		sp--;
		ft_putchar(' ');
	}
	ft_putstr("0x");
	while (block->left == 0 && block->zero == 1 && sp > 0)
	{
		sp--;
		ft_putchar('0');
	}
	ft_putstr(s);
	free(s);
	while (block->left == 1 && sp-- > 0)
		ft_putchar(' ');
	return (1);
}
