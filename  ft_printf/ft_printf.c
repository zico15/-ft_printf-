/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 14:43:34 by edos-san          #+#    #+#             */
/*   Updated: 2022/03/26 18:31:49 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printf_flags(t_data *data)
{
	corrections(data);
	if (data->flags[1].is_user)
	{
		if (data->flags[1].value < data->size && data->type == 's')
			data->flags[1].is_user = 0;
		else
			(data->flags[1]).value += data->txt[0] == '-';
	}
	if (print_minimum_width(data, (data->flags[0])) \
	&& print_minimum_width(data, (data->flags[1])))
		data->count += write(1, data->txt, data->size);
	free_txt();
	return (data->count);
}

static int	read_arg(char **str, char type)
{
	data()->count = 0;
	clean_flgas(data());
	*str = read_flags(data(), *str);
	type = **str;
	data()->type = type;
	if (type == 'c' || type == 's')
		read_str_char();
	else if (type == 'i' || type == 'd' || type == 'u')
		read_base(convert(DEX, 10));
	else if (type == 'p' || type == 'x')
		read_base(convert(HEX_LOW, 16));
	else if (type == 'X')
		read_base(convert(HEX_UP, 16));
	else if (type == '%')
	{
		data()->size = 1;
		(data()->txt) = cread_str("%%", 1);
	}
	(*str)++;
	return (printf_flags(data()));
}

t_data	*data(void)
{
	static t_data	d;

	return (&d);
}

int	ft_printf(const char *str, ...)
{
	int		count;
	char	*txt;

	va_start(data()->args, str);
	count = 0;
	txt = (char *) str;
	while (txt && *txt)
	{
		if (*txt == '%' && *txt++)
			count += read_arg(&txt, *txt);
		else
		{
			count += write(1, txt, 1);
			txt++;
		}
	}
	va_end(data()->args);
	return (count);
}
