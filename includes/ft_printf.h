/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnilprap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 09:28:15 by vnilprap          #+#    #+#             */
/*   Updated: 2022/05/06 16:57:43 by vnilprap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include "../libft/libft.h"

typedef struct s_node
{
	int	left;
	int	sign;
	int	space;
	int	prefix;
	int	zero;
	int	width;
	int	precision;
}	t_node;

int		ft_printf(const char *str, ...);
int		ft_check(const char *str, va_list list, t_node *block);
int		ft_putchar(const char c);
int		ft_putstr(const char *s);
int		ft_geti(size_t n, int base);
int		ft_pre(t_node *block, char *s, int sign, int sp);
int		ft_convertc(va_list list, t_node *block);
int		ft_converts(va_list list, t_node *block);
int		ft_convertp(va_list list, t_node *block);
int		ft_convertdi(va_list list, t_node *block);
int		ft_convertux(va_list list, t_node *block, int base, char type);
char	*ft_gets(t_node *block, char *s);
char	*ft_itoa_base(unsigned int n, int base);
void	ft_toupperx(char *s);
void	ft_post(t_node *block, char *s, int sign, int sp);
t_node	*ft_setnode(void);

#endif
