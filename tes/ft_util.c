/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 00:37:58 by edos-san          #+#    #+#             */
/*   Updated: 2022/03/26 00:56:32 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*cread_str(char *txt, int size)
{
	char	*str;
	int		i;

	str = malloc(sizeof(char) * size + 1);
	i = -1;
	if (!str)
		return (NULL);
	while (++i < size)
		str[i] = txt[i];
	str[i] = 0;
	return (str);
}

void	free_txt(void)
{
	if (data()->txt)
		free(data()->txt);
	data()->txt = 0;
}
