# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tgreil <tgreil@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/10 13:32:03 by tgreil            #+#    #+#              #
#    Updated: 2018/04/10 12:26:29 by tgreil           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RM		=	rm -rf

NAME	=	libftprintf.a

CFLAGS	+=	-Wall -Wextra -Werror

CFLAGS	+=	-Iincludes

SRCS	=	utils.c						\
			ft_printf.c					\
			ft_printf_fd.c				\
			ft_llong_itoa.c				\
			ft_printf_file.c			\
			ft_printf_print.c			\
			ft_printf_color.c			\
			ft_printf_utils.c			\
			ft_putnbr_base_fd.c			\
			ft_printf_conversion.c		\
			ft_printf_conv_utils.c		\
			ft_printf_conversion_find.c	\
			conv/ft_printf_a.c			\
			conv/ft_printf_b.c			\
			conv/ft_printf_c.c			\
			conv/ft_printf_d.c			\
			conv/ft_printf_e.c			\
			conv/ft_printf_f.c			\
			conv/ft_printf_g.c			\
			conv/ft_printf_n.c			\
			conv/ft_printf_o.c			\
			conv/ft_printf_p.c			\
			conv/ft_printf_s.c			\
			conv/ft_printf_u.c			\
			conv/ft_printf_x.c			\
			conv/ft_printf_mod.c

OBJS	=	$(addprefix srcs/, $(SRCS:.c=.o))

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
