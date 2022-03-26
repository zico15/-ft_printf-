/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 15:08:01 by edos-san          #+#    #+#             */
/*   Updated: 2022/03/26 16:00:45 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	get_size(const char *txt)
{
	int	i;

	i = 0;
	while (txt && txt[i])
		i++;
	return (i);
}

void	read_str_char(void)
{
	char	str[2];

	str[1] = 0;
	if (data()->type == 'c')
	{
		str[0] = va_arg(data()->args, int);
		data()->txt = str;
		data()->size = 1;
	}
	else
	{
		(data()->txt) = va_arg(data()->args, char *);
		data()->size = get_size(data()->txt);
		if (data()->txt == NULL)
		{
			data()->txt = "(null)";
			data()->size = 6;
			data()->flags[1].is_user = 0;
		}
		if (data()->flags[1].is_user && data()->flags[1].value < data()->size)
			data()->size = data()->flags[1].value;
		data()->flags[1].is_user = 0;
	}
	(data()->txt) = cread_str(data()->txt, data()->size);
}

t_convert	convert(char *base, int size_base)
{
	t_convert	c;

	c.u_x = 1;
	c.p = 1;
	c.i_d = 1;
	c.index = 0;
	c.base = base;
	c.size_base = size_base;
	return (c);
}

void	read_base(t_convert	c)
{
	c.str[0] = '0';
	c.str[1] = 'x' - (data()->flags[2].is_user * 32 * (data()->type == 'X'));
	if (data()->type == 'u' || data()->type == 'x' || (data()->type == 'X'))
		c.u_x = va_arg(data()->args, unsigned int);
	else if (data()->type == 'i' || (data()->type == 'd'))
	{
		c.i_d = va_arg(data()->args, int);
		c.str[0] = '-' - (data()->flags[4].is_user * 2 * (c.i_d >= 0));
		c.index = (c.i_d < 0) + (data()->flags[4].is_user * (c.i_d >= 0));
	}
	else if (data()->type == 'p')
	{
		c.index = 2;
		c.p = va_arg(data()->args, unsigned long);
	}
	if ((data()->type == 'x' || data()->type == 'X') && \
	data()->flags[2].is_user && c.u_x > 0)
		c.index = 2;
	c.signal = (c.i_d >= 0) - (c.i_d < 0);
	c.n = c.u_x * c.p * (c.i_d * c.signal);
	convert_base(c.index, c.n, &c);
	(data()->size) = get_size(c.str);
	(data()->txt) = cread_str(c.str, (data()->size));
}

int	convert_base(int index, unsigned long long n, t_convert *c)
{
	if (n >= c->size_base)
		index = convert_base(index, n / c->size_base, c);
	c->str[index] = c->base[n % c->size_base];
	c->str[++index] = 0;
	return (index);
}
