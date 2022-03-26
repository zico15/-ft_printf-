/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 23:48:07 by edos-san          #+#    #+#             */
/*   Updated: 2022/03/26 16:09:28 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	corrections(t_data *data)
{
	char	*temp;
	int		i;

	if (data->flags[3].is_user && (data->type == 'i' || data->type == 'd') && \
	data->txt && data->txt[0] != '-')
	{
		temp = data->txt;
		i = -1;
		data->txt = malloc(sizeof(char) * data->size + 2);
		if (data->txt)
		{
			data->txt[0] = data->flags[3].t[0];
			while (temp && temp[++i])
				data->txt[i + 1] = temp[i];
			i++;
			data->txt[i] = 0;
			data->size = i;
		}
		if (temp)
			free(temp);
	}
}

int	print_minimum_width(t_data *data, struct s_flags flag)
{
	if (flag.is_user)
	{
		flag.value -= data->size;
		if (flag.direction)
			data->count += write(1, data->txt, data->size);
		if (flag.value > 0 && data->txt[0] == '-' && \
		flag.t[0] == '0')
		{
			data->count += write(1, "-", 1);
			data->txt[0] = '0';
			flag.value--;
		}
		while (flag.value && --flag.value >= 0)
			data->count += write(1, flag.t, 1);
		if (!flag.direction)
			data->count += write(1, data->txt, data->size);
		if (flag.value > 0)
			data->size += flag.value;
		return (0);
	}
	return (1);
}
