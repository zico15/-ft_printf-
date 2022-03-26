/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 14:00:19 by efreire-          #+#    #+#             */
/*   Updated: 2022/03/26 02:32:52 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

# define DEX "0123456789"
# define HEX_UP "0123456789ABCDEF"
# define HEX_LOW "0123456789abcdef"

typedef struct s_flags
{
	int		is_user;
	int		value;
	char	*t;
	int		direction;
}	t_flags;

typedef struct s_data
{
	va_list	args;
	char	*txt;
	char	type;
	int		size;
	char	*text_out;
	int		count;
	t_flags	flags[5];
}	t_data;

typedef struct s_convert
{
	char				str[30];
	char				*base;
	unsigned long long	n;
	unsigned int		size_base;
	unsigned long		p;
	int					i_d;
	unsigned int		u_x;
	long long			signal;
	int					index;
}	t_convert;

int			ft_printf(const char *input, ...);
t_data		*data(void);

//			convert
int			get_size(const char *txt);
void		read_str_char(void);
int			convert_base(int index, unsigned long long n, t_convert *t);
void		read_base(t_convert	c);
t_convert	convert(char *base, int size_base);

//			flags
char		*read_flags(t_data *data, char *str);
void		clean_flgas(t_data *data);

//			print flgas
int			printf_flags(t_data *data);
int			print_minimum_width(t_data *data, struct s_flags flag);
void		corrections(t_data *data);

//			util
char		*cread_str(char *txt, int size);
void		free_txt(void);

#endif
