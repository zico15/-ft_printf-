# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/25 14:43:41 by edos-san          #+#    #+#              #
#    Updated: 2022/03/26 00:40:36 by edos-san         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS	= ft_printf.c \
		  ft_convert.c \
		  ft_flags.c	\
		  ft_print_flags.c \
		  ft_util.c

OBJS	= $(SRCS:.c=.o)
NAME	= libftprintf.a
LIB		= ar rc
RL		= ranlib
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -f

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME): $(OBJS)
	$(LIB) $(NAME) $(OBJS)
	$(RL) $(NAME)

all: $(NAME)

bonus: all

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

norm :
	norminette -R CheckForbiddenSourceHeader $(SRCS)
	norminette -R CheckDefine $(INS)

.PHONY: all re clean fclean
