/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 19:29:50 by edos-san          #+#    #+#             */
/*   Updated: 2022/03/26 15:06:37 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	str_to_int(char **v, int n)
{
	if (v && *v && **v >= '0' && **v <= '9')
	{
		n = (n * 10) + (**v - '0');
		(*v)++;
		return (str_to_int(v, n));
	}
	return (n);
}

void	clean_flgas(t_data *data)
{
	int	i;

	i = -1;
	while (++i < 5)
	{
		data->flags[i].direction = 0;
		data->flags[i].is_user = 0;
		data->flags[i].t = 0;
		data->flags[i].value = 0;
	}
}

char	*read_flags_2(t_data *data, char *str)
{
	if (*str == '#' && *str++)
	{
		data->flags[2].is_user = 1;
		data->flags[2].value = 2;
		data->flags[2].t = "0x";
		return (read_flags(data, str));
	}
	if (*str == '+' && *str++)
	{
		data->flags[4].is_user = 1;
		data->flags[4].value = 1;
		data->flags[4].t = "+";
		return (read_flags(data, str));
	}
	if (*str == ' ' && *str++)
	{
		data->flags[3].is_user = 1;
		data->flags[3].value = 1;
		data->flags[3].t = " ";
		return (read_flags(data, str));
	}
	return (str);
}

char	*read_flags(t_data *data, char *str)
{
	if (*str == '0' || *str == '-' || (*str >= '1' && *str <= '9'))
	{
		data->flags[0].direction = *str == '-';
		data->flags[0].t = " ";
		str = str + (*str == '-');
		if (*str == '0' && *str++)
			data->flags[0].t = "0";
		data->flags[0].is_user = 1;
		data->flags[0].value = str_to_int(&str, 0);
		return (read_flags(data, str));
	}
	if (*str == '.' && *str++)
	{
		data->flags[1].is_user = 1;
		data->flags[1].value = str_to_int(&str, 0);
		data->flags[1].t = "0";
		return (read_flags(data, str));
	}
	return (read_flags_2(data, str));
}
