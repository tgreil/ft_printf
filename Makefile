# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tgreil <tgreil@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/10 13:32:03 by tgreil            #+#    #+#              #
#    Updated: 2018/03/04 17:15:04 by tgreil           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RM		=	rm -rf

NAME	=	libftprintf.a

CFLAGS	+=	-Wall -Wextra -Werror

CFLAGS	+=	-I.

SRCS	=	utils.c						\
			ft_printf.c					\
			ft_printf_fd.c				\
			ft_super_itoa.c				\
			ft_printf_file.c			\
			ft_printf_print.c			\
			ft_printf_color.c			\
			ft_printf_conversion.c		\
			ft_printf_conv_utils.c		\
			ft_printf_conversion_find.c	\
			ft_printf_a.c				\
			ft_printf_b.c				\
			ft_printf_c.c				\
			ft_printf_d.c

OBJS	=	$(SRCS:.c=.o)

$(NAME):	 $(OBJS)
		ar rc $(NAME) $(OBJS)
		ranlib $(NAME)

all:		$(NAME)

clean:
		$(RM) $(OBJS)

fclean:	clean
		$(RM) $(NAME)

re:		fclean all

.PHONY: all clean fclean re
